--- ti-pru.c.orig	2015-08-19 15:27:54.000000000 -0700
+++ ti-pru.c	2020-09-22 12:58:50.636444000 -0700
@@ -502,7 +502,7 @@
 	case TI_OP_MVI:
 		ti_reg_str(op3, c_op3, sizeof(c_op3));
 		ti_reg_str(op2, c_op2, sizeof(c_op2));
-		memmove(c_op2 + 1, c_op2, sizeof(c_op2));
+		memmove(c_op2 + 1, c_op2, sizeof(c_op2)-1);
 		c_op2[0] = '*';
 		break;
 	case TI_OP_JMP:
