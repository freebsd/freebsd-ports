--- makeskkcdb.sh.dist	2009-02-06 11:56:47.000000000 +0900
+++ makeskkcdb.sh	2009-02-11 01:34:16.000000000 +0900
@@ -1,3 +1,3 @@
 #!/bin/sh
-./skktocdbm.sh < /usr/local/share/skk/SKK-JISYO.L | \
-	cdb -c -t - SKK-JISYO.L.cdb
+./skktocdbm.sh < %%PREFIX%%/%%SKKDIR%%/%%JISYONAME%% | \
+	cdb -c -t - %%JISYONAME%%.cdb
