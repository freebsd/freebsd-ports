
$FreeBSD: /tmp/pcvs/ports/java/kaffe/files/Attic/patch-kaffe_kaffevm_jit3_labels.c,v 1.1 2005-01-10 11:04:50 edwin Exp $

--- kaffe/kaffevm/jit3/labels.c.orig
+++ kaffe/kaffevm/jit3/labels.c
@@ -217,6 +217,7 @@
 #endif
 			ABORT();
 #endif
+			break;
 		}
 #if 0
 		/*
