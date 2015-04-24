--- ByteLoader/bytecode.h.orig	2014-08-21 22:13:08 UTC
+++ ByteLoader/bytecode.h
@@ -785,13 +785,21 @@ static int bget_swab = 0;
 	    padl = (SV*)pad_new(arg);			\
 	    BSET_OBJ_STOREX(padl);			\
 	} STMT_END
-#if (PERL_VERSION >= 19) || ( PERL_VERSION == 19 && PERL_SUBVERSION > 3)
+/* PADNAMELIST now a valid lvalue: v5.21.6-197-g0f94cb1 */
+#if (PERL_VERSION >= 22) || ( PERL_VERSION == 21 && PERL_SUBVERSION > 5)
+#define BSET_padl_name(padl, pad)                \
+    PadlistARRAY((PADLIST*)padl)[0] = (PAD*)pad; \
+    PadnamelistMAXNAMED((PADNAMELIST*)pad) = AvFILL((AV*)pad)
+#else
+/* extra PADNAMELIST: v5.17.3-49-g36c300b */
+#if (PERL_VERSION >= 18) || ( PERL_VERSION == 17 && PERL_SUBVERSION > 3)
 #define BSET_padl_name(padl, pad)                \
     PadlistARRAY((PADLIST*)padl)[0] = (PAD*)pad; \
     PadnamelistMAXNAMED((PAD*)pad) = AvFILL((AV*)pad)
 #else
 #define BSET_padl_name(padl, pad)  PadlistARRAY((PADLIST*)padl)[0] = (PAD*)pad
 #endif
+#endif
 #define BSET_padl_sym(padl, pad)   PadlistARRAY((PADLIST*)padl)[1] = (PAD*)pad
 #define BSET_xcv_name_hek(cv, arg)                                      \
   STMT_START {                                                          \
