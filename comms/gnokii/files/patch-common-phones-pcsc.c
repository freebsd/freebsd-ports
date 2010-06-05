--- common/phones/pcsc.c.orig	2010-06-04 15:08:13.000466080 +0200
+++ common/phones/pcsc.c	2010-06-04 15:15:44.926057193 +0200
@@ -199,7 +199,9 @@
 	case SCARD_W_UNPOWERED_CARD:
 	case SCARD_W_RESET_CARD:
 	case SCARD_W_REMOVED_CARD:
+/* removed from pcsc-lite
 	case SCARD_W_INSERTED_CARD:
+*/
 	 	return GN_ERR_SIMPROBLEM;
 	case SCARD_E_NO_MEMORY:
 		return GN_ERR_MEMORYFULL;
