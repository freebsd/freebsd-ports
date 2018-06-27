--- src/common/sex.cpp.orig	2018-06-25 13:54:25 UTC
+++ src/common/sex.cpp
@@ -242,7 +242,7 @@ static Table   list[] = {
         {his,            SZ(his)},        {dongadj,        SZ(dongadj)},
         {dong,           SZ(dong)},       {intoher,        SZ(intoher)},
         {twatadj,        SZ(twatadj)},    {twat,           SZ(twat)},
-        {(const char **)NULL,  (short)NULL},
+        {(const char **)NULL,  0},
 };
 
 std::string sex(short wraplen) {
