sip 4.16.5 has switched the Makefile lines that invoke the moc utility from
an invocation with an explicit source file name to "$<".

This works with GNU make, but not make(1), where it $< evaluates to nothing
in this context.

Switch back to the previous version to avoid having to depend on devel/gmake
(figuring out which ports need it is not trivial).
--- siputils.py
+++ siputils.py
@@ -1683,7 +1683,7 @@
             cpp = "moc_" + root + ".cpp"
 
             mfile.write("\n%s: %s\n" % (cpp, mf))
-            mfile.write("\t$(MOC) -o %s $<\n" % cpp)
+            mfile.write("\t$(MOC) -o %s %s\n" % (cpp, mf))
 
         mfile.write("\n$(TARGET): $(OFILES)\n")
 
@@ -1980,7 +1980,7 @@
                 mf = os.path.join(self._src_dir, mf)
 
             mfile.write("\n%s: %s\n" % (cpp, mf))
-            mfile.write("\t$(MOC) -o %s $<\n" % cpp)
+            mfile.write("\t$(MOC) -o %s %s\n" % (cpp, mf))
 
         mfile.write("\n$(TARGET): $(OFILES)\n")
 
