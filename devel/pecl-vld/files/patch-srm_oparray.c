--- srm_oparray.c.orig	Mon Mar  5 00:55:20 2007
+++ srm_oparray.c	Mon Mar  5 00:55:20 2007
@@ -350,7 +350,8 @@
 			op->op2.u.opline_num = (zend_uint)((zend_op*)base_address + op->op2.u.opline_num);
 			op->op2.op_type = VLD_IS_OPLINE;
 			break;
-
+/* use ZEND_JMP_NO_CTOR only when it is available (php < 5.1) */
+#ifdef ZEND_JMP_NO_CTOR
 		case ZEND_JMP_NO_CTOR:
 			flags = OP2_USED;
 			if (op->op1.op_type != IS_UNUSED) {
@@ -361,6 +362,7 @@
 #endif
 			op->op2.op_type = VLD_IS_OPLINE;
 			break;
+#endif
 
 #ifdef ZEND_ENGINE_2
 		case ZEND_FETCH_CLASS:
