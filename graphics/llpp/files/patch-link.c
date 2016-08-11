--- link.c.orig	2015-10-13 20:12:27 UTC
+++ link.c
@@ -34,12 +34,6 @@
 #include <caml/memory.h>
 #include <caml/unixsupport.h>
 
-#if __GNUC__ < 5
-/* At least gcc (Gentoo 4.9.3 p1.0, pie-0.6.2) 4.9.3 emits erroneous
-   clobbered diagnostics */
-#pragma GCC diagnostic ignored "-Wclobbered"
-#endif
-
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wunused-parameter"
 #pragma GCC diagnostic ignored "-Wshadow"
@@ -189,8 +183,8 @@ struct page {
     int agen;
     int pageno;
     int pdimno;
-    fz_text_page *text;
-    fz_text_sheet *sheet;
+    fz_stext_page *text;
+    fz_stext_sheet *sheet;
     fz_page *fzpage;
     fz_display_list *dlist;
     int slinkcount;
@@ -199,7 +193,7 @@ struct page {
     struct annot *annots;
     struct mark {
         int i;
-        fz_text_span *span;
+        fz_stext_span *span;
     } fmark, lmark;
 };
 
@@ -531,10 +525,10 @@ static void freepage (struct page *page)
 {
     if (!page) return;
     if (page->text) {
-        fz_drop_text_page (state.ctx, page->text);
+        fz_drop_stext_page (state.ctx, page->text);
     }
     if (page->sheet) {
-        fz_drop_text_sheet (state.ctx, page->sheet);
+        fz_drop_stext_sheet (state.ctx, page->sheet);
     }
     if (page->slinks) {
         free (page->slinks);
@@ -1307,11 +1301,11 @@ static void process_outline (void)
     }
 }
 
-static char *strofspan (fz_text_span *span)
+static char *strofspan (fz_stext_span *span)
 {
     char *p;
     char utf8[10];
-    fz_text_char *ch;
+    fz_stext_char *ch;
     size_t size = 0, cap = 80;
 
     p = malloc (cap + 1);
@@ -1332,7 +1326,7 @@ static char *strofspan (fz_text_span *sp
     return p;
 }
 
-static int matchspan (regex_t *re, fz_text_span *span,
+static int matchspan (regex_t *re, fz_stext_span *span,
                       int stop, int pageno, double start)
 {
     int ret;
@@ -1372,8 +1366,8 @@ static int matchspan (regex_t *re, fz_te
             b = MAX (0, b-1);
         }
 
-        fz_text_char_bbox (state.ctx, &sb, span, a);
-        fz_text_char_bbox (state.ctx, &eb, span, b);
+        fz_stext_char_bbox (state.ctx, &sb, span, a);
+        fz_stext_char_bbox (state.ctx, &eb, span, b);
 
         p1.x = sb.x0;
         p1.y = sb.y0;
@@ -1411,8 +1405,8 @@ static int matchspan (regex_t *re, fz_te
 
 static int compareblocks (const void *l, const void *r)
 {
-    fz_text_block const *ls = l;
-    fz_text_block const *rs = r;
+    fz_stext_block const *ls = l;
+    fz_stext_block const *rs = r;
     return ls->bbox.y0 - rs->bbox.y0;
 }
 
@@ -1421,8 +1415,8 @@ static void search (regex_t *re, int pag
 {
     int i, j;
     fz_device *tdev;
-    fz_text_page *text;
-    fz_text_sheet *sheet;
+    fz_stext_page *text;
+    fz_stext_sheet *sheet;
     struct pagedim *pdim, *pdimprev;
     int stop = 0, niters = 0;
     double start, end;
@@ -1458,9 +1452,9 @@ static void search (regex_t *re, int pag
         pdim = pdimprev;
     found:
 
-        sheet = fz_new_text_sheet (state.ctx);
-        text = fz_new_text_page (state.ctx);
-        tdev = fz_new_text_device (state.ctx, sheet, text);
+        sheet = fz_new_stext_sheet (state.ctx);
+        text = fz_new_stext_page (state.ctx);
+        tdev = fz_new_stext_device (state.ctx, sheet, text);
 
         page = fz_load_page (state.ctx, state.doc, pageno);
         {
@@ -1474,15 +1468,15 @@ static void search (regex_t *re, int pag
         for (j = 0; j < text->len; ++j) {
             int k;
             fz_page_block *pb;
-            fz_text_block *block;
+            fz_stext_block *block;
 
             pb = &text->blocks[forward ? j : text->len - 1 - j];
             if (pb->type != FZ_PAGE_BLOCK_TEXT) continue;
             block = pb->u.text;
 
             for (k = 0; k < block->len; ++k) {
-                fz_text_line *line;
-                fz_text_span *span;
+                fz_stext_line *line;
+                fz_stext_span *span;
 
                 if (forward) {
                     line = &block->lines[k];
@@ -1511,8 +1505,8 @@ static void search (regex_t *re, int pag
             y = INT_MAX;
         }
     endloop:
-        fz_drop_text_page (state.ctx, text);
-        fz_drop_text_sheet (state.ctx, sheet);
+        fz_drop_stext_page (state.ctx, text);
+        fz_drop_stext_sheet (state.ctx, sheet);
         fz_drop_page (state.ctx, page);
     }
     end = now ();
@@ -2010,9 +2004,9 @@ static void showsel (struct page *page, 
     int seen = 0;
     fz_irect bbox;
     fz_rect rect;
-    fz_text_line *line;
+    fz_stext_line *line;
     fz_page_block *pageb;
-    fz_text_block *block;
+    fz_stext_block *block;
     struct mark first, last;
     unsigned char selcolor[] = {15,15,15,140};
 
@@ -2036,7 +2030,7 @@ static void showsel (struct page *page, 
         for (line = block->lines;
              line < block->lines + block->len;
              ++line) {
-            fz_text_span *span;
+            fz_stext_span *span;
             rect = fz_empty_rect;
 
             for (span = line->first_span; span; span = span->next) {
@@ -2066,7 +2060,7 @@ static void showsel (struct page *page, 
                     for (i = j; i <= k; ++i) {
                         fz_rect bbox1;
                         fz_union_rect (&rect,
-                                       fz_text_char_bbox (state.ctx, &bbox1,
+                                       fz_stext_char_bbox (state.ctx, &bbox1,
                                                           span, i));
                     }
                     fz_round_rect (&bbox, &rect);
@@ -2216,7 +2210,7 @@ static int compareslinks (const void *l,
 static void droptext (struct page *page)
 {
     if (page->text) {
-        fz_drop_text_page (state.ctx, page->text);
+        fz_drop_stext_page (state.ctx, page->text);
         page->fmark.i = -1;
         page->lmark.i = -1;
         page->fmark.span = NULL;
@@ -2224,7 +2218,7 @@ static void droptext (struct page *page)
         page->text = NULL;
     }
     if (page->sheet) {
-        fz_drop_text_sheet (state.ctx, page->sheet);
+        fz_drop_stext_sheet (state.ctx, page->sheet);
         page->sheet = NULL;
     }
 }
@@ -2252,7 +2246,7 @@ static void ensureannots (struct page *p
 
     for (annot = fz_first_annot (state.ctx, page->fzpage);
          annot;
-         annot = fz_next_annot (state.ctx, page->fzpage, annot)) {
+         annot = fz_next_annot (state.ctx, annot)) {
         count++;
     }
 
@@ -2265,10 +2259,10 @@ static void ensureannots (struct page *p
 
         for (annot = fz_first_annot (state.ctx, page->fzpage), i = 0;
              annot;
-             annot = fz_next_annot (state.ctx, page->fzpage, annot), i++) {
+             annot = fz_next_annot (state.ctx, annot), i++) {
             fz_rect rect;
 
-            fz_bound_annot (state.ctx, page->fzpage, annot, &rect);
+            fz_bound_annot (state.ctx, annot, &rect);
             page->annots[i].annot = annot;
             fz_round_rect (&page->annots[i].bbox, &rect);
         }
@@ -2325,10 +2319,7 @@ static void ensureslinks (struct page *p
         }
         for (j = 0; j < page->annotcount; ++j, ++i) {
             fz_rect rect;
-            fz_bound_annot (state.ctx,
-                            page->fzpage,
-                            page->annots[j].annot,
-                            &rect);
+            fz_bound_annot (state.ctx, page->annots[j].annot, &rect);
             fz_transform_rect (&rect, &ctm);
             fz_round_rect (&page->slinks[i].bbox, &rect);
 
@@ -2647,16 +2638,14 @@ static void ensuretext (struct page *pag
         fz_matrix ctm;
         fz_device *tdev;
 
-        page->text = fz_new_text_page (state.ctx);
-        page->sheet = fz_new_text_sheet (state.ctx);
-        tdev = fz_new_text_device (state.ctx, page->sheet, page->text);
+        page->text = fz_new_stext_page (state.ctx);
+        page->sheet = fz_new_stext_sheet (state.ctx);
+        tdev = fz_new_stext_device (state.ctx, page->sheet, page->text);
         ctm = pagectm (page);
-        fz_begin_page (state.ctx, tdev, &fz_infinite_rect, &ctm);
         fz_run_display_list (state.ctx, page->dlist,
                              tdev, &ctm, &fz_infinite_rect, NULL);
         qsort (page->text->blocks, page->text->len,
                sizeof (*page->text->blocks), compareblocks);
-        fz_end_page (state.ctx, tdev);
         fz_drop_device (state.ctx, tdev);
     }
 }
@@ -3049,13 +3038,13 @@ CAMLprim value ml_whatsunder (value ptr_
     else {
         fz_rect *b;
         fz_page_block *pageb;
-        fz_text_block *block;
+        fz_stext_block *block;
 
         ensuretext (page);
         for (pageb = page->text->blocks;
              pageb < page->text->blocks + page->text->len;
              ++pageb) {
-            fz_text_line *line;
+            fz_stext_line *line;
             if (pageb->type != FZ_PAGE_BLOCK_TEXT) continue;
             block = pageb->u.text;
 
@@ -3066,7 +3055,7 @@ CAMLprim value ml_whatsunder (value ptr_
             for (line = block->lines;
                  line < block->lines + block->len;
                  ++line) {
-                fz_text_span *span;
+                fz_stext_span *span;
 
                 b = &line->bbox;
                 if (!(x >= b->x0 && x <= b->x1 && y >= b->y0 && y <= b->y1))
@@ -3081,12 +3070,12 @@ CAMLprim value ml_whatsunder (value ptr_
 
                     for (charnum = 0; charnum < span->len; ++charnum) {
                         fz_rect bbox;
-                        fz_text_char_bbox (state.ctx, &bbox, span, charnum);
+                        fz_stext_char_bbox (state.ctx, &bbox, span, charnum);
                         b = &bbox;
 
                         if (x >= b->x0 && x <= b->x1
                             && y >= b->y0 && y <= b->y1) {
-                            fz_text_style *style = span->text->style;
+                            fz_stext_style *style = span->text->style;
                             const char *n2 =
                                 style->font
                                 ? style->font->name
@@ -3164,9 +3153,9 @@ CAMLprim value ml_markunder (value ptr_v
     CAMLlocal1 (ret_v);
     fz_rect *b;
     struct page *page;
-    fz_text_line *line;
+    fz_stext_line *line;
     fz_page_block *pageb;
-    fz_text_block *block;
+    fz_stext_block *block;
     struct pagedim *pdim;
     int mark = Int_val (mark_v);
     char *s = String_val (ptr_v);
@@ -3242,7 +3231,7 @@ CAMLprim value ml_markunder (value ptr_v
         for (line = block->lines;
              line < block->lines + block->len;
              ++line) {
-            fz_text_span *span;
+            fz_stext_span *span;
 
             b = &line->bbox;
             if (!(x >= b->x0 && x <= b->x1 && y >= b->y0 && y <= b->y1))
@@ -3267,7 +3256,7 @@ CAMLprim value ml_markunder (value ptr_v
 
                 for (charnum = 0; charnum < span->len; ++charnum) {
                     fz_rect bbox;
-                    fz_text_char_bbox (state.ctx, &bbox, span, charnum);
+                    fz_stext_char_bbox (state.ctx, &bbox, span, charnum);
                     b = &bbox;
 
                     if (x >= b->x0 && x <= b->x1 && y >= b->y0 && y <= b->y1) {
@@ -3383,10 +3372,10 @@ CAMLprim value ml_seltext (value ptr_v, 
     struct pagedim *pdim;
     char *s = String_val (ptr_v);
     int i, x0, x1, y0, y1, fi, li;
-    fz_text_line *line;
+    fz_stext_line *line;
     fz_page_block *pageb;
-    fz_text_block *block;
-    fz_text_span *span, *fspan, *lspan;
+    fz_stext_block *block;
+    fz_stext_span *span, *fspan, *lspan;
 
     if (trylock ("ml_seltext")) {
         goto done;
@@ -3426,7 +3415,7 @@ CAMLprim value ml_seltext (value ptr_v, 
 
             for (span = line->first_span; span; span = span->next) {
                 for (i = 0; i < span->len; ++i) {
-                    fz_text_char_bbox (state.ctx, &b, span, i);
+                    fz_stext_char_bbox (state.ctx, &b, span, i);
 
                     if (x0 >= b.x0 && x0 <= b.x1
                         && y0 >= b.y0 && y0 <= b.y1) {
@@ -3465,7 +3454,7 @@ CAMLprim value ml_seltext (value ptr_v, 
     CAMLreturn (Val_unit);
 }
 
-static int UNUSED_ATTR pipespan (FILE *f, fz_text_span *span, int a, int b)
+static int UNUSED_ATTR pipespan (FILE *f, fz_stext_span *span, int a, int b)
 {
     char buf[4];
     int i, len, ret;
@@ -3589,9 +3578,9 @@ CAMLprim value ml_copysel (value fd_v, v
     FILE *f;
     int seen = 0;
     struct page *page;
-    fz_text_line *line;
+    fz_stext_line *line;
     fz_page_block *pageb;
-    fz_text_block *block;
+    fz_stext_block *block;
     int fd = Int_val (fd_v);
     char *s = String_val (ptr_v);
 
@@ -3621,7 +3610,7 @@ CAMLprim value ml_copysel (value fd_v, v
         for (line = block->lines;
              line < block->lines + block->len;
              ++line) {
-            fz_text_span *span;
+            fz_stext_span *span;
 
             for (span = line->first_span; span; span = span->next) {
                 int a, b;
@@ -3913,8 +3902,7 @@ CAMLprim value ml_platform (value unit_v
     platid = pilinux;
 #elif defined __CYGWIN__
     platid = picygwin;
-#elif defined __DragonFly__ || defined __FreeBSD__
-    || defined __OpenBSD__ || defined __NetBSD__
+#elif defined __DragonFly__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __NetBSD__
     platid = pibsd;
 #elif defined __sun__
     platid = pisun;
@@ -4185,7 +4173,7 @@ CAMLprim value ml_savedoc (value path_v)
     pdf_document *pdf = pdf_specifics (state.ctx, state.doc);
 
     if (pdf) {
-        pdf_write_document (state.ctx, pdf, String_val (path_v), NULL);
+        pdf_save_document (state.ctx, pdf, String_val (path_v), NULL);
     }
     CAMLreturn (Val_unit);
 }
@@ -4400,10 +4388,10 @@ CAMLprim value ml_init (value csock_v, v
 #endif
     }
     else {
-        unsigned int len;
-        void *base = pdf_lookup_substitute_font (state.ctx, 0, 0, 0, 0, &len);
+        int len;
+        const char *data = pdf_lookup_substitute_font (state.ctx, 0, 0, 0, 0, &len);
 
-        state.face = load_builtin_font (base, len);
+        state.face = load_builtin_font (data, len);
     }
     if (!state.face) _exit (1);
 
