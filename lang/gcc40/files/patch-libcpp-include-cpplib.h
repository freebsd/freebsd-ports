Index: libcpp/include/cpplib.h
===================================================================
--- libcpp/include/cpplib.h	(revision 106886)
+++ libcpp/include/cpplib.h	(working copy)
@@ -453,8 +453,7 @@
 
   /* Called to emit a diagnostic if client_diagnostic option is true.
      This callback receives the translated message.  */
-  void (*error) (cpp_reader *, int, const char *, va_list *)
-       ATTRIBUTE_PRINTF(3,0);
+  void (*error) (cpp_reader *, int, const char *, va_list *);
 };
 
 /* Chain of directories to look for include files in.  */
