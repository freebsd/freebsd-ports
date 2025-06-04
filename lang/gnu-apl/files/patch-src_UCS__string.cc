--- src/UCS_string.cc.orig	2019-06-23 12:39:20 UTC
+++ src/UCS_string.cc
@@ -43,32 +43,36 @@ UCS_string::UCS_string()
 }
 //-----------------------------------------------------------------------------
 UCS_string::UCS_string(Unicode uni)
-   : basic_string<Unicode>(1, uni)
 {
+  push_back(uni);
   create(LOC);
 }
 //-----------------------------------------------------------------------------
 UCS_string::UCS_string(const Unicode * data, size_t len)
-   : basic_string<Unicode>(data, len)
 {
+   reserve(2*len);
+   loop(l, len)   push_back(data[l]);
    create(LOC);
 }
 //-----------------------------------------------------------------------------
 UCS_string::UCS_string(size_t len, Unicode uni)
-   : basic_string<Unicode>(len, uni)
 {
+   reserve(2*len);
+   loop(l, len)   push_back(uni);
    create(LOC);
 }
 //-----------------------------------------------------------------------------
 UCS_string::UCS_string(const UCS_string & ucs)
-   : basic_string<Unicode>(ucs)
+   : vector<Unicode>(ucs)
 {
    create(LOC);
 }
 //-----------------------------------------------------------------------------
 UCS_string::UCS_string(const UCS_string & ucs, size_t pos, size_t len)
-   : basic_string<Unicode>(ucs, pos, len)
 {
+   if (len > ucs.size() - pos)   len = ucs.size() - pos;
+   reserve(2*len);
+   loop(l, len)   push_back(ucs[pos + l]);
    create(LOC);
 }
 //-----------------------------------------------------------------------------
@@ -88,7 +92,7 @@ UCS_string::UCS_string(const char * cstring)
    while (*cstring)
       {
         Assert((0x80 & *cstring) == 0);   // ASCII
-        *this += Unicode(*cstring++);
+        push_back(Unicode(*cstring++));
       }
 }
 //-----------------------------------------------------------------------------
@@ -127,7 +131,7 @@ UCS_string::UCS_string(const UTF8_string & utf)
                       << " len " << utf.size() << " at " << LOC <<  endl;
                    if (utf.size() >= 40)
                       {
-                         const UTF8_string end(&utf[utf.size() - 10], 10);
+                         const UTF8_string end(utf8P(&utf[utf.size() - 10]), 10);
                          end.dump_hex(CERR << endl << "(ending with : ", 20)
                                            << ")" << endl;
                       }
@@ -141,7 +145,7 @@ UCS_string::UCS_string(const UTF8_string & utf)
                       << " len " << utf.size() << " at " << LOC <<  endl;
                    if (utf.size() >= 40)
                       {
-                         const UTF8_string end(&utf[utf.size() - 10], 10);
+                         const UTF8_string end(utf8P(&utf[utf.size() - 10]), 10);
                          end.dump_hex(CERR << endl << "(ending with : ", 20)
                                            << ")" << endl;
                       }
@@ -479,7 +483,7 @@ UCS_string::remove_trailing_whitespaces()
 void
 UCS_string::remove_leading_whitespaces()
 {
-int count = 0;
+ShapeItem count = 0;
    loop(s, size())
       {
         if (at(s) <= UNI_ASCII_SPACE)   ++count;
@@ -488,7 +492,7 @@ int count = 0;
 
    if (count == 0)        return;      // no leading whitspaces
    if (count == size())   clear();     // only whitespaces
-   else                   basic_string::erase(0, count);
+   else                   vector<Unicode>::erase(begin(), begin() + count);
 }
 //-----------------------------------------------------------------------------
 void
