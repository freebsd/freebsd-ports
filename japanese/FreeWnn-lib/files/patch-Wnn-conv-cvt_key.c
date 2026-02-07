Index: Wnn/conv/cvt_key.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/conv/cvt_key.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- Wnn/conv/cvt_key.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/conv/cvt_key.c	20 Dec 2008 15:22:37 -0000	1.2
@@ -65,172 +65,165 @@
 extern struct CONVCODE tbl[];
 extern int cnv_tbl_cnt;         /* convert table count */
 
-
- /** intの配列 h をビットベクタとみなし、第iビットをチェックあるいは立てる */
+/** intの配列 h をビットベクタとみなし、第iビットをチェックあるいは立てる */
 #define BITONP(h, i) (h[i / BITSIZ] &  (1 << (i % BITSIZ)))
 #define BITOFP(h, i) (!BITONP(h, i))
 #define BIT_UP(h, i) (h[i / BITSIZ] |= (1 << (i % BITSIZ)))
 #define BITDWN(h, i) (h[i / BITSIZ] &= ~(1 << (i % BITSIZ)))
 
- /** 変換コードのチェックとコード変換 */
+/** 変換コードのチェックとコード変換 */
 int
-key_check (inbuf, conv_tbl, tbl_cnt, check_flg)
-     int inbuf[];               /* ソースストリング */
-     struct CONVCODE conv_tbl[];        /* コード変換テーブル */
-     int tbl_cnt;
-     int check_flg[];
+key_check (int inbuf[],			/* ソースストリング */
+	   struct CONVCODE conv_tbl[],	/* コード変換テーブル */
+	   int tbl_cnt,
+	   int check_flg[])
 {
-  int dist, base;
-  char *code_p;
-  int i;
-
-  for (base = 0; inbuf[base] != -1; base++)
-    {
-      for (dist = 0; dist < tbl_cnt; dist++)
-        {
-          if (BITONP (check_flg, dist) && conv_tbl[dist].fromkey != 0)
-            {
-              code_p = conv_tbl[dist].fromkey + base;
-              if (*code_p == (char) inbuf[base])
-                {
-                  if (*(code_p + 1) == (char) 0)
-                    {
-                      /* マッチした */
-                      for (i = 0, base++; (inbuf[i] = inbuf[base]) != -1; i++, base++);
-                      return (conv_tbl[dist].tokey);
-                    }
-                  /* まだマッチしていない */
-                }
-              else
-                {
-                  BITDWN (check_flg, dist);     /* 無効 */
-                }
-            }
-        }
-    }
-
-  /* ビットベクタ check_flg[] の第0〜tblcntビットに立ったまま残っている
-     ものがあるか調べる。 */
-  for (i = 0; i < tbl_cnt / BITSIZ; i++)
-    {
-      if (check_flg[i])
-        return (-1);
-    }
-  if ((tbl_cnt %= BITSIZ) && (check_flg[i] & ~(~0 << tbl_cnt)))
-    return (-1);
-  /* return -1 … まだ未決定の物がある */
+	int dist, base;
+	char *code_p;
+	int i;
+
+	for (base = 0; inbuf[base] != -1; base++) {
+		for (dist = 0; dist < tbl_cnt; dist++) {
+			if (BITONP (check_flg, dist) && conv_tbl[dist].fromkey != 0) {
+				code_p = conv_tbl[dist].fromkey + base;
+
+				if (*code_p == (char) inbuf[base]) {
+					if (*(code_p + 1) == (char) 0) {
+						/* マッチした */
+						for (i = 0, base++; (inbuf[i] = inbuf[base]) != -1; i++, base++);
+						return (conv_tbl[dist].tokey);
+					}
+					/* まだマッチしていない */
+				} else {
+					/* 無効 */
+					BITDWN (check_flg, dist);
+				}
+			}
+		}
+	}
+
+	/* ビットベクタ check_flg[] の第0〜tblcntビットに立ったまま残っている
+	   ものがあるか調べる。 */
+
+	for (i = 0; i < tbl_cnt / BITSIZ; i++) {
+		if (check_flg[i])
+			return (-1);
+	}
+
+	if ((tbl_cnt %= BITSIZ) && (check_flg[i] & ~(~0 << tbl_cnt)))
+		return (-1);
+	/* return -1 … まだ未決定の物がある */
 
-  return (-2);                  /* 変換対象となる物はない */
+	/* 変換対象となる物はない */
+	return (-2);
 }
 
- /** 指定された変換テーブルに従ってコード変換する。*/
+/** 指定された変換テーブルに従ってコード変換する。*/
 int
-convert_key (inkey, conv_tbl, tbl_cnt, matching_flg, in_buf)
-     int (*inkey) ();           /* キー入力関数 */
-     struct CONVCODE conv_tbl[];        /* 変換テーブル */
-     int tbl_cnt;               /* conv_tbl[] の個数 */
-     int matching_flg;          /* マッチングしなかったストリングの処理指定
-                                   0 : 返値として返す
-                                   1 : そのストリングは捨てる   */
-     char *in_buf;
+convert_key (int (*inkey)(),		/* キー入力関数 */
+	     struct CONVCODE conv_tbl[],	/* 変換テーブル */
+	     int tbl_cnt,		/* conv_tbl[] の個数 */
+	     int matching_flg,       /* マッチングしなかったストリングの処理指定
+					0 : 返値として返す
+					1 : そのストリングは捨てる   */
+	     char *in_buf)
 {
 #define MAX     20              /* キー入力バッファの最大値 */
 
-  static int inbuf[MAX];        /* キー入力バッファ */
-  /* バッファの終端は、-1 で示される。 */
-
-  int out_cnt;                  /* 出力バッファの出力カウント */
-
-  static int buf_cnt = 0;       /* inbuf の入力時のカウンタ   */
-
-  int check_flg[CHANGE_MAX];
-  /* ビットベクタとして扱われ、マッチング時に対象となっているconv_tbl[]
-     を示す。1の時対象となり、0で非対象 */
-
-  int i, c, flg = 0;            /* work */
-
-  for (i = 0; i < div_up (tbl_cnt, BITSIZ); check_flg[i++] = ~0);
-  /* 配列check_flgをビットベクタ扱いし、その第0〜tbl_cnt ビットを立てる。
-     但し、実際はその少し先まで立つ */
-
-  for (;;)
-    {
-      if (flg != 0 || buf_cnt == 0)
-        {
-          inbuf[buf_cnt] = (*inkey) (); /* 一文字入力 */
-          in_buf[buf_cnt] = (char) (inbuf[buf_cnt] & 0xff);
-          if (inbuf[buf_cnt] == -1)
-            {
-              if (buf_cnt > 0)
-                {
-                  c = -2;       /* タイムアウト */
-                  goto LABEL;
-                }
-              else
-                {
-                  continue;
-                }
-            }
-          else
-            {
-              inbuf[++buf_cnt] = -1;    /* ターミネータ */
-            }
-        }
-      flg++;
-
-      if (buf_cnt >= MAX - 1)
-        {
-          in_buf[0] = '\0';
-          return (-1);          /* ERROR */
-        }
-
-      c = key_check (inbuf, conv_tbl, tbl_cnt, check_flg);
-    LABEL:
-      switch (c)
-        {
-        case -1:                /* 未決定 */
-          continue;
-
-        case -2:                /* 変換対象でないことが決定した */
-          buf_cnt--;
-          out_cnt = 0;
-          c = inbuf[out_cnt++];
-          for (i = 0; inbuf[i] != -1; inbuf[i++] = inbuf[out_cnt++]);
-          if (matching_flg != 0)
-            {
-              flg = 0;
-              continue;
-            }
-          in_buf[0] = '\0';
-          return (c);
-
-        default:                /* 変換されたコード */
-          in_buf[buf_cnt] = '\0';
-          buf_cnt = 0;
-          return (c);
-        }
-    }
+        /* キー入力バッファ */
+	/* バッファの終端は、-1 で示される。 */
+	static int inbuf[MAX];
+
+	/* 出力バッファの出力カウント */
+	int out_cnt;
+	
+	/* inbuf の入力時のカウンタ   */
+	static int buf_cnt = 0;
+
+
+	/* ビットベクタとして扱われ、マッチング時に対象となっているconv_tbl[]
+	   を示す。1の時対象となり、0で非対象 */
+	int check_flg[CHANGE_MAX];
+
+	/* work */
+	int i, c, flg = 0;
+
+	for (i = 0; i < div_up (tbl_cnt, BITSIZ); check_flg[i++] = ~0);
+	/* 配列check_flgをビットベクタ扱いし、その第0〜tbl_cnt ビットを立てる。
+	   但し、実際はその少し先まで立つ */
+
+	for (;;) {
+		if (flg != 0 || buf_cnt == 0) {
+			inbuf[buf_cnt] = (*inkey) (); /* 一文字入力 */
+			in_buf[buf_cnt] = (char) (inbuf[buf_cnt] & 0xff);
+			if (inbuf[buf_cnt] == -1) {
+				if (buf_cnt > 0) {
+					c = -2;
+					/* タイムアウト */
+					goto LABEL;
+				} else {
+					continue;
+				}
+			} else {
+				/* ターミネータ */
+				inbuf[++buf_cnt] = -1;
+			}
+		}
+		flg++;
+
+		if (buf_cnt >= MAX - 1) {
+			in_buf[0] = '\0';
+
+			/* ERROR */
+			return (-1);
+		}
+
+		c = key_check (inbuf, conv_tbl, tbl_cnt, check_flg);
+
+	LABEL:
+		switch (c) {
+		case -1:
+			/* 未決定 */
+			continue;
+
+		case -2:
+			/* 変換対象でないことが決定した */
+			buf_cnt--;
+			out_cnt = 0;
+			c = inbuf[out_cnt++];
+			for (i = 0; inbuf[i] != -1; inbuf[i++] = inbuf[out_cnt++]);
+
+			if (matching_flg != 0) {
+				flg = 0;
+				continue;
+			}
+
+			in_buf[0] = '\0';
+			return (c);
+
+		default:
+			/* 変換されたコード */
+			in_buf[buf_cnt] = '\0';
+			buf_cnt = 0;
+			return (c);
+		}
+	}
 }
 
  /** コード変換を伴うキー入力関数 */
 int
-keyin1 (get_ch, in_buf)
-     int (*get_ch) ();          /* getchar() と同様の関数 */
-     char *in_buf;
+keyin1(int (*get_ch)(),          /* getchar() と同様の関数 */
+       char *in_buf)
 {
-  int ret;
+	int ret;
 
-  for (;;)
-    {
-      if (cnv_tbl_cnt == 0)
-        {
-          ret = (*get_ch) ();
-          if (ret >= 0)
-            return (ret);
-        }
-      else
-        {
-          return (convert_key (get_ch, tbl, cnv_tbl_cnt, 0, in_buf));
-        }
-    }
+	for (;;) {
+		if (cnv_tbl_cnt == 0) {
+			ret = (*get_ch)();
+			if (ret >= 0)
+				return (ret);
+		} else {
+			return (convert_key(get_ch, tbl, cnv_tbl_cnt, 0, in_buf));
+		}
+	}
 }
