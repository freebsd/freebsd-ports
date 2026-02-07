--- miniline.c.orig	2011-06-28 02:04:58.000000000 +0000
+++ miniline.c
@@ -15,7 +15,7 @@
  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  *
- * @(#)$Header: /mm2/home/cvs/bc-src/tgif/miniline.c,v 1.38 2011/05/18 22:41:20 william Exp $
+ * @(#)$Header: /mm2/home/cvs/bc-src/tgif/miniline.c,v 1.40 2011/09/07 04:28:51 cvsps Exp $
  */
 
 #define _INCLUDE_FROM_MINILINE_C_
@@ -5661,10 +5661,15 @@ void DumpGRestore(FP, do_dump, indent)
 }
 
 static
-void DumpSetFont(FP, font, font_name, double_byte, style, sz_unit)
+void DumpSetFont(FP, font, font_name, double_byte, style, sz_unit,
+      pn_cancel_double_byte_mod_bytes)
    FILE *FP;
-   int font, double_byte, style, sz_unit;
+   int font, double_byte, style, sz_unit, *pn_cancel_double_byte_mod_bytes;
    char *font_name;
+   /*
+    * The only known condition for setting *cancel_double_byte_mod_bytes to
+    *       TRUE is when Japanese EUC fonts are used.
+    */
 {
    char buf[MAXSTRING], font_str[MAXSTRING], real_font_str[MAXSTRING];
    char *ps_findfont_cmd=gPsCmd[PS_FINDFONT];
@@ -5684,6 +5689,10 @@ void DumpSetFont(FP, font, font_name, do
       strcpy(real_font_str, font_str);
       MapAliasedPSFontName(real_font_str, sizeof(real_font_str));
 
+      if (pn_cancel_double_byte_mod_bytes != NULL &&
+            strstr(real_font_str, "-EUC-") != NULL) {
+         *pn_cancel_double_byte_mod_bytes = TRUE;
+      }
 #ifdef _PS_USE_EUC_FONT
       /* do not translate -- program constants */
       euc_font = (strstr(font_str, "-EUC-") != NULL);
@@ -5755,6 +5764,7 @@ void DumpStrSeg(pStrSeg, just, x, baseli
    int font=pStrSeg->font, style=pStrSeg->style, sz_unit=pStrSeg->sz_unit;
    int double_byte=pStrSeg->double_byte, color_index=pStrSeg->color;
    int double_byte_mod_bytes=pStrSeg->double_byte_mod_bytes;
+   int cancel_double_byte_mod_bytes=FALSE;
    int asc=(pStrSeg->read_only ? pStrSeg->orig_asc : pStrSeg->asc);
    char *font_name=pStrSeg->font_name;
 
@@ -5779,10 +5789,13 @@ void DumpStrSeg(pStrSeg, just, x, baseli
       }
    }
    DumpIndentString(FP, indent);
-   DumpSetFont(FP, font, font_name, double_byte, style, sz_unit);
+   DumpSetFont(FP, font, font_name, double_byte, style, sz_unit,
+         &cancel_double_byte_mod_bytes);
    DumpIndentString(FP, indent);
    fprintf(FP, "(");
-   DumpOneStr(FP, font, double_byte, double_byte_mod_bytes, pStrSeg->dyn_str.s);
+   DumpOneStr(FP, font, double_byte,
+         double_byte_mod_bytes && !cancel_double_byte_mod_bytes,
+         pStrSeg->dyn_str.s);
    if (do_dump) {
       int underline_on=pStrSeg->underline_on;
       int overline_on=pStrSeg->overline_on;
