Fix build with MuPDF 1.12.0

Based on upstream commit 50a80d2fe92b52c0b50915bc194edf556b10aa49

--- link.c.orig	2016-11-29 15:11:31 UTC
+++ link.c
@@ -8,12 +8,18 @@
 #include <string.h>
 #include <stdlib.h>
 #include <signal.h>
+
+#include <math.h>
 #include <wchar.h>
+#include <locale.h>
+#include <langinfo.h>
 
 #include <unistd.h>
 #include <pthread.h>
 #include <sys/uio.h>
 #include <sys/time.h>
+#include <sys/stat.h>
+#include <fcntl.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/utsname.h>
@@ -29,7 +35,15 @@
 #include <limits.h>
 #include <inttypes.h>
 
+#ifdef __COCOA__
+#include <CoreFoundation/CoreFoundation.h>
+#endif
+
+#ifdef __APPLE__
+#include <OpenGL/gl.h>
+#else
 #include <GL/gl.h>
+#endif
 
 #include <caml/fail.h>
 #include <caml/alloc.h>
@@ -48,10 +62,6 @@
 #include <ft2build.h>
 #include FT_FREETYPE_H
 
-#ifdef USE_FONTCONFIG
-#include <fontconfig/fontconfig.h>
-#endif
-
 #define PIGGYBACK
 #define CACHE_PAGEREFS
 
@@ -191,16 +201,15 @@ struct page {
     int pageno;
     int pdimno;
     fz_stext_page *text;
-    fz_stext_sheet *sheet;
     fz_page *fzpage;
     fz_display_list *dlist;
+    fz_link *links;
     int slinkcount;
     struct slink *slinks;
     int annotcount;
     struct annot *annots;
     struct mark {
-        int i;
-        fz_stext_span *span;
+        fz_stext_char *ch;
     } fmark, lmark;
 };
 
@@ -270,6 +279,7 @@ struct {
         pdf_document *pdf;
     } pdflut;
 #endif
+    int utf8cs;
 } state;
 
 struct bo {
@@ -396,6 +406,7 @@ static int readlen (int fd)
 {
     /* Type punned unions here. Why? Less code (Adjusted by more comments).
        https://en.wikipedia.org/wiki/Type_punning */
+    /* Then again https://bugs.llvm.org/show_bug.cgi?id=31928 - hmm */
     union { uint32_t len; char raw[4]; } buf;
     readdata (fd, buf.raw, 4);
     return buf.len;
@@ -511,8 +522,8 @@ static void pdfinfo (void)
         { "info:Producer", "Producer" },
         { "info:CreationDate", "Creation date" },
     };
-    int len = 256;
-    char *buf = malloc (len);
+    int len = 0;
+    char *buf = NULL;
 
     for (size_t i = 0; i < sizeof (metatbl) / sizeof (metatbl[1]); ++i) {
         int need;
@@ -524,9 +535,9 @@ static void pdfinfo (void)
                 printd ("info %s\t%s", metatbl[i].name, buf);
             }
             else {
-                buf = realloc (buf, need);
-                if (!buf) err (1, "realloc %d", need);
-                len = need;
+                buf = realloc (buf, need + 1);
+                if (!buf) err (1, "pdfinfo realloc %d", need + 1);
+                len = need + 1;
                 goto again;
             }
         }
@@ -555,9 +566,6 @@ static void freepage (struct page *page)
     if (page->text) {
         fz_drop_stext_page (state.ctx, page->text);
     }
-    if (page->sheet) {
-        fz_drop_stext_sheet (state.ctx, page->sheet);
-    }
     if (page->slinks) {
         free (page->slinks);
     }
@@ -772,12 +780,13 @@ static struct tile *rendertile (struct page *page, int
         if (pbo) {
             tile->pixmap =
                 fz_new_pixmap_with_bbox_and_data (state.ctx, state.colorspace,
-                                                  &bbox, 1, pbo->ptr);
+                                                  &bbox, NULL, 1, pbo->ptr);
             tile->pbo = pbo;
         }
         else {
             tile->pixmap =
-                fz_new_pixmap_with_bbox (state.ctx, state.colorspace, &bbox, 1);
+                fz_new_pixmap_with_bbox (state.ctx, state.colorspace, &bbox,
+                                         NULL, 1);
         }
     }
 
@@ -817,7 +826,7 @@ pdf_collect_pages(pdf_document *doc, pdf_obj *node)
         fz_throw (ctx, FZ_ERROR_GENERIC, "cycle in page tree");
     for (int i = 0; i < len; i++) {
         pdf_obj *kid = pdf_array_get (ctx, kids, i);
-        char *type = pdf_to_name (ctx, pdf_dict_gets (ctx, kid, "Type"));
+        const char *type = pdf_to_name (ctx, pdf_dict_gets (ctx, kid, "Type"));
         if (*type
             ? !strcmp (type, "Pages")
             : pdf_dict_gets (ctx, kid, "Kids")
@@ -930,7 +939,6 @@ static void initpdims (int wthack)
                         fz_matrix ctm, page_ctm;
 
                         dev = fz_new_bbox_device (ctx, &rect);
-                        dev->hints |= FZ_IGNORE_SHADE;
                         pdf_page_transform (ctx, page, &mediabox, &page_ctm);
                         fz_invert_matrix (&ctm, &page_ctm);
                         pdf_run_page (ctx, page, dev, &fz_identity, NULL);
@@ -1034,7 +1042,6 @@ static void initpdims (int wthack)
                         fz_device *dev;
 
                         dev = fz_new_bbox_device (ctx, &rect);
-                        dev->hints |= FZ_IGNORE_SHADE;
                         fz_run_page (ctx, page, dev, &fz_identity, NULL);
                         fz_close_device (ctx, dev);
                         fz_drop_device (ctx, dev);
@@ -1291,7 +1298,7 @@ static void process_outline (void)
     }
 }
 
-static char *strofspan (fz_stext_span *span)
+static char *strofline (fz_stext_line *line)
 {
     char *p;
     char utf8[10];
@@ -1301,7 +1308,7 @@ static char *strofspan (fz_stext_span *span)
     p = malloc (cap + 1);
     if (!p) return NULL;
 
-    for (ch = span->text; ch < span->text + span->len; ++ch) {
+    for (ch = line->first_char; ch; ch = ch->next) {
         int n = fz_runetochar (utf8, ch->c);
         if (size + n > cap) {
             cap *= 2;
@@ -1316,17 +1323,14 @@ static char *strofspan (fz_stext_span *span)
     return p;
 }
 
-static int matchspan (regex_t *re, fz_stext_span *span,
+static int matchline (regex_t *re, fz_stext_line *line,
                       int stop, int pageno, double start)
 {
     int ret;
     char *p;
     regmatch_t rm;
-    int a, b, c;
-    fz_rect sb, eb;
-    fz_point p1, p2, p3, p4;
 
-    p = strofspan (span);
+    p = strofline (line);
     if (!p) return -1;
 
     ret = regexec (re, p, 1, &rm, 0);
@@ -1343,31 +1347,33 @@ static int matchspan (regex_t *re, fz_stext_span *span
         return 0;
     }
     else {
-        int l = span->len;
+        fz_point p1, p2, p3, p4;
+        fz_rect s = {0,0,0,0}, e;
+        fz_stext_char *ch;
+        int o = 0;
 
-        for (a = 0, c = 0; c < rm.rm_so && a < l; a++) {
-            c += fz_runelen (span->text[a].c);
+        for (ch = line->first_char; ch; ch = ch->next) {
+            o += fz_runelen (ch->c);
+            if (o > rm.rm_so) {
+                s = ch->bbox;
+                break;
+            }
         }
-        for (b = a; c < rm.rm_eo - 1 && b < l; b++) {
-            c += fz_runelen (span->text[b].c);
+        for (;ch; ch = ch->next) {
+            o += fz_runelen (ch->c);
+            if (o > rm.rm_eo) break;
         }
+        e = ch->bbox;
 
-        if (fz_runelen (span->text[b].c) > 1) {
-            b = fz_maxi (0, b-1);
-        }
+        p1.x = s.x0;
+        p1.y = s.y0;
+        p2.x = e.x1;
+        p2.y = s.y0;
+        p3.x = e.x1;
+        p3.y = e.y1;
+        p4.x = s.x0;
+        p4.y = e.y1;
 
-        fz_stext_char_bbox (state.ctx, &sb, span, a);
-        fz_stext_char_bbox (state.ctx, &eb, span, b);
-
-        p1.x = sb.x0;
-        p1.y = sb.y0;
-        p2.x = eb.x1;
-        p2.y = sb.y0;
-        p3.x = eb.x1;
-        p3.y = eb.y1;
-        p4.x = sb.x0;
-        p4.y = eb.y1;
-
         if (!stop) {
             printd ("firstmatch %d %d %f %f %f %f %f %f %f %f",
                     pageno, 1,
@@ -1393,24 +1399,16 @@ static int matchspan (regex_t *re, fz_stext_span *span
     }
 }
 
-static int compareblocks (const void *l, const void *r)
-{
-    fz_stext_block const *ls = l;
-    fz_stext_block const *rs = r;
-    return ls->bbox.y0 - rs->bbox.y0;
-}
-
 /* wishful thinking function */
 static void search (regex_t *re, int pageno, int y, int forward)
 {
-    int j;
     fz_device *tdev;
     fz_stext_page *text;
-    fz_stext_sheet *sheet;
     struct pagedim *pdim;
     int stop = 0, niters = 0;
     double start, end;
     fz_page *page;
+    fz_stext_block *block;
 
     start = now ();
     while (pageno >= 0 && pageno < state.pagecount && !stop) {
@@ -1428,9 +1426,8 @@ static void search (regex_t *re, int pageno, int y, in
             }
         }
         pdim = pdimofpageno (pageno);
-        sheet = fz_new_stext_sheet (state.ctx);
         text = fz_new_stext_page (state.ctx, &pdim->mediabox);
-        tdev = fz_new_stext_device (state.ctx, sheet, text, 0);
+        tdev = fz_new_stext_device (state.ctx, text, 0);
 
         page = fz_load_page (state.ctx, state.doc, pageno);
         {
@@ -1438,34 +1435,34 @@ static void search (regex_t *re, int pageno, int y, in
             fz_run_page (state.ctx, page, tdev, &ctm, NULL);
         }
 
-        qsort (text->blocks, text->len, sizeof (*text->blocks), compareblocks);
         fz_close_device (state.ctx, tdev);
         fz_drop_device (state.ctx, tdev);
 
-        for (j = 0; j < text->len; ++j) {
-            int k;
-            fz_page_block *pb;
-            fz_stext_block *block;
+        if (forward) {
+            for (block = text->first_block; block; block = block->next) {
+                fz_stext_line *line;
 
-            pb = &text->blocks[forward ? j : text->len - 1 - j];
-            if (pb->type != FZ_PAGE_BLOCK_TEXT) continue;
-            block = pb->u.text;
+                if (block->type != FZ_STEXT_BLOCK_TEXT) continue;
+                for (line = block->u.t.first_line; line; line = line->next) {
+                    if (line->bbox.y0 < y + 1) continue;
 
-            for (k = 0; k < block->len; ++k) {
+                    switch (matchline (re, line, stop, pageno, start)) {
+                    case 0: break;
+                    case 1: stop = 1; break;
+                    case -1: stop = 1; goto endloop;
+                    }
+                }
+            }
+        }
+        else {
+            for (block = text->last_block; block; block = block->prev) {
                 fz_stext_line *line;
-                fz_stext_span *span;
 
-                if (forward) {
-                    line = &block->lines[k];
+                if (block->type != FZ_STEXT_BLOCK_TEXT) continue;
+                for (line = block->u.t.last_line; line; line = line->prev) {
                     if (line->bbox.y0 < y + 1) continue;
-                }
-                else {
-                    line = &block->lines[block->len - 1 - k];
-                    if (line->bbox.y0 > y - 1) continue;
-                }
 
-                for (span = line->first_span; span; span = span->next) {
-                    switch (matchspan (re, span, stop, pageno, start)) {
+                    switch (matchline (re, line, stop, pageno, start)) {
                     case 0: break;
                     case 1: stop = 1; break;
                     case -1: stop = 1; goto endloop;
@@ -1473,6 +1470,7 @@ static void search (regex_t *re, int pageno, int y, in
                 }
             }
         }
+
         if (forward) {
             pageno += 1;
             y = 0;
@@ -1483,7 +1481,6 @@ static void search (regex_t *re, int pageno, int y, in
         }
     endloop:
         fz_drop_stext_page (state.ctx, text);
-        fz_drop_stext_sheet (state.ctx, sheet);
         fz_drop_page (state.ctx, page);
     }
     end = now ();
@@ -1537,17 +1534,13 @@ static void realloctexts (int texcount)
                           state.texids + texcount);
     }
 
-    size = texcount * sizeof (*state.texids);
+    size = texcount * (sizeof (*state.texids) + sizeof (*state.texowners));
     state.texids = realloc (state.texids, size);
     if (!state.texids) {
-        err (1, "realloc texids %" FMT_s, size);
+        err (1, "realloc texs %" FMT_s, size);
     }
 
-    size = texcount * sizeof (*state.texowners);
-    state.texowners = realloc (state.texowners, size);
-    if (!state.texowners) {
-        err (1, "realloc texowners %" FMT_s, size);
-    }
+    state.texowners = (void *) (state.texids + texcount);
     if (texcount > state.texcount) {
         glGenTextures (texcount - state.texcount,
                        state.texids + state.texcount);
@@ -1566,23 +1559,32 @@ static char *mbtoutf8 (char *s)
     wchar_t *tmp;
     size_t i, ret, len;
 
+    if (state.utf8cs) {
+        return s;
+    }
+
     len = mbstowcs (NULL, s, strlen (s));
     if (len == 0) {
         return s;
     }
     else {
         if (len == (size_t) -1) {
+            printd ("emsg mbtoutf8: mbstowcs %d:%s\n", errno, strerror (errno));
             return s;
         }
     }
 
-    tmp = malloc (len * sizeof (wchar_t));
+    tmp = calloc (len, sizeof (wchar_t));
     if (!tmp) {
+        printd ("emsg mbtoutf8: calloc(%zu, %zu) %d:%s",
+                len, sizeof (wchar_t), errno, strerror (errno));
         return s;
     }
 
     ret = mbstowcs (tmp, s, len);
     if (ret == (size_t) -1) {
+        printd ("emsg mbtoutf8: mbswcs %zu characters failed %d:%s\n",
+                len, errno, strerror (errno));
         free (tmp);
         return s;
     }
@@ -1594,6 +1596,7 @@ static char *mbtoutf8 (char *s)
 
     p = r = malloc (len + 1);
     if (!r) {
+        printd ("emsg mbtoutf8: malloc(%zu)", len);
         free (tmp);
         return s;
     }
@@ -1988,87 +1991,45 @@ static void recti (int x0, int y0, int x1, int y1)
 
 static void showsel (struct page *page, int ox, int oy)
 {
-    int seen = 0;
     fz_irect bbox;
     fz_rect rect;
-    fz_stext_line *line;
-    fz_page_block *pageb;
     fz_stext_block *block;
-    struct mark first, last;
+    int seen = 0;
     unsigned char selcolor[] = {15,15,15,140};
 
-    first = page->fmark;
-    last = page->lmark;
+    if (!page->fmark.ch || !page->lmark.ch) return;
 
-    if (!first.span || !last.span) return;
-
     glEnable (GL_BLEND);
     glBlendFunc (GL_SRC_ALPHA, GL_SRC_ALPHA);
     glColor4ubv (selcolor);
 
     ox += state.pagedims[page->pdimno].bounds.x0;
     oy += state.pagedims[page->pdimno].bounds.y0;
-    for (pageb = page->text->blocks;
-         pageb < page->text->blocks + page->text->len;
-         ++pageb) {
-        if (pageb->type != FZ_PAGE_BLOCK_TEXT) continue;
-        block = pageb->u.text;
 
-        for (line = block->lines;
-             line < block->lines + block->len;
-             ++line) {
-            fz_stext_span *span;
-            rect = fz_empty_rect;
+    for (block = page->text->first_block; block; block = block->next) {
+        fz_stext_line *line;
 
-            for (span = line->first_span; span; span = span->next) {
-                int i, j, k;
-                bbox.x0 = bbox.y0 = bbox.x1 = bbox.y1 = 0;
+        if (block->type != FZ_STEXT_BLOCK_TEXT) continue;
+        for (line = block->u.t.first_line; line; line = line->next) {
+            fz_stext_char *ch;
 
-                j = 0;
-                k = span->len - 1;
-
-                if (span == page->fmark.span && span == page->lmark.span) {
-                    seen = 1;
-                    j = fz_mini (first.i, last.i);
-                    k = fz_maxi (first.i, last.i);
-                }
-                else {
-                    if (span == first.span) {
-                        seen = 1;
-                        j = first.i;
-                    }
-                    else if (span == last.span) {
-                        seen = 1;
-                        k = last.i;
-                    }
-                }
-
-                if (seen) {
-                    for (i = j; i <= k; ++i) {
-                        fz_rect bbox1;
-                        fz_union_rect (&rect,
-                                       fz_stext_char_bbox (state.ctx, &bbox1,
-                                                           span, i));
-                    }
+            rect = fz_empty_rect;
+            for (ch = line->first_char; ch; ch = ch->next) {
+                if (ch == page->fmark.ch) seen = 1;
+                if (seen) fz_union_rect (&rect, &ch->bbox);
+                if (ch == page->lmark.ch) {
                     fz_round_rect (&bbox, &rect);
-                    lprintf ("%d %d %d %d oy=%d ox=%d\n",
-                             bbox.x0,
-                             bbox.y0,
-                             bbox.x1,
-                             bbox.y1,
-                             oy, ox);
-
                     recti (bbox.x0 + ox, bbox.y0 + oy,
                            bbox.x1 + ox, bbox.y1 + oy);
-                    if (span == last.span) {
-                        goto done;
-                    }
-                    rect = fz_empty_rect;
+                    goto done;
                 }
             }
+            fz_round_rect (&bbox, &rect);
+            recti (bbox.x0 + ox, bbox.y0 + oy,
+                   bbox.x1 + ox, bbox.y1 + oy);
         }
     }
- done:
+done:
     glDisable (GL_BLEND);
 }
 
@@ -2131,14 +2092,20 @@ static void solidrect (fz_matrix *m,
     glDrawArrays (GL_TRIANGLE_FAN, 0, 4);
 }
 
+static void ensurelinks (struct page *page)
+{
+    if (!page->links)
+        page->links = fz_load_links (state.ctx, page->fzpage);
+}
+
 static void highlightlinks (struct page *page, int xoff, int yoff)
 {
     fz_matrix ctm, tm, pm;
-    fz_link *link, *links;
+    fz_link *link;
     GLfloat *texcoords = state.texcoords;
     GLfloat *vertices = state.vertices;
 
-    links = fz_load_links (state.ctx, page->fzpage);
+    ensurelinks (page);
 
     glEnable (GL_TEXTURE_1D);
     glEnable (GL_BLEND);
@@ -2154,7 +2121,7 @@ static void highlightlinks (struct page *page, int xof
     glTexCoordPointer (1, GL_FLOAT, 0, texcoords);
     glVertexPointer (2, GL_FLOAT, 0, vertices);
 
-    for (link = links; link; link = link->next) {
+    for (link = page->links; link; link = link->next) {
         fz_point p1, p2, p3, p4;
 
         p1.x = link->rect.x0;
@@ -2214,16 +2181,10 @@ static void droptext (struct page *page)
 {
     if (page->text) {
         fz_drop_stext_page (state.ctx, page->text);
-        page->fmark.i = -1;
-        page->lmark.i = -1;
-        page->fmark.span = NULL;
-        page->lmark.span = NULL;
+        page->fmark.ch = NULL;
+        page->lmark.ch = NULL;
         page->text = NULL;
     }
-    if (page->sheet) {
-        fz_drop_stext_sheet (state.ctx, page->sheet);
-        page->sheet = NULL;
-    }
 }
 
 static void dropannots (struct page *page)
@@ -2279,6 +2240,10 @@ static void dropslinks (struct page *page)
         page->slinks = NULL;
         page->slinkcount = 0;
     }
+    if (page->links) {
+        fz_drop_link (state.ctx, page->links);
+        page->links = NULL;
+    }
 }
 
 static void ensureslinks (struct page *page)
@@ -2286,7 +2251,7 @@ static void ensureslinks (struct page *page)
     fz_matrix ctm;
     int i, count;
     size_t slinksize = sizeof (*page->slinks);
-    fz_link *link, *links;
+    fz_link *link;
 
     ensureannots (page);
     if (state.gen != page->sgen) {
@@ -2295,11 +2260,11 @@ static void ensureslinks (struct page *page)
     }
     if (page->slinks) return;
 
-    links = fz_load_links (state.ctx, page->fzpage);
+    ensurelinks (page);
     ctm = pagectm (page);
 
     count = page->annotcount;
-    for (link = links; link; link = link->next) {
+    for (link = page->links; link; link = link->next) {
         count++;
     }
     if (count > 0) {
@@ -2311,7 +2276,7 @@ static void ensureslinks (struct page *page)
             err (1, "calloc slinks %d", count);
         }
 
-        for (i = 0, link = links; link; ++i, link = link->next) {
+        for (i = 0, link = page->links; link; ++i, link = link->next) {
             fz_rect rect;
 
             rect = link->rect;
@@ -2467,20 +2432,20 @@ static void uploadslice (struct tile *tile, struct sli
     }
 }
 
-CAMLprim value ml_begintiles (value unit_v)
+CAMLprim void ml_begintiles (value unit_v)
 {
     CAMLparam1 (unit_v);
     glEnable (TEXT_TYPE);
     glTexCoordPointer (2, GL_FLOAT, 0, state.texcoords);
     glVertexPointer (2, GL_FLOAT, 0, state.vertices);
-    CAMLreturn (unit_v);
+    CAMLreturn0;
 }
 
-CAMLprim value ml_endtiles (value unit_v)
+CAMLprim void ml_endtiles (value unit_v)
 {
     CAMLparam1 (unit_v);
     glDisable (TEXT_TYPE);
-    CAMLreturn (unit_v);
+    CAMLreturn0;
 }
 
 CAMLprim void ml_drawtile (value args_v, value ptr_v)
@@ -2664,9 +2629,9 @@ static fz_link *getlink (struct page *page, int x, int
 {
     fz_point p;
     fz_matrix ctm;
-    fz_link *link, *links;
+    fz_link *link;
 
-    links = fz_load_links (state.ctx, page->fzpage);
+    ensureslinks (page);
 
     p.x = x;
     p.y = y;
@@ -2675,7 +2640,7 @@ static fz_link *getlink (struct page *page, int x, int
     fz_invert_matrix (&ctm, &ctm);
     fz_transform_point (&p, &ctm);
 
-    for (link = links; link; link = link->next) {
+    for (link = page->links; link; link = link->next) {
         if (p.x >= link->rect.x0 && p.x <= link->rect.x1) {
             if (p.y >= link->rect.y0 && p.y <= link->rect.y1) {
                 return link;
@@ -2697,13 +2662,10 @@ static void ensuretext (struct page *page)
 
         page->text = fz_new_stext_page (state.ctx,
                                         &state.pagedims[page->pdimno].mediabox);
-        page->sheet = fz_new_stext_sheet (state.ctx);
-        tdev = fz_new_stext_device (state.ctx, page->sheet, page->text, 0);
+        tdev = fz_new_stext_device (state.ctx, page->text, 0);
         ctm = pagectm (page);
         fz_run_display_list (state.ctx, page->dlist,
                              tdev, &ctm, &fz_infinite_rect, NULL);
-        qsort (page->text->blocks, page->text->len,
-               sizeof (*page->text->blocks), compareblocks);
         fz_close_device (state.ctx, tdev);
         fz_drop_device (state.ctx, tdev);
     }
@@ -2743,7 +2705,9 @@ CAMLprim value ml_find_page_with_links (value start_pa
         }
         else {
             fz_page *page = fz_load_page (state.ctx, state.doc, i);
-            found = !!fz_load_links (state.ctx, page);
+            fz_link *link = fz_load_links (state.ctx, page);
+            found = !!link;
+            fz_drop_link (state.ctx, link);
             fz_drop_page (state.ctx, page);
         }
 
@@ -2917,8 +2881,9 @@ CAMLprim value ml_getlink (value ptr_v, value n_v)
 CAMLprim value ml_getannotcontents (value ptr_v, value n_v)
 {
     CAMLparam2 (ptr_v, n_v);
+    CAMLlocal1 (ret_v);
     pdf_document *pdf;
-    const char *contents = "";
+    char *contents = NULL;
 
     lock (__func__);
     pdf = pdf_specifics (state.ctx, state.doc);
@@ -2929,11 +2894,18 @@ CAMLprim value ml_getannotcontents (value ptr_v, value
 
         page = parse_pointer (__func__, s);
         slink = &page->slinks[Int_val (n_v)];
-        contents = pdf_annot_contents (state.ctx,
-                                       (pdf_annot *) slink->u.annot);
+        contents = pdf_copy_annot_contents (state.ctx,
+                                            (pdf_annot *) slink->u.annot);
     }
     unlock (__func__);
-    CAMLreturn (caml_copy_string (contents));
+    if (contents) {
+        ret_v = caml_copy_string (contents);
+        fz_free (state.ctx, contents);
+    }
+    else  {
+        ret_v = caml_copy_string ("");
+    }
+    CAMLreturn (ret_v);
 }
 
 CAMLprim value ml_getlinkcount (value ptr_v)
@@ -3019,85 +2991,67 @@ CAMLprim value ml_whatsunder (value ptr_v, value x_v, 
     }
     else {
         fz_rect *b;
-        fz_page_block *pageb;
         fz_stext_block *block;
 
         ensuretext (page);
-        for (pageb = page->text->blocks;
-             pageb < page->text->blocks + page->text->len;
-             ++pageb) {
+
+        for (block = page->text->first_block; block; block = block->next) {
             fz_stext_line *line;
-            if (pageb->type != FZ_PAGE_BLOCK_TEXT) continue;
-            block = pageb->u.text;
 
+            if (block->type != FZ_STEXT_BLOCK_TEXT) continue;
             b = &block->bbox;
             if (!(x >= b->x0 && x <= b->x1 && y >= b->y0 && y <= b->y1))
                 continue;
 
-            for (line = block->lines;
-                 line < block->lines + block->len;
-                 ++line) {
-                fz_stext_span *span;
+            for (line = block->u.t.first_line; line; line = line->next) {
+                fz_stext_char *ch;
 
                 b = &line->bbox;
                 if (!(x >= b->x0 && x <= b->x1 && y >= b->y0 && y <= b->y1))
                     continue;
 
-                for (span = line->first_span; span; span = span->next) {
-                    int charnum;
+                for (ch = line->first_char; ch; ch = ch->next) {
+                    b = &ch->bbox;
 
-                    b = &span->bbox;
-                    if (!(x >= b->x0 && x <= b->x1 && y >= b->y0 && y <= b->y1))
-                        continue;
+                    if (x >= b->x0 && x <= b->x1 && y >= b->y0 && y <= b->y1) {
+                        const char *n2 = fz_font_name (state.ctx, ch->font);
+                        FT_FaceRec *face = fz_font_ft_face (state.ctx,
+                                                            ch->font);
 
-                    for (charnum = 0; charnum < span->len; ++charnum) {
-                        fz_rect bbox;
-                        fz_stext_char_bbox (state.ctx, &bbox, span, charnum);
-                        b = &bbox;
+                        if (!n2) n2 = "<unknown font>";
 
-                        if (x >= b->x0 && x <= b->x1
-                            && y >= b->y0 && y <= b->y1) {
-                            fz_stext_style *style = span->text->style;
-                            const char *n2 =
-                                style->font
-                                ? fz_font_name (state.ctx, style->font)
-                                : "Span has no font name"
-                                ;
-                            FT_FaceRec *face = fz_font_ft_face (state.ctx,
-                                                                style->font);
-                            if (face && face->family_name) {
-                                char *s;
-                                char *n1 = face->family_name;
-                                size_t l1 = strlen (n1);
-                                size_t l2 = strlen (n2);
+                        if (face && face->family_name) {
+                            char *s;
+                            char *n1 = face->family_name;
+                            size_t l1 = strlen (n1);
+                            size_t l2 = strlen (n2);
 
-                                if (l1 != l2 || memcmp (n1, n2, l1)) {
-                                    s = malloc (l1 + l2 + 2);
-                                    if (s) {
-                                        memcpy (s, n2, l2);
-                                        s[l2] = '=';
-                                        memcpy (s + l2 + 1, n1, l1 + 1);
-                                        str_v = caml_copy_string (s);
-                                        free (s);
-                                    }
+                            if (l1 != l2 || memcmp (n1, n2, l1)) {
+                                s = malloc (l1 + l2 + 2);
+                                if (s) {
+                                    memcpy (s, n2, l2);
+                                    s[l2] = '=';
+                                    memcpy (s + l2 + 1, n1, l1 + 1);
+                                    str_v = caml_copy_string (s);
+                                    free (s);
                                 }
                             }
-                            if (str_v == Val_unit) {
-                                str_v = caml_copy_string (n2);
-                            }
-                            ret_v = caml_alloc_small (1, utext);
-                            Field (ret_v, 0) = str_v;
-                            goto unlock;
                         }
+                        if (str_v == Val_unit) {
+                            str_v = caml_copy_string (n2);
+                        }
+                        ret_v = caml_alloc_small (1, utext);
+                        Field (ret_v, 0) = str_v;
+                        goto unlock;
                     }
                 }
             }
         }
     }
- unlock:
+unlock:
     unlock (__func__);
 
- done:
+done:
     CAMLreturn (ret_v);
 }
 
@@ -3120,10 +3074,8 @@ CAMLprim void ml_clearmark (value ptr_v)
     }
 
     page = parse_pointer (__func__, s);
-    page->fmark.span = NULL;
-    page->lmark.span = NULL;
-    page->fmark.i = 0;
-    page->lmark.i = 0;
+    page->fmark.ch = NULL;
+    page->lmark.ch = NULL;
 
     unlock (__func__);
  done:
@@ -3137,7 +3089,6 @@ CAMLprim value ml_markunder (value ptr_v, value x_v, v
     fz_rect *b;
     struct page *page;
     fz_stext_line *line;
-    fz_page_block *pageb;
     fz_stext_block *block;
     struct pagedim *pdim;
     int mark = Int_val (mark_v);
@@ -3155,34 +3106,8 @@ CAMLprim value ml_markunder (value ptr_v, value x_v, v
     ensuretext (page);
 
     if (mark == mark_page) {
-        int i;
-        fz_page_block *pb1 = NULL, *pb2 = NULL;
-
-        for (i = 0; i < page->text->len; ++i) {
-            if (page->text->blocks[i].type == FZ_PAGE_BLOCK_TEXT) {
-                pb1 = &page->text->blocks[i];
-                break;
-            }
-        }
-        if (!pb1) goto unlock;
-
-        for (i = page->text->len - 1; i >= 0; --i) {
-            if (page->text->blocks[i].type == FZ_PAGE_BLOCK_TEXT) {
-                pb2 = &page->text->blocks[i];
-                break;
-            }
-        }
-        if (!pb2) goto unlock;
-
-        block = pb1->u.text;
-
-        page->fmark.i = 0;
-        page->fmark.span = block->lines->first_span;
-
-        block = pb2->u.text;
-        line = &block->lines[block->len - 1];
-        page->lmark.i = line->last_span->len - 1;
-        page->lmark.span = line->last_span;
+        page->fmark.ch = page->text->first_block->u.t.first_line->first_char;
+        page->lmark.ch = page->text->last_block->u.t.last_line->last_char;
         ret_v = Val_bool (1);
         goto unlock;
     }
@@ -3190,102 +3115,62 @@ CAMLprim value ml_markunder (value ptr_v, value x_v, v
     x += pdim->bounds.x0;
     y += pdim->bounds.y0;
 
-    for (pageb = page->text->blocks;
-         pageb < page->text->blocks + page->text->len;
-         ++pageb) {
-        if (pageb->type != FZ_PAGE_BLOCK_TEXT) continue;
-        block = pageb->u.text;
-
+    for (block = page->text->first_block; block; block = block->next) {
+        if (block->type != FZ_STEXT_BLOCK_TEXT) continue;
         b = &block->bbox;
         if (!(x >= b->x0 && x <= b->x1 && y >= b->y0 && y <= b->y1))
             continue;
 
         if (mark == mark_block) {
-            page->fmark.i = 0;
-            page->fmark.span = block->lines->first_span;
-
-            line = &block->lines[block->len - 1];
-            page->lmark.i = line->last_span->len - 1;
-            page->lmark.span = line->last_span;
+            page->fmark.ch = block->u.t.first_line->first_char;
+            page->lmark.ch = block->u.t.last_line->last_char;
             ret_v = Val_bool (1);
             goto unlock;
         }
 
-        for (line = block->lines;
-             line < block->lines + block->len;
-             ++line) {
-            fz_stext_span *span;
+        for (line = block->u.t.first_line; line; line = line->next) {
+            fz_stext_char *ch;
 
             b = &line->bbox;
             if (!(x >= b->x0 && x <= b->x1 && y >= b->y0 && y <= b->y1))
                 continue;
 
             if (mark == mark_line) {
-                page->fmark.i = 0;
-                page->fmark.span = line->first_span;
-
-                page->lmark.i = line->last_span->len - 1;
-                page->lmark.span = line->last_span;
+                page->fmark.ch = line->first_char;
+                page->lmark.ch = line->last_char;
                 ret_v = Val_bool (1);
                 goto unlock;
             }
 
-            for (span = line->first_span; span; span = span->next) {
-                int charnum;
-
-                b = &span->bbox;
-                if (!(x >= b->x0 && x <= b->x1 && y >= b->y0 && y <= b->y1))
-                    continue;
-
-                for (charnum = 0; charnum < span->len; ++charnum) {
-                    fz_rect bbox;
-                    fz_stext_char_bbox (state.ctx, &bbox, span, charnum);
-                    b = &bbox;
-
-                    if (x >= b->x0 && x <= b->x1 && y >= b->y0 && y <= b->y1) {
-                        /* unicode ftw */
-                        int charnum2, charnum3 = -1, charnum4 = -1;
-
-                        if (uninteresting (span->text[charnum].c)) goto unlock;
-
-                        for (charnum2 = charnum; charnum2 >= 0; --charnum2) {
-                            if (uninteresting (span->text[charnum2].c)) {
-                                charnum3 = charnum2 + 1;
-                                break;
-                            }
-                        }
-                        if (charnum3 == -1) charnum3 = 0;
-
-                        charnum4 = charnum;
-                        for (charnum2 = charnum + 1;
-                             charnum2 < span->len;
-                             ++charnum2) {
-                            if (uninteresting (span->text[charnum2].c)) break;
-                            charnum4 = charnum2;
-                        }
-
-                        page->fmark.i = charnum3;
-                        page->fmark.span = span;
-
-                        page->lmark.i = charnum4;
-                        page->lmark.span = span;
-                        ret_v = Val_bool (1);
-                        goto unlock;
+            for (ch = line->first_char; ch; ch = ch->next) {
+                fz_stext_char *ch2, *first = NULL, *last = NULL;
+                b = &ch->bbox;
+                if (x >= b->x0 && x <= b->x1 && y >= b->y0 && y <= b->y1) {
+                    for (ch2 = line->first_char; ch2 != ch; ch2 = ch2->next) {
+                        if (uninteresting (ch2->c)) first = NULL;
+                        else if (!first) first = ch2;
                     }
+                    for (ch2 = ch; ch2; ch2 = ch2->next) {
+                        if (uninteresting (ch2->c)) break;
+                        last = ch2;
+                    }
+
+                    page->fmark.ch = first;
+                    page->lmark.ch = last;
+                    ret_v = Val_bool (1);
+                    goto unlock;
                 }
             }
         }
     }
- unlock:
+unlock:
     if (!Bool_val (ret_v)) {
-        page->fmark.span = NULL;
-        page->lmark.span = NULL;
-        page->fmark.i = 0;
-        page->lmark.i = 0;
+        page->fmark.ch = NULL;
+        page->lmark.ch = NULL;
     }
     unlock (__func__);
 
- done:
+done:
     CAMLreturn (ret_v);
 }
 
@@ -3295,8 +3180,8 @@ CAMLprim value ml_rectofblock (value ptr_v, value x_v,
     CAMLlocal2 (ret_v, res_v);
     fz_rect *b = NULL;
     struct page *page;
-    fz_page_block *pageb;
     struct pagedim *pdim;
+    fz_stext_block *block;
     char *s = String_val (ptr_v);
     int x = Int_val (x_v), y = Int_val (y_v);
 
@@ -3312,16 +3197,14 @@ CAMLprim value ml_rectofblock (value ptr_v, value x_v,
 
     ensuretext (page);
 
-    for (pageb = page->text->blocks;
-         pageb < page->text->blocks + page->text->len;
-         ++pageb) {
-        switch (pageb->type) {
-        case FZ_PAGE_BLOCK_TEXT:
-            b = &pageb->u.text->bbox;
+    for (block = page->text->first_block; block; block = block->next) {
+        switch (block->type) {
+        case FZ_STEXT_BLOCK_TEXT:
+            b = &block->bbox;
             break;
 
-        case FZ_PAGE_BLOCK_IMAGE:
-            b = &pageb->u.image->bbox;
+        case FZ_STEXT_BLOCK_IMAGE:
+            b = &block->bbox;
             break;
 
         default:
@@ -3354,11 +3237,11 @@ CAMLprim void ml_seltext (value ptr_v, value rect_v)
     struct page *page;
     struct pagedim *pdim;
     char *s = String_val (ptr_v);
-    int i, x0, x1, y0, y1, fi, li;
+    int x0, x1, y0, y1;
+    fz_stext_char *ch;
     fz_stext_line *line;
-    fz_page_block *pageb;
     fz_stext_block *block;
-    fz_stext_span *span, *fspan, *lspan;
+    fz_stext_char *fc, *lc;
 
     if (trylock (__func__)) {
         goto done;
@@ -3381,76 +3264,51 @@ CAMLprim void ml_seltext (value ptr_v, value rect_v)
         x1 = t;
     }
 
-    fi = page->fmark.i;
-    fspan = page->fmark.span;
+    fc = page->fmark.ch;
+    lc = page->lmark.ch;
 
-    li = page->lmark.i;
-    lspan = page->lmark.span;
-
-    for (pageb = page->text->blocks;
-         pageb < page->text->blocks + page->text->len;
-         ++pageb) {
-        if (pageb->type != FZ_PAGE_BLOCK_TEXT) continue;
-        block = pageb->u.text;
-        for (line = block->lines;
-             line < block->lines + block->len;
-             ++line) {
-
-            for (span = line->first_span; span; span = span->next) {
-                for (i = 0; i < span->len; ++i) {
-                    fz_stext_char_bbox (state.ctx, &b, span, i);
-
-                    if (x0 >= b.x0 && x0 <= b.x1
-                        && y0 >= b.y0 && y0 <= b.y1) {
-                        fspan = span;
-                        fi = i;
-                    }
-                    if (x1 >= b.x0 && x1 <= b.x1
-                        && y1 >= b.y0 && y1 <= b.y1) {
-                        lspan = span;
-                        li = i;
-                    }
+    for (block = page->text->first_block; block; block = block->next) {
+        if (block->type != FZ_STEXT_BLOCK_TEXT) continue;
+        for (line = block->u.t.first_line; line; line = line->next) {
+            for (ch = line->first_char; ch; ch = ch->next) {
+                b = ch->bbox;
+                if (x0 >= b.x0 && x0 <= b.x1 && y0 >= b.y0 && y0 <= b.y1) {
+                    fc = ch;
                 }
+                if (x1 >= b.x0 && x1 <= b.x1 && y1 >= b.y0 && y1 <= b.y1) {
+                    lc = ch;
+                }
             }
         }
     }
-    if (x1 < x0 && fspan == lspan) {
-        i = fi;
-        span = fspan;
+    if (x1 < x0 && fc == lc) {
+        fz_stext_char *t;
 
-        fi = li;
-        fspan = lspan;
-
-        li = i;
-        lspan = span;
+        t = fc;
+        fc = lc;
+        lc = t;
     }
 
-    page->fmark.i = fi;
-    page->fmark.span = fspan;
+    page->fmark.ch = fc;
+    page->lmark.ch = lc;
 
-    page->lmark.i = li;
-    page->lmark.span = lspan;
-
     unlock (__func__);
 
  done:
     CAMLreturn0;
 }
 
-static int UNUSED_ATTR pipespan (FILE *f, fz_stext_span *span, int a, int b)
+static int pipechar (FILE *f, fz_stext_char *ch)
 {
     char buf[4];
-    int i, len, ret;
+    int len, ret;
 
-    for (i = a; i <= b; ++i) {
-        len = fz_runetochar (buf, span->text[i].c);
-        ret = fwrite (buf, len, 1, f);
-
-        if (ret != 1) {
-            fprintf (stderr, "failed to write %d bytes ret=%d: %s\n",
-                     len, ret, strerror (errno));
-            return -1;
-        }
+    len = fz_runetochar (buf, ch->c);
+    ret = fwrite (buf, len, 1, f);
+    if (ret != 1) {
+        fprintf (stderr, "failed to write %d bytes ret=%d: %s\n",
+                 len, ret, strerror (errno));
+        return -1;
     }
     return 0;
 }
@@ -3549,7 +3407,7 @@ CAMLprim value ml_hassel (value ptr_v)
     }
 
     page = parse_pointer (__func__, s);
-    ret_v = Val_bool (page->fmark.span && page->lmark.span);
+    ret_v = Val_bool (page->fmark.ch && page->lmark.ch);
     unlock (__func__);
  done:
     CAMLreturn (ret_v);
@@ -3562,7 +3420,6 @@ CAMLprim void ml_copysel (value fd_v, value ptr_v)
     int seen = 0;
     struct page *page;
     fz_stext_line *line;
-    fz_page_block *pageb;
     fz_stext_block *block;
     int fd = Int_val (fd_v);
     char *s = String_val (ptr_v);
@@ -3573,7 +3430,7 @@ CAMLprim void ml_copysel (value fd_v, value ptr_v)
 
     page = parse_pointer (__func__, s);
 
-    if (!page->fmark.span || !page->lmark.span) {
+    if (!page->fmark.ch || !page->lmark.ch) {
         fprintf (stderr, "nothing to copy on page %d\n", page->pageno);
         goto unlock;
     }
@@ -3585,43 +3442,24 @@ CAMLprim void ml_copysel (value fd_v, value ptr_v)
         f = stdout;
     }
 
-    for (pageb = page->text->blocks;
-         pageb < page->text->blocks + page->text->len;
-         ++pageb) {
-        if (pageb->type != FZ_PAGE_BLOCK_TEXT) continue;
-        block = pageb->u.text;
-        for (line = block->lines;
-             line < block->lines + block->len;
-             ++line) {
-            fz_stext_span *span;
-
-            for (span = line->first_span; span; span = span->next) {
-                int a, b;
-
-                seen |= span == page->fmark.span || span == page->lmark.span;
-                a = span == page->fmark.span ? page->fmark.i : 0;
-                b = span == page->lmark.span ? page->lmark.i : span->len - 1;
-
-                if (seen) {
-                    if (pipespan (f, span, a, b)) {
-                        goto close;
-                    }
-                    if (span == page->lmark.span) {
-                        goto close;
-                    }
-                    if (span == line->last_span) {
-                        if (putc ('\n', f) == EOF) {
-                            fprintf (stderr,
-                                     "failed break line on sel pipe: %s\n",
-                                     strerror (errno));
-                            goto close;
-                        }
-                    }
+    for (block = page->text->first_block; block; block = block->next) {
+        if (block->type != FZ_STEXT_BLOCK_TEXT) continue;
+        for (line = block->u.t.first_line; line; line = line->next) {
+            fz_stext_char *ch;
+            for (ch = line->first_char; ch; ch = ch->next) {
+                if (seen || ch == page->fmark.ch) {
+                    do {
+                        pipechar (f, ch);
+                        if (ch == page->lmark.ch) goto close;
+                    } while ((ch = ch->next));
+                    seen = 1;
+                    break;
                 }
             }
+            if (seen) fputc ('\n', f);
         }
     }
- close:
+close:
     if (f != stdout) {
         int ret = fclose (f);
         fd = -1;
@@ -3632,10 +3470,10 @@ CAMLprim void ml_copysel (value fd_v, value ptr_v)
             }
         }
     }
- unlock:
+unlock:
     unlock (__func__);
 
- done:
+done:
     if (fd >= 0) {
         if (close (fd)) {
             fprintf (stderr, "failed to close sel pipe: %s\n",
@@ -3768,7 +3606,6 @@ CAMLprim value ml_getpagebox (value opaque_v)
 
     ret_v = caml_alloc_tuple (4);
     dev = fz_new_bbox_device (state.ctx, &rect);
-    dev->hints |= FZ_IGNORE_SHADE;
 
     ctm = pagectm (page);
     fz_run_page (state.ctx, page->fzpage, dev, &ctm, NULL);
@@ -3792,6 +3629,7 @@ CAMLprim void ml_setaalevel (value level_v)
     CAMLreturn0;
 }
 
+#ifndef __COCOA__
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wvariadic-macros"
 #include <X11/Xlib.h>
@@ -3848,7 +3686,6 @@ CAMLprim value ml_glxinit (value display_v, value wid_
     int num_conf;
     EGLint visid;
     EGLint attribs[] = {
-        EGL_DEPTH_SIZE, 24,
         EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
         EGL_RENDERABLE_TYPE, EGL_OPENGL_BIT,
         EGL_NONE
@@ -3887,7 +3724,7 @@ CAMLprim value ml_glxinit (value display_v, value wid_
     CAMLreturn (Val_int (visid));
 }
 
-CAMLprim value ml_glxcompleteinit (value unit_v)
+CAMLprim void ml_glxcompleteinit (value unit_v)
 {
     CAMLparam1 (unit_v);
 
@@ -3902,12 +3739,11 @@ CAMLprim value ml_glxcompleteinit (value unit_v)
         caml_failwith ("eglCreateWindowSurface");
     }
 
-    XFree (glx.visual);
     if (!eglMakeCurrent (glx.edpy, glx.win, glx.win, glx.ctx)) {
         glx.ctx = NULL;
         caml_failwith ("eglMakeCurrent");
     }
-    CAMLreturn (unit_v);
+    CAMLreturn0;
 }
 #else
 CAMLprim value ml_glxinit (value display_v, value wid_v, value screen_v)
@@ -3932,7 +3768,7 @@ CAMLprim value ml_glxinit (value display_v, value wid_
     CAMLreturn (Val_int (glx.visual->visualid));
 }
 
-CAMLprim value ml_glxcompleteinit (value unit_v)
+CAMLprim void ml_glxcompleteinit (value unit_v)
 {
     CAMLparam1 (unit_v);
 
@@ -3949,7 +3785,7 @@ CAMLprim value ml_glxcompleteinit (value unit_v)
         glx.ctx = NULL;
         caml_failwith ("glXMakeCurrent");
     }
-    CAMLreturn (unit_v);
+    CAMLreturn0;
 }
 #endif
 
@@ -3964,7 +3800,7 @@ CAMLprim void ml_setcursor (value cursor_v)
     CAMLreturn0;
 }
 
-CAMLprim value ml_swapb (value unit_v)
+CAMLprim void ml_swapb (value unit_v)
 {
     CAMLparam1 (unit_v);
 #ifdef USE_EGL
@@ -3974,7 +3810,7 @@ CAMLprim value ml_swapb (value unit_v)
 #else
     glXSwapBuffers (glx.dpy, glx.wid);
 #endif
-    CAMLreturn (unit_v);
+    CAMLreturn0;
 }
 
 #include "keysym2ucs.c"
@@ -3994,7 +3830,22 @@ CAMLprim value ml_keysymtoutf8 (value keysym_v)
     str_v = caml_copy_string (buf);
     CAMLreturn (str_v);
 }
+#else
+CAMLprim value ml_keysymtoutf8 (value keysym_v)
+{
+    CAMLparam1 (keysym_v);
+    CAMLlocal1 (str_v);
+    long ucs_v = Long_val (keysym_v);
+    int len;
+    char buf[5];
 
+    len = fz_runetochar (buf, ucs_v);
+    buf[len] = 0;
+    str_v = caml_copy_string (buf);
+    CAMLreturn (str_v);
+}
+#endif
+
 enum { piunknown, pilinux, piosx, pisun, pibsd, picygwin };
 
 CAMLprim value ml_platform (value unit_v)
@@ -4008,8 +3859,7 @@ CAMLprim value ml_platform (value unit_v)
     platid = pilinux;
 #elif defined __CYGWIN__
     platid = picygwin;
-#elif defined __DragonFly__ || defined __FreeBSD__
-    || defined __OpenBSD__ || defined __NetBSD__
+#elif defined __DragonFly__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __NetBSD__
     platid = pibsd;
 #elif defined __sun__
     platid = pisun;
@@ -4145,6 +3995,12 @@ CAMLprim void ml_unmappbo (value s_v)
 
 static void setuppbo (void)
 {
+#ifdef __COCOA__
+  static CFBundleRef framework = NULL;
+  if (framework == NULL)
+    framework = CFBundleGetBundleWithIdentifier (CFSTR ("com.apple.opengl"));
+#define GGPA(n) (&state.n = CFBundleGetFunctionPointerForName (framework, CFSTR (#n)))
+#else
 #ifdef USE_EGL
 #define GGPA(n) (*(void (**) ()) &state.n = eglGetProcAddress (#n))
 #else
@@ -4156,6 +4012,7 @@ static void setuppbo (void)
         && GGPA (glBufferDataARB)
         && GGPA (glGenBuffersARB)
         && GGPA (glDeleteBuffersARB);
+#endif
 #undef GGPA
 }
 
@@ -4364,101 +4221,6 @@ CAMLprim value ml_fz_version (value UNUSED_ATTR unit_v
     return caml_copy_string (FZ_VERSION);
 }
 
-#ifdef USE_FONTCONFIG
-static struct {
-    int inited;
-    FcConfig *config;
-} fc;
-
-static fz_font *fc_load_system_font_func (fz_context *ctx,
-                                          const char *name,
-                                          int bold,
-                                          int italic,
-                                          int UNUSED_ATTR needs_exact_metrics)
-{
-    char *buf;
-    size_t i, size;
-    fz_font *font;
-    FcChar8 *path;
-    FcResult result;
-    FcPattern *pat, *pat1;
-
-    lprintf ("looking up %s bold:%d italic:%d needs_exact_metrics:%d\n",
-             name, bold, italic, needs_exact_metrics);
-    if (!fc.inited) {
-        fc.inited = 1;
-        fc.config = FcInitLoadConfigAndFonts ();
-        if (!fc.config) {
-            lprintf ("FcInitLoadConfigAndFonts failed\n");
-            return NULL;
-        }
-    }
-    if (!fc.config) return NULL;
-
-    size = strlen (name);
-    if (bold) size += sizeof (":bold") - 1;
-    if (italic) size += sizeof (":italic") - 1;
-    size += 1;
-
-    buf = malloc (size);
-    if (!buf) {
-        err (1, "malloc %zu failed", size);
-    }
-
-    strcpy (buf, name);
-    if (bold && italic) {
-        strcat (buf, ":bold:italic");
-    }
-    else {
-        if (bold) strcat (buf, ":bold");
-        if (italic) strcat (buf, ":italic");
-    }
-    for (i = 0; i < size; ++i) {
-        if (buf[i] == ',' || buf[i] == '-') buf[i] = ':';
-    }
-
-    lprintf ("fcbuf=%s\n", buf);
-    pat = FcNameParse ((FcChar8 *) buf);
-    if (!pat) {
-        printd ("emsg FcNameParse failed\n");
-        free (buf);
-        return NULL;
-    }
-
-    if (!FcConfigSubstitute (fc.config, pat, FcMatchPattern)) {
-        printd ("emsg FcConfigSubstitute failed\n");
-        free (buf);
-        return NULL;
-    }
-    FcDefaultSubstitute (pat);
-
-    pat1 = FcFontMatch (fc.config, pat, &result);
-    if (!pat1) {
-        printd ("emsg FcFontMatch failed\n");
-        FcPatternDestroy (pat);
-        free (buf);
-        return NULL;
-    }
-
-    if (FcPatternGetString (pat1, FC_FILE, 0, &path) != FcResultMatch) {
-        printd ("emsg FcPatternGetString failed\n");
-        FcPatternDestroy (pat);
-        FcPatternDestroy (pat1);
-        free (buf);
-        return NULL;
-    }
-
-#if 0
-    printd ("emsg name=%s path=%s\n", name, path);
-#endif
-    font = fz_new_font_from_file (ctx, name, (char *) path, 0, 0);
-    FcPatternDestroy (pat);
-    FcPatternDestroy (pat1);
-    free (buf);
-    return font;
-}
-#endif
-
 CAMLprim void ml_init (value csock_v, value params_v)
 {
     CAMLparam2 (csock_v, params_v);
@@ -4470,6 +4232,20 @@ CAMLprim void ml_init (value csock_v, value params_v)
     int mustoresize;
     int haspboext;
 
+    /* Without following call to setlocale mbstowcs fails for, at
+       least, strings containing chinese symbols (中 for instance)
+       (with glibc citing EILSEQ="Invalid or incomplete multibyte or
+       wide character" as the reason of failure and with macOS
+       producing bogus output) */
+    if (setlocale (LC_CTYPE, "")) {
+        /* Following two lines were taken from dvtm/vt.c */
+        const char *cset = nl_langinfo (CODESET);
+        state.utf8cs = !strcmp (cset, "UTF-8");
+    }
+    else {
+        fprintf (stderr, "setlocale failed\n");
+    }
+
     state.csock         = Int_val (csock_v);
     state.rotate        = Int_val (Field (params_v, 0));
     state.fitmodel      = Int_val (Field (params_v, 1));
@@ -4489,19 +4265,11 @@ CAMLprim void ml_init (value csock_v, value params_v)
         }
     }
 
-    haspboext           = Bool_val (Field (params_v, 9));
+    haspboext         = Bool_val (Field (params_v, 9));
 
     state.ctx = fz_new_context (NULL, NULL, mustoresize);
     fz_register_document_handlers (state.ctx);
 
-#ifdef USE_FONTCONFIG
-    if (Bool_val (Field (params_v, 11))) {
-        fz_install_load_system_font_funcs (
-            state.ctx, fc_load_system_font_func, NULL
-            );
-    }
-#endif
-
     state.trimmargins = Bool_val (Field (trim_v, 0));
     fuzz_v            = Field (trim_v, 1);
     state.trimfuzz.x0 = Int_val (Field (fuzz_v, 0));
@@ -4512,48 +4280,13 @@ CAMLprim void ml_init (value csock_v, value params_v)
     set_tex_params (colorspace);
 
     if (*fontpath) {
-#ifndef USE_FONTCONFIG
         state.face = load_font (fontpath);
-#else
-        FcChar8 *path;
-        FcResult result;
-        char *buf = fontpath;
-        FcPattern *pat, *pat1;
-
-        fc.inited = 1;
-        fc.config = FcInitLoadConfigAndFonts ();
-        if (!fc.config) {
-            errx (1, "FcInitLoadConfigAndFonts failed");
-        }
-
-        pat = FcNameParse ((FcChar8 *) buf);
-        if (!pat) {
-            errx (1, "FcNameParse failed");
-        }
-
-        if (!FcConfigSubstitute (fc.config, pat, FcMatchPattern)) {
-            errx (1, "FcConfigSubstitute failed");
-        }
-        FcDefaultSubstitute (pat);
-
-        pat1 = FcFontMatch (fc.config, pat, &result);
-        if (!pat1) {
-            errx (1, "FcFontMatch failed");
-        }
-
-        if (FcPatternGetString (pat1, FC_FILE, 0, &path) != FcResultMatch) {
-            errx (1, "FcPatternGetString failed");
-        }
-
-        state.face = load_font ((char *) path);
-        FcPatternDestroy (pat);
-        FcPatternDestroy (pat1);
-#endif
     }
     else {
         int len;
-        const char *data = pdf_lookup_substitute_font (state.ctx, 0, 0,
-                                                       0, 0, &len);
+        const unsigned char *data;
+
+        data = pdf_lookup_substitute_font (state.ctx, 0, 0, 0, 0, &len);
         state.face = load_builtin_font (data, len);
     }
     if (!state.face) _exit (1);
