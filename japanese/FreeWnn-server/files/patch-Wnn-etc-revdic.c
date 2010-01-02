Index: Wnn/etc/revdic.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/etc/revdic.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- Wnn/etc/revdic.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/etc/revdic.c	20 Dec 2008 15:22:40 -0000	1.2
@@ -5,7 +5,7 @@
 /*
  * FreeWnn is a network-extensible Kana-to-Kanji conversion system.
  * This file is part of FreeWnn.
- * 
+ *
  * Copyright Kyoto University Research Institute for Mathematical Sciences
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
@@ -35,13 +35,11 @@
 #include "jh.h"
 #include "jdata.h"
 
-
 #ifndef min
 #define min(a, b) ((a > b)? b:a)
 #define max(a, b) ((a < b)? b:a)
 #endif
 
-
 /*
  * rev_ud_hontai(hostart, maxhontai)
  * rev_ud_table(tary, maxtable)
@@ -51,96 +49,81 @@
 
 static int tmptmp;
 
-#define rev_int(x) (tmptmp = *(x), *(x) = ((tmptmp >> 24) & 0xff) | \
-                                      (((tmptmp >> 16) & 0xff) << 8) | \
-                                      (((tmptmp >> 8) & 0xff) << 16) | \
-                                      (((tmptmp & 0xff) << 24)))
+#define rev_int(x) (tmptmp = *(x), *(x) = ((tmptmp >> 24) & 0xff) |    \
+		    (((tmptmp >> 16) & 0xff) << 8) |		       \
+		    (((tmptmp >> 8) & 0xff) << 16) |		       \
+		    (((tmptmp & 0xff) << 24)))
 
 #define rev_short(x) (tmptmp = *(x), *(x) = ((tmptmp >> 8) & 0xff) | \
-                                            ((tmptmp & 0xff) << 8))
+		      ((tmptmp & 0xff) << 8))
 
 #define rev_int_org(x) (tmptmp = *(x), *(x) = ((tmptmp >> 24) & 0xff) | \
-                                      (((tmptmp >> 16) & 0xff) << 8) | \
-                                      (((tmptmp >> 8) & 0xff) << 16) | \
-                                      ((tmptmp & 0xff) << 24), tmptmp)
+			(((tmptmp >> 16) & 0xff) << 8) |		\
+			(((tmptmp >> 8) & 0xff) << 16) |		\
+			((tmptmp & 0xff) << 24), tmptmp)
 
 #define rev_short_org(x) (tmptmp = *(x), *(x) = ((tmptmp >> 8) & 0xff) | \
-                                            ((tmptmp & 0xff) << 8), tmptmp)
+			  ((tmptmp & 0xff) << 8), tmptmp)
 
+void
+rev_ud_hontai(UCHAR *hostart,
+	      int maxhontai,
+	      int match		/* whether the cpu type match the dictionary */
+	)
+{
+	UCHAR *hoend = hostart + maxhontai;
+	struct uind2 *hop, *hop1;
+	int k;
+	int len;
+
+	/* Skip first 4 bytes for some reason. (cf. ujistoud() in atod.c) */
+	for (hop = (struct uind2 *)((int *) hostart + 1); (UCHAR *) hop < hoend;) {
+		rev_int(&(hop->next));
+		rev_int(&(hop->serial));
+		rev_int(&(hop->kanjipter));
+		rev_short(&(hop->kosuu));
+
+		if (match) {
+			len = hop->yomi[0];
+			hop1 = (struct uind2 *)(AL_INT (&(hop->yomi[0]) + 1 + max((len - 4), 0)));
+			rev_short(&(hop->yomi[0]));
+			for (k = 0; k < len - 4; k++)
+				rev_short(&(hop->yomi[k + 1]));
+			hop = hop1;
+		} else {
+			rev_short(&(hop->yomi[0]));
+			len = hop->yomi[0];
+			for (k = 0; k < len - 4; k++)
+				rev_short(&(hop->yomi[k + 1]));
+			hop = (struct uind2 *)(AL_INT (&(hop->yomi[0]) + 1 + max((len - 4), 0)));
+		}
+	}
+}
 
+void
+rev_ud_table(struct uind1 *tary,
+	     int maxtable,
+	     int match)
+{
+	int k;
+
+	for (k = 0; k < maxtable; k++) {
+		rev_int(&(tary[k].pter1));
+		rev_int(&(tary[k].pter));
+		rev_int(&(tary[k].yomi1));
+		rev_int(&(tary[k].yomi2));
+	}
+}
 
 void
-rev_ud_hontai (hostart, maxhontai, match)
-     UCHAR *hostart;
-     int maxhontai;
-     int match;                 /* whether the cpu type match the dictionary */
-{
-  UCHAR *hoend = hostart + maxhontai;
-  struct uind2 *hop, *hop1;
-  int k;
-  int len;
-
-  /* Skip first 4 bytes for some reason. (cf. ujistoud() in atod.c) */ 
-  for (hop = (struct uind2 *)((int *) hostart + 1); (UCHAR *) hop < hoend;)
-    {
-      rev_int (&(hop->next));
-      rev_int (&(hop->serial));
-      rev_int (&(hop->kanjipter));
-      rev_short (&(hop->kosuu));
-      if (match)
-        {
-          len = hop->yomi[0];
-          hop1 = (struct uind2 *) (AL_INT (&(hop->yomi[0]) + 1 + max ((len - 4), 0)));
-          rev_short (&(hop->yomi[0]));
-          for (k = 0; k < len - 4; k++)
-            {
-              rev_short (&(hop->yomi[k + 1]));
-            }
-          hop = hop1;
-        }
-      else
-        {
-          rev_short (&(hop->yomi[0]));
-          len = hop->yomi[0];
-          for (k = 0; k < len - 4; k++)
-            {
-              rev_short (&(hop->yomi[k + 1]));
-            }
-          hop = (struct uind2 *) (AL_INT (&(hop->yomi[0]) + 1 + max ((len - 4), 0)));
-        }
-    }
-}
-
-
-void
-rev_ud_table (tary, maxtable, match)
-     struct uind1 *tary;
-     int maxtable;
-     int match;
-{
-  int k;
-
-  for (k = 0; k < maxtable; k++)
-    {
-      rev_int (&(tary[k].pter1));
-      rev_int (&(tary[k].pter));
-      rev_int (&(tary[k].yomi1));
-      rev_int (&(tary[k].yomi2));
-    }
-}
-
-void
-rev_hinsi (hinsi, maxserial, match)
-     unsigned short *hinsi;
-     int maxserial;
-     int match;
-{
-  int k;
-
-  for (k = 0; k < maxserial; k++)
-    {
-      rev_short (&(hinsi[k]));
-    }
+rev_hinsi(unsigned short *hinsi,
+	  int maxserial,
+	  int match)
+{
+	int k;
+
+	for (k = 0; k < maxserial; k++)
+		rev_short(&(hinsi[k]));
 }
 
 /*
@@ -154,200 +137,183 @@ void travel_next_nodes ();
 void rev_sd_node ();
 
 void
-rev_sd_hontai0 (hopter, hostart, match)
-     UCHAR *hostart;
-     UCHAR *hopter;
-     int match;
-{
-  if (match)
-    {
-      travel_next_nodes (hopter, hostart, match);
-      rev_sd_node (hopter, hostart, match);
-    }
-  else
-    {
-      rev_sd_node (hopter, hostart, match);
-      travel_next_nodes (hopter, hostart, match);
-    }
-}
-
-void
-rev_sd_hontai (hostart, match)
-     UCHAR *hostart;
-     int match;
-{
-  rev_sd_hontai0 (hostart, hostart, match);
-}
-
-void
-travel_next_nodes (hopter, hostart, match)
-     UCHAR *hostart, *hopter;
-     int match;
-{
-  int k;
-  int tsize;
-  w_char *charst;
-  w_char *sumst;
-  int *ptrst;
-
-  switch (*(unsigned short *) hopter)
-    {
-    case ST_NORMAL:
-      tsize = *(w_char *) (hopter + 2);
-      charst = (w_char *) (hopter + 12);
-      sumst = ((w_char *) charst + tsize + 2);  /* + 2 keeps two zero words */
-      ptrst = (int *) ((w_char *) sumst + tsize);
-      for (k = 0; k < tsize; k++)
-        {
-          if (ptrst[k] != ENDPTR)
-            {
-              rev_sd_hontai0 (hostart + ptrst[k], hostart, match);
-            }
-        }
-      break;
-    case ST_NOPTER:
-      break;
-    case ST_NOENT:
-      tsize = *(w_char *) (hopter + 2);
-      charst = (w_char *) (hopter + 4);
-      ptrst = (int *) AL_INT ((w_char *) charst + tsize);
-      for (k = 0; k < tsize; k++)
-        {
-          rev_sd_hontai0 (hostart + ptrst[k], hostart, match);
-        }
-      break;
-    case ST_SMALL:
-      rev_sd_hontai0 (hopter + 4, hostart, match);
-      break;
-    }
+rev_sd_hontai0(UCHAR *hopter,
+	       UCHAR *hostart,
+	       int match)
+{
+	if (match) {
+		travel_next_nodes(hopter, hostart, match);
+		rev_sd_node(hopter, hostart, match);
+	} else {
+		rev_sd_node(hopter, hostart, match);
+		travel_next_nodes(hopter, hostart, match);
+	}
+}
+
+void
+rev_sd_hontai(UCHAR *hostart,
+	      int match)
+{
+	rev_sd_hontai0(hostart, hostart, match);
+}
+
+void
+travel_next_nodes(UCHAR *hopter,
+		  UCHAR *hostart,
+		  int match)
+{
+	int k;
+	int tsize;
+	w_char *charst;
+	w_char *sumst;
+	int *ptrst;
+
+	switch (*(unsigned short *)hopter) {
+	case ST_NORMAL:
+		tsize = *(w_char *)(hopter + 2);
+		charst = (w_char *)(hopter + 12);
+		sumst = ((w_char *)charst + tsize + 2);  /* + 2 keeps two zero words */
+		ptrst = (int *)((w_char *)sumst + tsize);
+
+		for (k = 0; k < tsize; k++) {
+			if (ptrst[k] != ENDPTR)
+				rev_sd_hontai0(hostart + ptrst[k], hostart, match);
+		}
+		break;
+
+	case ST_NOPTER:
+		break;
+	case ST_NOENT:
+		tsize = *(w_char *)(hopter + 2);
+		charst = (w_char *)(hopter + 4);
+		ptrst = (int *)AL_INT((w_char *)charst + tsize);
+
+		for (k = 0; k < tsize; k++)
+			rev_sd_hontai0(hostart + ptrst[k], hostart, match);
+		break;
+	case ST_SMALL:
+		rev_sd_hontai0(hopter + 4, hostart, match);
+		break;
+	}
 }
 
 #define rev_if_short(x) (match? rev_short_org(x): rev_short(x))
 #define rev_if_int(x) (match? rev_int_org(x): rev_int(x))
 
 void
