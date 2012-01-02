--- test/lib/test_suite.py.orig	2011-05-14 12:16:32.000000000 +0000
+++ test/lib/test_suite.py	2011-12-13 00:23:04.673107891 +0000
@@ -10,13 +10,21 @@
 import filecmp
 import shlex
 import time
-from server import Server
+from tarantool_silverbox_server import TarantoolSilverboxServer
+from tarantool_connection import AdminConnection, DataConnection
 import tarantool_preprocessor
 import re
 import cStringIO
 import string
 import traceback
 
+class TestRunException(RuntimeError):
+  """A common exception to use across the program."""
+  def __init__(self, message):
+    self.message = message
+  def __str__(self):
+    return self.message
+
 class FilteredStream:
   """Helper class to filter .result file output"""
   def __init__(self, filename):
@@ -66,12 +74,12 @@
     """Initialize test properties: path to test file, path to
     temporary result file, path to the client program, test status."""
     self.name = name
-    self.args = args
-    self.suite_ini = suite_ini
     self.result = name.replace(".test", ".result")
-    self.tmp_result = os.path.join(self.args.vardir,
+    self.tmp_result = os.path.join(suite_ini["vardir"],
                                    os.path.basename(self.result))
     self.reject = name.replace(".test", ".reject")
+    self.args = args
+    self.suite_ini = suite_ini
     self.is_executed = False
     self.is_executed_ok = None
     self.is_equal_result = None
@@ -81,7 +89,7 @@
     """Return true if this test was run successfully."""
     return self.is_executed and self.is_executed_ok and self.is_equal_result
 
-  def run(self, server):
+  def run(self):
     """Execute the test assuming it's a python program.
     If the test aborts, print its output to stdout, and raise
     an exception. Else, comprare result and reject files.
@@ -91,10 +99,18 @@
 
     diagnostics = "unknown"
     save_stdout = sys.stdout
+    admin = AdminConnection(self.suite_ini["host"],
+                            self.suite_ini["admin_port"])
+    sql = DataConnection(self.suite_ini["host"],
+                         self.suite_ini["port"])
+    server = self.suite_ini["server"]
     try:
+      admin.connect()
+      sql.connect()
       sys.stdout = FilteredStream(self.tmp_result)
-      stdout_fileno = sys.stdout.stream.fileno()
-      execfile(self.name, dict(locals(), **server.__dict__))
+      server = self.suite_ini["server"]
+      vardir = self.suite_ini["vardir"]
+      execfile(self.name, globals(), locals())
       self.is_executed_ok = True
     except Exception as e:
       traceback.print_exc(e)
@@ -103,6 +119,8 @@
       if sys.stdout and sys.stdout != save_stdout:
         sys.stdout.close()
       sys.stdout = save_stdout;
+      admin.disconnect()
+      sql.disconnect()
 
     self.is_executed = True
 
@@ -111,7 +129,7 @@
 
     if self.args.valgrind:
       self.is_valgrind_clean = \
-      check_valgrind_log(server.valgrind_log) == False
+      check_valgrind_log(self.suite_ini["valgrind_log"]) == False
 
     if self.is_executed_ok and self.is_equal_result and self.is_valgrind_clean:
       print "[ pass ]"
@@ -133,12 +151,12 @@
         where = ": wrong test output"
       elif not self.is_valgrind_clean:
         os.remove(self.reject)
-        self.print_diagnostics(server.valgrind_log,
+        self.print_diagnostics(self.suite_ini["valgrind_log"],
                                "Test failed! Last 10 lines of valgrind.log:")
         where = ": there were warnings in valgrind.log"
 
-      if not self.args.is_force:
-        raise RuntimeError("Failed to run test " + self.name + where)
+      if not self.suite_ini["is_force"]:
+        raise TestRunException("Failed to run test " + self.name + where)
 
 
   def print_diagnostics(self, logfile, message):
@@ -167,6 +185,20 @@
         for line in diff:
           sys.stdout.write(line)
 
+class TarantoolConfigFile:
+  """ConfigParser can't read files without sections, work it around"""
+  def __init__(self, fp, section_name):
+    self.fp = fp
+    self.section_name = "[" + section_name + "]"
+  def readline(self):
+    if self.section_name:
+      section_name = self.section_name
+      self.section_name = None
+      return section_name
+    # tarantool.cfg puts string values in quote
+    return self.fp.readline().replace("\"", '')
+
+
 class TestSuite:
   """Each test suite contains a number of related tests files,
   located in the same directory on disk. Each test file has
@@ -186,13 +218,15 @@
     self.args = args
     self.tests = []
     self.ini = {}
-
-    self.ini["core"] = "tarantool"
-    self.ini["module"] = "silverbox"
+    self.ini["suite_path"] = suite_path
+    self.ini["host"] = "localhost"
+    self.ini["is_force"] = self.args.is_force
+    self.ini["vardir"] = args.vardir
+    self.ini["valgrind_log"] = os.path.join(args.vardir, "valgrind.log")
 
     if os.access(suite_path, os.F_OK) == False:
-      raise RuntimeError("Suite \"" + suite_path +\
-                         "\" doesn't exist")
+      raise TestRunException("Suite \"" + suite_path +\
+                             "\" doesn't exist")
 
 # read the suite config
     config = ConfigParser.ConfigParser()
@@ -203,6 +237,16 @@
       self.ini["disabled"] = dict.fromkeys(self.ini["disabled"].split(" "))
     else:
       self.ini["disabled"] = dict()
+# import the necessary module for test suite client
+
+# now read the server config, we need some properties from it
+
+    with open(self.ini["config"]) as fp:
+      dummy_section_name = "tarantool_silverbox"
+      config.readfp(TarantoolConfigFile(fp, dummy_section_name))
+      self.ini["pidfile"] = config.get(dummy_section_name, "pid_file")
+      self.ini["admin_port"] = int(config.get(dummy_section_name, "admin_port"))
+      self.ini["port"] = int(config.get(dummy_section_name, "primary_port"))
 
     print "Collecting tests in \"" + suite_path + "\": " +\
       self.ini["description"] + "."
@@ -216,17 +260,9 @@
   def run_all(self):
     """For each file in the test suite, run client program
     assuming each file represents an individual test."""
-    try:
-      server = Server(self.ini["core"], self.ini["module"])
-    except Exception as e:
-      print e
-      raise RuntimeError("Unknown server: core = {0}, module = {1}".format(
-        self.ini["core"], self.ini["module"]))
-    server.deploy(self.ini["config"],
-                  server.find_exe(self.args.builddir, silent=False),
-		  self.args.vardir,
-                  self.args.mem, self.args.start_and_exit, self.args.gdb, self.args.valgrind,
-		  silent=False)
+    server = TarantoolSilverboxServer(self.args, self.ini)
+    server.install()
+    server.start()
     if self.args.start_and_exit:
       print "  Start and exit requested, exiting..."
       exit(0)
@@ -247,7 +283,7 @@
       if os.path.basename(test.name) in self.ini["disabled"]:
         print "[ skip ]"
       else:
-        test.run(server)
+        test.run()
         if not test.passed():
           failed_tests.append(test.name)
 
@@ -255,11 +291,9 @@
     if len(failed_tests):
       print "Failed {0} tests: {1}.".format(len(failed_tests),
                                             ", ".join(failed_tests))
-    server.stop(silent=False)
-    server.cleanup()
+    server.stop();
 
-    if self.args.valgrind and check_valgrind_log(server.valgrind_log):
+    if self.args.valgrind and check_valgrind_log(self.ini["valgrind_log"]):
       print "  Error! There were warnings/errors in valgrind log file:"
-      print_tail_n(server.valgrind_log, 20)
-      return 1
-    return len(failed_tests)
+      print_tail_n(self.ini["valgrind_log"], 20)
+
