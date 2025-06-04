--- src/Quad_CR.cc.orig	2019-06-23 12:39:20 UTC
+++ src/Quad_CR.cc
@@ -1041,17 +1041,15 @@ Value_P Z(utf, LOC);
 Value_P
 Quad_CR::do_CR19(const Value & B)
 {
-UTF8_string utf(B);
-   for (size_t l = 0; l < utf.size();)
-       {
-         int len = 0;
-         const Unicode uni = UTF8_string::toUni(&utf[l], len, false);
-         if (uni == Invalid_Unicode)   DOMAIN_ERROR;
+   if (B.get_rank() > 1)   RANK_ERROR;
+const ShapeItem len_B = B.element_count();
 
-         l += len;
-       }
+UTF8 bytes_utf[len_B + 10];
+   loop(b, len_B)   bytes_utf[b] = B.get_ravel(b).get_byte_value();
+   bytes_utf[len_B] = 0;
 
-UCS_string ucs(utf);
+const UTF8_string utf(bytes_utf, len_B);
+const UCS_string ucs(utf);
 Value_P Z(ucs, LOC);
    return Z;
 }
