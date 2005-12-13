--- src/xlslib/label.cpp.orig	Mon Dec 12 16:45:55 2005
+++ src/xlslib/label.cpp	Mon Dec 12 16:48:27 2005
@@ -95,7 +95,7 @@
 label_t class implementation
 ******************************
 */
-label_t::label_t(unsigned16_t rowval, unsigned16_t colval, 
+xlslib_core::label_t::label_t(unsigned16_t rowval, unsigned16_t colval, 
 		 string& labelstrval, xf_t* pxfval)
 {
    row = rowval;
@@ -121,7 +121,7 @@
 ******************************
 */
 
-unsigned16_t label_t::GetSize() 
+unsigned16_t xlslib_core::label_t::GetSize() 
 {
    unsigned16_t size = 0;
 
@@ -136,7 +136,7 @@
 ******************************
 */
 
-CUnit* label_t::GetData() 
+CUnit* xlslib_core::label_t::GetData() 
 {
    CUnit* datalabel = 
       (CUnit*)( new CLabel(row,col,strlabel,pxf));
