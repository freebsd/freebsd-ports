--- ports/unix/install.sh.orig	Sun Sep 28 03:46:54 2003
+++ ports/unix/install.sh	Sun Sep 28 03:47:48 2003
@@ -15,7 +15,7 @@
 	echo "that supports shell functions."
 	echo
 	echo "On your system, you may try one out of these shells:"
-	for p in /bin /usr/bin /usr/local/bin; do
+	for p in /bin /usr/bin ${LOCALBASE}/bin; do
 		for s in ksh bash; do
 			if [ -f $p/$s ]; then echo $p/$s; fi
 		done
@@ -98,7 +98,7 @@
 	strip tools/sdfmt
 fi
 
-rm -f /usr/local/bin/tide /usr/local/bin/sdfmt
+rm -f ${PREFIX}/bin/tide ${PREFIX}/bin/sdfmt
 
 (cd classes;
  txcm -i config
@@ -146,9 +146,9 @@
 install -o bin -g bin -C -m 0644 docs/Changes.sd $T3XDIR/doc/tool-changes.sd
 
 if [ $SYMLINK = yes ]; then
-	ln -fs $T3XDIR/tide/tide /usr/local/bin/tide
-	ln -fs $T3XDIR/bin/sdfmt /usr/local/bin/sdfmt
+	ln -fs $T3XDIR/tide/tide ${PREFIX}/bin/tide
+	ln -fs $T3XDIR/bin/sdfmt ${PREFIX}/bin/sdfmt
 else
-	binlink $T3XDIR/tide/tide /usr/local/bin/tide
-	binlink $T3XDIR/bin/sdfmt /usr/local/bin/sdfmt
+	binlink $T3XDIR/tide/tide ${PREFIX}/bin/tide
+	binlink $T3XDIR/bin/sdfmt ${PREFIX}/bin/sdfmt
 fi
