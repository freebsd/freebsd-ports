--- virtualenv.py	2007-10-10 16:27:32.000000000 +0200
+++ virtualenv.py.port	2008-01-06 13:42:54.000000000 +0100
@@ -464,6 +464,9 @@
     if sys.executable != py_executable:
         ## FIXME: could I just hard link?
         shutil.copyfile(sys.executable, py_executable)
+	if not py_executable.endswith('/python'):
+	    py_link = os.path.join(os.path.dirname(py_executable), 'python')
+	    os.symlink(os.path.basename(py_executable), py_link)
         make_exe(py_executable)
     
     if 'Python.framework' in sys.prefix:
