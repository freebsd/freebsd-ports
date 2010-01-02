Index: Wnn/conv/cvt_head.h
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/conv/cvt_head.h,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- Wnn/conv/cvt_head.h	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/conv/cvt_head.h	20 Dec 2008 15:22:37 -0000	1.2
@@ -52,17 +52,17 @@
 
 #ifdef WNNDEFAULT
 #  include "wnn_config.h"
- /* マクロCONVERT_FILENAMEの定義（のためだけ）。コンパイル時は、ヘッダファイル
-    のサーチパスに、Wnnのインクルードファイルのありかを設定しておくこと。 */
+/* マクロCONVERT_FILENAMEの定義（のためだけ）。コンパイル時は、ヘッダファイル
+   のサーチパスに、Wnnのインクルードファイルのありかを設定しておくこと。 */
 #else
 #  define CONVERT_FILENAME "cvt_key_tbl"
 #endif
 
 #define div_up(a, b) ((a + b - 1) / b)
- /* a,bは非負整数。a/bを切り上げて整数にする */
+/* a,bは非負整数。a/bを切り上げて整数にする */
 
 struct CONVCODE
 {
-  int tokey;                    /* 変換されたコード */
-  char *fromkey;                /* 変換するコード */
+	int tokey;	/* 変換されたコード */
+	char *fromkey;	/* 変換するコード */
 };
