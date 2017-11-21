fix seg fault
https://bugzilla.gnome.org/show_bug.cgi?id=776791
https://github.com/doxygen/doxygen/commit/0f02761a158a5e9ddbd5801682482af8986dbc35#diff-dea13e25f9bbae3ddde44cc615b9c9ba

--- src/xmlgen.cpp.orig	2016-11-29 08:14:16 UTC
+++ src/xmlgen.cpp
@@ -620,7 +620,7 @@ static void generateXMLForMember(MemberD
     if (md->isInline()) t << "yes"; else t << "no";
     t << "\"";
 
-    if (al->refQualifier!=RefQualifierNone)
+    if (al!=0 && al->refQualifier!=RefQualifierNone)
     {
       t << " refqual=\"";
       if (al->refQualifier==RefQualifierLValue) t << "lvalue"; else t << "rvalue";
