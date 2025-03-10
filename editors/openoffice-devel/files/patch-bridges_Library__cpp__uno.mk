--- bridges/Library_cpp_uno.mk.orig
+++ bridges/Library_cpp_uno.mk
@@ -131,6 +131,10 @@
         bridges/source/cpp_uno/gcc3_freebsd_powerpc64/uno2cpp \
 ))
 
+$(eval $(call gb_Library_add_asmobjects,$(COMNAME)_uno,\
+		bridges/source/cpp_uno/gcc3_freebsd_powerpc64/call \
+))
+
 $(eval $(call gb_LinkTarget_set_cxx_optimization, \
         bridges/source/cpp_uno/gcc3_freebsd_powerpc64/cpp2uno \
         bridges/source/cpp_uno/gcc3_freebsd_powerpc64/uno2cpp \

