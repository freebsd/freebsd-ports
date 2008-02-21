Index: src/ucompose.hpp
@@ -178,9 +178,9 @@
   inline Composition::Composition(std::string fmt)
     : arg_no(1)
   {
-#if __GNUC__ >= 3
-    os.imbue(std::locale("")); // use the user's locale for the stream
-#endif
+//#if __GNUC__ >= 3
+//   os.imbue(std::locale("")); // use the user's locale for the stream
+//#endif
     std::string::size_type b = 0, i = 0;
   
     // fill in output with the strings between the %1 %2 %3 etc. and
