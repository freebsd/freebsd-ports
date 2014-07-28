--- configure.h.orig	Fri Dec 18 21:55:05 1998
+++ configure.h	Thu Feb 25 10:31:24 1999
@@ -11,10 +11,10 @@
  */
 
 /* インストールディレクトリ */
-#define INSTALLDIR ${HOME}/bin
+#define INSTALLDIR ${PREFIX}/bin
 
 /* デフォルトデータをインストールする場所 */
-#define DATADIR ${HOME}/share/mindfocus
+#define DATADIR ${PREFIX}/share/examples/mindfocus
 
 /* 個人環境保存ファイル(設定ファイル)の名前 */
 #define DOTFILENAME ".mindfocus"
@@ -32,7 +32,7 @@
 
 /* XPMフォーマットに対応させるときは定義する。今のところ事実上必須。 */
 #define XPM
-#define XPMLIBRARY -L/usr/local/X11R6/lib -lXpm
+#define XPMLIBRARY -L${PREFIX}/lib -lXpm
 
 
 /*
