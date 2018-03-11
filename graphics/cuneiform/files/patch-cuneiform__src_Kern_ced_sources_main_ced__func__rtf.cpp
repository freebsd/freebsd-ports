Fix with modern Clang, e.g.

cuneiform_src/Kern/ced/sources/main/ced_func_rtf.cpp:215:12: error: ordered comparison between pointer and zero ('CEDSection *' and 'int')
        for (;sect>0;sect=sect->next)

--- cuneiform_src/Kern/ced/sources/main/ced_func_rtf.cpp.orig	2018-03-11 17:08:11 UTC
+++ cuneiform_src/Kern/ced/sources/main/ced_func_rtf.cpp
@@ -212,7 +212,7 @@ Bool32	CEDPage::FormattedWriteRtf(const 
     }
 */
     // write the text lines
-	for (;sect>0;sect=sect->next)
+	for (;sect;sect=sect->next)
 	{
 		if (!WriteRtfSection(rtf,sect)) goto WRITE_END; //write section properties
 		//	int sectNum=0;
@@ -897,7 +897,7 @@ Bool WriteRtfCharFmt(struct StrRtfOut fa
 //    if (curChar->fontNum>=rtf->page->fontsUsed || (prevChar&&prevChar->fontNum>=rtf->page->fontsUsed)) return TRUE;
 
     // extract value for comparison
-    if (prevChar>0) {
+    if (prevChar) {
 //       lstrcpy(PrevTypeFace,TerFont[PrevFont].TypeFace);
        PrevFamily=rtf->table[rtf->page->GetFontByNum(prevChar->fontNum)];
        PrevStyle=prevChar->fontAttribs;
