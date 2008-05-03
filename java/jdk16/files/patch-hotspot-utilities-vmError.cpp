$FreeBSD: /tmp/pcvs/ports/java/jdk16/files/patch-hotspot-utilities-vmError.cpp,v 1.1 2008-05-03 15:49:27 glewis Exp $

--- ../../hotspot/src/share/vm/utilities/vmError.cpp.orig	2008-04-12 13:56:26.000000000 +0300
+++ ../../hotspot/src/share/vm/utilities/vmError.cpp	2008-04-12 14:26:42.728926827 +0300
@@ -269,7 +269,7 @@
          st->print("# java.lang.OutOfMemoryError: ");
          if (_size) {
            st->print("requested ");
-           sprintf(buf,"%ld",_size);
+           sprintf(buf,"%zu",_size);
            st->print(buf);
            st->print(" bytes");
            if (_message != NULL) {
