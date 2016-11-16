--- READMEJP.md.old	2016-10-05 08:08:44.857462000 +0900
+++ READMEJP.md	2016-10-05 08:11:34.862781000 +0900
@@ -28,11 +28,11 @@
 
 ## インストール前の注意
 
-1. 添付の makeskkcdb.sh を実行する．このスクリプトでは辞書ファイルは skktocdbm.sh の標準入力に与える． ファイル名の既定値は /usr/local/share/skk/SKK-JISYO.L である．実行するとカレントディレクトリに SKK-JISYO.L.cdb が作られる．この辞書ファイルはインストールの際 dbskkd-cdb.c 中の JISYO\_FILE で指定するディレクトリに置く．JISYO\_FILE の既定値は /usr/local/share/skk/SKK-JISYO.L.cdb である． 注意: 1.x ではこのマクロは `JISHO_FILE` と定義していたが，辞書ファイルとの名前の整合性を取るためにこのようにした．
+1. 添付の makeskkcdb.sh を実行する．このスクリプトでは辞書ファイルは skktocdbm.sh の標準入力に与える． ファイル名の既定値は `%%PREFIX%%/%%SKKDIR%%/%%JISYONAME%%` である．実行するとカレントディレクトリに `%%JISYONAME%%.cdb` が作られる．この辞書ファイルはインストールの際 dbskkd-cdb.c 中の JISYO\_FILE で指定するディレクトリに置く．JISYO\_FILE の既定値は `%%PREFIX%%/%%SKKDIR%%/%%JISYONAME%%.cdb` である． 注意: 1.x ではこのマクロは `JISHO_FILE` と定義していたが，辞書ファイルとの名前の整合性を取るためにこのようにした．
 
 2. 実行ファイル dbskkd-cdb をコンパイルするため make する． この際 TinyCDB 中の cdb.h が必要となる． また TinyCDB 中の libcdb.a をリンクする．
 
-3. make install で dbskkd-cdb を実行ディレクトリにコピーする．既定値では /usr/local/libexec へコピーする．
+3. make install で dbskkd-cdb を実行ディレクトリにコピーする．既定値では `%%PREFIX%%/libexec` へコピーする．
 
 ## インストールの際の注意
 
