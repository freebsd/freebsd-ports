
$FreeBSD$

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
