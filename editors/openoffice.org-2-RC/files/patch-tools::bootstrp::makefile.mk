--- ../tools/bootstrp/makefile.mk.orig	Tue Jan  1 14:12:19 2002
+++ ../tools/bootstrp/makefile.mk
@@ -83,6 +83,15 @@
 	@echo No bootstrp for Mac OS
 .ELSE	# "$(OS)"=="MACOS"
 
+.IF "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
+ALLTAR2: $(LB)$/libgcc_pic.a $(LB)$/libgcc.a ALLTAR 
+	@echo ""
+$(LB)$/libgcc_pic.a:
+	-objcopy -L set_new_handler__FPFv_v /usr/lib/libgcc_pic.a $(LB)$/libgcc_pic.a
+$(LB)$/libgcc.a:
+	objcopy -L set_new_handler__FPFv_v `gcc -print-libgcc-file-name` $(LB)$/libgcc.a
+.ENDIF
+
 OBJFILES=                       \
 	$(OBJ)$/sstring.obj     \
 	$(OBJ)$/appdef.obj      \
@@ -172,3 +181,4 @@
 # --- Targets ------------------------------------------------------
 
 .INCLUDE :  target.mk
+
