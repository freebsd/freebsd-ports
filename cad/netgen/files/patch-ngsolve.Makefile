--- ngsolve/Makefile.orig	Tue Nov 16 10:14:27 2004
+++ ngsolve/Makefile	Wed Nov 17 23:18:39 2004
@@ -89,14 +89,14 @@
 pebblesinc = -I../../pebbles_old/libsrc/setup -I../../pebbles_old/libsrc/solver -I../../pebbles_old/libsrc/prepro -I../../pebbles_old/libsrc/parallel -I../../pebbles_old/libsrc
 # 
 $(lib):: $(src)
-	$(CPLUSPLUS) -c -I. -I../libsrc -I../libsrc/include -I../libsrc/interface -Iinclude $(pebblesinc) $(CPLUSPLUSFLAGS2) -DNETGEN_ELTRANS $? 
+	$(CPLUSPLUS) -c -I. -I../libsrc -I../libsrc/include -I../libsrc/interface -Iinclude $(pebblesinc) $(CPLUSPLUSFLAGS2) $(CPLUSPLUSFLAGS3) -DNETGEN_ELTRANS $? 
 	$(AR) $(ARFLAGS) $@ *.o
 	mv *.o ../lib/$(MACHINE)
 	-$(RM) *.o
 	-@$(RANLIB) $@
 #
 $(lib2):: $(src2) 
-	$(CPLUSPLUS) -c -I. -I../libsrc/interface -Iinclude $(CPLUSPLUSFLAGS2) $?
+	$(CPLUSPLUS) -c -I. -I../libsrc/interface -Iinclude $(CPLUSPLUSFLAGS2) $(CPLUSPLUSFLAGS3) $?
 	$(AR) $(ARFLAGS) $@ *.o
 	-$(RM) *.o
 	-@$(RANLIB) $@
