--- bridges/source/cpp_uno/gcc3_freebsd_powerpc64/makefile.mk
+++ bridges/source/cpp_uno/gcc3_freebsd_powerpc64/makefile.mk
@@ -53,7 +53,8 @@
 SLOFILES= \
 	$(SLO)$/except.obj		\
 	$(SLO)$/cpp2uno.obj		\
-	$(SLO)$/uno2cpp.obj
+	$(SLO)$/uno2cpp.obj		\
+	$(SLO)$/call.obj
 
 SHL1TARGET= $(TARGET)
 
@@ -73,3 +74,7 @@
 # --- Targets ------------------------------------------------------
 
 .INCLUDE :  target.mk
+
+$(SLO)$/%.obj: %.s
+    $(CC) -c -o $(SLO)$/$(@:b).o $<
+    touch $@

