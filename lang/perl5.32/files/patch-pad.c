--- pad.c.orig	2020-12-18 10:04:36 UTC
+++ pad.c
@@ -162,9 +162,9 @@ Perl_set_padlist(CV * cv, PADLIST *padlist){
 void
 Perl_set_padlist(CV * cv, PADLIST *padlist){
     PERL_ARGS_ASSERT_SET_PADLIST;
-#  if PTRSIZE == 8
+#  if PTRADDRSIZE == 8
     assert((Size_t)padlist != UINT64_C(0xEFEFEFEFEFEFEFEF));
-#  elif PTRSIZE == 4
+#  elif PTRADDRSIZE == 4
     assert((Size_t)padlist != 0xEFEFEFEF);
 #  else
 #    error unknown pointer size
