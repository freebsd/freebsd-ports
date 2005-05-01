--- lib/coding.c.orig	Fri Jan 24 15:08:40 1997
+++ lib/coding.c	Sun May  1 01:53:52 2005
@@ -120,7 +120,7 @@
 
 struct fontRegs fDRegs[] = {
     /* DF_GB2312 */
-    {  GB2312, 0,  "GB2312.1980-0", NULL, 0, 0, 'A', 0, 0},
+    {  FldGB2312, 0,  "GB2312.1980-0", NULL, 0, 0, 'A', 0, 0},
     /* DF_JISX0208 */
     {JISX0208, 0,"JISX0208.1983-0", NULL, 0, 0, 'B', 0, 0},
     /* DF_KSC5601 */
@@ -128,19 +128,19 @@
     /* DF_JISX0212 */
     {JISX0208, 0,       "JISX0212", NULL, 0, 0, 'D', 0, 0},
     /* DF_BIG5_0 */
-    {    BIG5, 0,     "BIG5.HKU-0", NULL, 0, 0, '0', 0, 0},
+    {    BIG5, 0,         "BIG5-0", NULL, 0, 0, '0', 0, 0},
     /* DF_BIG5_1 */
-    {    BIG5, 0,     "BIG5.HKU-0", NULL, 0, 0, '1', 0, 0},
+    {    BIG5, 0,         "BIG5-0", NULL, 0, 0, '1', 0, 0},
     {    NULL, 0,             NULL, NULL, 0, 0,   0, 0, 0}
 };
 
 struct fontLoaderRegs fldDRegs[] = {
-    {  FldGB2312,      0},
+    {     GB2312,      0},
     {FldJISX0208, 0x7424},
     { FldKSC5601, 0x7D7E},
     {FldJISX0208, 0x7424},
-    {       BIG5,      0},
-    {       BIG5,      0},
+    {       BIG5, 0xfefe},
+    {       BIG5, 0xfefe},
     {       NULL,      0}
 };
 
