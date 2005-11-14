Index: libcpp/include/cpplib.h
===================================================================
--- libcpp/include/cpplib.h	(revision 106842)
+++ libcpp/include/cpplib.h	(working copy)
@@ -474,7 +474,7 @@
   /* Called to emit a diagnostic if client_diagnostic option is true.
      This callback receives the translated message.  */
   void (*error) (cpp_reader *, int, const char *, va_list *)
-       ATTRIBUTE_PRINTF(3,0);
+       ATTRIBUTE_FPTR_PRINTF(3,0);
 };
 
 /* Chain of directories to look for include files in.  */