-rev_sd_node (hopter, hostart, match)
-     UCHAR *hostart, *hopter;
-     int match;
-{
-  /* whether current state of dict matches the cpu type of the machine */
-  int k;
-  int tsize;
-  w_char *charst;
-  w_char *sumst;
-  int *ptrst;
-  int state;
-
-  state = rev_if_short ((unsigned short *) hopter);
-  switch (state)
-    {
-    case ST_NORMAL:
-    case ST_NOPTER:
-      tsize = rev_if_short ((w_char *) (hopter + 2));
-      rev_int ((int *) (hopter + 4));
-      rev_int ((int *) (hopter + 8));
-      charst = (w_char *) (hopter + 12);
-      sumst = ((w_char *) charst + tsize + 2);  /* + 2 keeps two zero words */
-      ptrst = (int *) ((w_char *) sumst + tsize);
-      for (k = 0; k < tsize; k++)
-        {
-          rev_short (charst + k);
-          rev_short (sumst + k);
-        }
-      if (state == ST_NORMAL)
-        {
-          for (k = 0; k < tsize; k++)
-            {
-              rev_int (ptrst + k);
-            }
-        }
-      break;
-    case ST_NOENT:
-      tsize = rev_if_short ((w_char *) (hopter + 2));
-      charst = (w_char *) (hopter + 4);
-      ptrst = (int *) AL_INT ((w_char *) charst + tsize);
-      for (k = 0; k < tsize; k++)
-        {
-          rev_short (charst + k);
-          rev_int (ptrst + k);
-        }
-      break;
-    case ST_SMALL:
-      rev_short ((unsigned short *) (hopter + 2));
-      break;
-    }
+rev_sd_node(UCHAR *hopter,
+	    UCHAR *hostart,
+	    int match)
+{
+	/* whether current state of dict matches the cpu type of the machine */
+	int k;
+	int tsize;
+	w_char *charst;
+	w_char *sumst;
+	int *ptrst;
+	int state;
+
+	state = rev_if_short((unsigned short *) hopter);
+
+	switch (state) {
+	case ST_NORMAL:
+	case ST_NOPTER:
+		tsize = rev_if_short((w_char *)(hopter + 2));
+		rev_int((int *)(hopter + 4));
+		rev_int((int *)(hopter + 8));
+		charst = (w_char *)(hopter + 12);
+		sumst = ((w_char *)charst + tsize + 2);  /* + 2 keeps two zero words */
+		ptrst = (int *)((w_char *)sumst + tsize);
+
+		for (k = 0; k < tsize; k++) {
+			rev_short(charst + k);
+			rev_short(sumst + k);
+		}
+
+		if (state == ST_NORMAL) {
+			for (k = 0; k < tsize; k++)
+				rev_int (ptrst + k);
+		}
+		break;
+
+	case ST_NOENT:
+		tsize = rev_if_short((w_char *)(hopter + 2));
+		charst = (w_char *)(hopter + 4);
+		ptrst = (int *)AL_INT((w_char *)charst + tsize);
+
+		for (k = 0; k < tsize; k++) {
+			rev_short(charst + k);
+			rev_int(ptrst + k);
+		}
+		break;
+
+	case ST_SMALL:
+		rev_short((unsigned short *)(hopter + 2));
+		break;
+	}
 }
 
-
 int
-little_endian ()
+little_endian()
 {
-  int a = 1;
+	int a = 1;
 #ifdef BYTE_SWAP
-  return (1);
+	return (1);
 #else
-  return (*(char *) &a == 1);
+	return (*(char *) &a == 1);
 #endif
 }
 
 void
-rev_rd_rind1 (ri1, maxri1, match)
-     struct rind1 *ri1;
-     int maxri1;
-     int match;
-{
-  int k;
-
-  for (k = 0; k < maxri1; k++)
-    {
-      rev_int (&(ri1[k].pter1));
-      rev_int (&(ri1[k].pter));
-    }
+rev_rd_rind1(struct rind1 *ri1,
+	     int maxri1,
+	     int match)
+{
+	int k;
+
+	for (k = 0; k < maxri1; k++) {
+		rev_int(&(ri1[k].pter1));
+		rev_int(&(ri1[k].pter));
+	}
 }
 
 void
-rev_rd_rind2 (ri2, maxri2, match)
-     struct rind2 *ri2;
-     int maxri2;
-     int match;
-{
-  int k;
-
-  for (k = 0; k < maxri2; k++)
-    {
-      rev_int (&(ri2[k].kanjipter));
-      rev_int (&(ri2[k].next[D_YOMI]));
-      rev_int (&(ri2[k].next[D_KANJI]));
-    }
+rev_rd_rind2(struct rind2 *ri2,
+	     int maxri2,
+	     int match)
+{
+	int k;
+
+	for (k = 0; k < maxri2; k++) {
+		rev_int(&(ri2[k].kanjipter));
+		rev_int(&(ri2[k].next[D_YOMI]));
+		rev_int(&(ri2[k].next[D_KANJI]));
+	}
 }
 
 void rev_w_char ();
 
 void
-rev_kanji (kpter, maxk, match)
-     UCHAR *kpter;
-     int maxk;
-     int match;
-{
-  UCHAR *kend = kpter + maxk;
-
-  while (kpter < kend && *kpter)
-    {
-      rev_w_char ((w_char *) (kpter + 2), *kpter / 2 - 1);
-      kpter += *kpter;
-    }
+rev_kanji(UCHAR *kpter,
+	  int maxk,
+	  int match)
+{
+	UCHAR *kend = kpter + maxk;
+
+	while (kpter < kend && *kpter) {
+		rev_w_char((w_char *)(kpter + 2), *kpter / 2 - 1);
+		kpter += *kpter;
+	}
 }
 
 void
-rev_w_char (p, maxp)
-     w_char *p;
-     int maxp;
-{
-  for (; maxp > 0; maxp--)
-    {
-      rev_short (p);
-      p++;
-    }
+rev_w_char(w_char *p,
+	   int maxp)
+{
+	for (; maxp > 0; maxp--) {
+		rev_short(p);
+		p++;
+	}
 }
 
 /*
@@ -357,87 +323,78 @@ rev_w_char (p, maxp)
  */
 
 int
-revdic (jtl, match)
-     struct JT *jtl;
-     int match;
-{
-  extern int rev_ud (), rev_rd (), rev_sd ();
-  int syurui = jtl->syurui;
-
-  syurui = jtl->syurui & 0xff;
-
-  if (syurui == WNN_UD_DICT)
-    {
-      if (rev_ud (jtl, match) == -1)
-        return (-1);
-    }
-  else if (syurui == WNN_REV_DICT)
-    {
-      if (rev_rd (jtl, match) == -1)
-        return (-1);
-    }
-  else
-    {
-      if (rev_sd (jtl, match) == -1)
-        return (-1);
-    }
-  return (0);
+revdic(struct JT *jtl,
+       int match)
+{
+	extern int rev_ud(), rev_rd(), rev_sd();
+	int syurui = jtl->syurui;
+
+	syurui = jtl->syurui & 0xff;
+
+	if (syurui == WNN_UD_DICT) {
+		if (rev_ud (jtl, match) == -1)
+			return (-1);
+	} else if (syurui == WNN_REV_DICT) {
+		if (rev_rd (jtl, match) == -1)
+			return (-1);
+	} else {
+		if (rev_sd (jtl, match) == -1)
+			return (-1);
+	}
+
+	return (0);
 }
 
 void rev_common ();
 
 int
-rev_ud (jtl, match)
-     struct JT *jtl;
-     int match;
-{
-  rev_common (jtl, match);
-  rev_ud_hontai (jtl->hontai, jtl->maxhontai, match);
-  rev_ud_table (jtl->table, jtl->maxtable, match);
-  return (0);
+rev_ud(struct JT *jtl,
+       int match)
+{
+	rev_common(jtl, match);
+	rev_ud_hontai(jtl->hontai, jtl->maxhontai, match);
+	rev_ud_table(jtl->table, jtl->maxtable, match);
+
+	return (0);
 }
 
 int
-rev_sd (jtl, match)
-     struct JT *jtl;
-     int match;
-{
-  rev_common (jtl, match);
-  rev_sd_hontai (jtl->hontai, match);
-  return (0);
+rev_sd(struct JT *jtl,
+       int match)
+{
+	rev_common(jtl, match);
+	rev_sd_hontai(jtl->hontai, match);
+	return (0);
 }
 
 int
-rev_rd (jtl, match)
-     struct JT *jtl;
-     int match;
-{
-  rev_common (jtl, match);
-  rev_rd_rind1 (jtl->ri1[D_YOMI], jtl->maxri1[D_YOMI], match);
-  rev_rd_rind1 (jtl->ri1[D_KANJI], jtl->maxri1[D_KANJI], match);
-  rev_rd_rind2 (jtl->ri2, jtl->maxri2, match);
-  return (0);
+rev_rd(struct JT *jtl,
+       int match)
+{
+	rev_common(jtl, match);
+	rev_rd_rind1(jtl->ri1[D_YOMI], jtl->maxri1[D_YOMI], match);
+	rev_rd_rind1(jtl->ri1[D_KANJI], jtl->maxri1[D_KANJI], match);
+	rev_rd_rind2(jtl->ri2, jtl->maxri2, match);
+	return (0);
 }
 
 void
-rev_common (jtl, match)
-     struct JT *jtl;
-     int match;
-{
-  if (jtl->hinsi)
-    rev_hinsi (jtl->hinsi, jtl->maxserial, match);
-  if (jtl->kanji)
-    rev_kanji (jtl->kanji, jtl->maxkanji, match);
-  if (jtl->comment)
-    rev_w_char (jtl->comment, jtl->maxcomment);
-  if (jtl->hinsi_list)
-    rev_w_char (jtl->hinsi_list, jtl->maxhinsi_list);
+rev_common(struct JT *jtl,
+	   int match)
+{
+	if (jtl->hinsi)
+		rev_hinsi(jtl->hinsi, jtl->maxserial, match);
+	if (jtl->kanji)
+		rev_kanji(jtl->kanji, jtl->maxkanji, match);
+	if (jtl->comment)
+		rev_w_char(jtl->comment, jtl->maxcomment);
+	if (jtl->hinsi_list)
+		rev_w_char(jtl->hinsi_list, jtl->maxhinsi_list);
 }
 
 /* rev_short is called from atod.c.... kanapiiii */
 void
-rev_short_fun (sp)
-     w_char *sp;
+rev_short_fun(w_char *sp)
 {
-  rev_short (sp);
+	rev_short (sp);
 }
