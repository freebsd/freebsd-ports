--- engine/SCons/Script/__init__.py.orig	Wed Feb 16 03:12:11 2005
+++ engine/SCons/Script/__init__.py	Thu Mar 17 14:07:01 2005
@@ -77,6 +77,41 @@
 
 main                    = Main.main
 
+# The following are global class definitions and variables that used to
+# live directly in this module back before 0.96.90, when it contained
+# a lot of code.  Some SConscript files in widely-distributed packages
+# (Blender is the specific example) actually reached into SCons.Script
+# directly to use some of these.  Rather than break those SConscript
+# files, we're going to propagate these names into the SCons.Script
+# namespace here.
+#
+# Some of these are commented out because it's *really* unlikely anyone
+# used them, but we're going to leave the comment here to try to make
+# it obvious what to do if the situation arises.
+BuildTask               = Main.BuildTask
+CleanTask               = Main.CleanTask
+QuestionTask            = Main.QuestionTask
+#PrintHelp               = Main.PrintHelp
+OptParser               = Main.OptParser
+SConscriptSettableOptions = Main.SConscriptSettableOptions
+
+keep_going_on_error     = Main.keep_going_on_error
+print_dtree             = Main.print_dtree
+print_explanations      = Main.print_explanations
+print_includes          = Main.print_includes
+print_objects           = Main.print_objects
+print_time              = Main.print_time
+print_tree              = Main.print_tree
+memory_stats            = Main.memory_stats
+ignore_errors           = Main.ignore_errors
+#sconscript_time         = Main.sconscript_time
+#command_time            = Main.command_time
+#exit_status             = Main.exit_status
+#profiling               = Main.profiling
+repositories            = Main.repositories
+#num_jobs                = Main.num_jobs     # settable by SConscript.SetJobs()
+
+#
 import SConscript
 _SConscript = SConscript
 
@@ -206,7 +241,7 @@
     'GetOption',
     'Help',
     'Import',
-    'SConscript',
+    #'SConscript', is handled separately, below.
     'SConscriptChdir',
     'SetOption',
 
@@ -221,6 +256,7 @@
     #The Command() method is handled separately, below.
     'Depends',
     'Dir',
+    'Entry',
     'Execute',
     'File',
     'FindFile',
@@ -272,6 +308,22 @@
 
 for name in GlobalDefaultEnvironmentFunctions + GlobalDefaultBuilders:
     exec "%s = _SConscript.DefaultEnvironmentCall(%s)" % (name, repr(name))
+
+# There are a handful of variables that used to live in the
+# Script/SConscript.py module that some SConscript files out there were
+# accessing directly as SCons.Script.SConscript.*.  The problem is that
+# "SConscript" in this namespace is no longer a module, it's a global
+# function call--or more precisely, an object that implements a global
+# function call through the default Environment.  Nevertheless, we can
+# aintain backwards compatibility for SConscripts that were reaching in
+# this way by hanging some attributes off the "SConscript" object here.
+SConscript = _SConscript.DefaultEnvironmentCall('SConscript')
+
+SConscript.Arguments = ARGUMENTS
+SConscript.ArgList = ARGLIST
+SConscript.BuildTargets = BUILD_TARGETS
+SConscript.CommandLineTargets = COMMAND_LINE_TARGETS
+SConscript.DefaultTargets = DEFAULT_TARGETS
 
 # The global Command() function must be handled differently than the
 # global functions for other construction environment methods because
