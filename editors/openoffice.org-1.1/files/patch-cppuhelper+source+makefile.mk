--- ../cppuhelper/source/makefile.mk.orig	Thu Mar  7 16:37:48 2002
+++ ../cppuhelper/source/makefile.mk	Thu Mar  7 16:37:55 2002
@@ -149,8 +149,8 @@
 SHL1TARGET=$(TARGET)$(UDK_MAJOR)$(COMID)
 
 SHL1STDLIBS= \
-		$(CPPULIB)		\
-		$(SALLIB)
+		$(SALLIB)		\
+		$(CPPULIB)
 
 SHL1DEPN=
 SHL1IMPLIB=i$(TARGET)
@@ -173,6 +173,10 @@
 SHL1VERSIONMAP=gcc2_linux_intel.map
 .ELIF "$(OS)$(CPU)$(COMNAME)"=="LINUXIgcc3"
 SHL1VERSIONMAP=gcc3_linux_intel.map
+.ELIF "$(OS)$(CPU)$(COMNAME)"=="FREEBSDIgcc2"
+#SHL1VERSIONMAP=gcc2_freebsd_intel.map
+.ELIF "$(OS)$(CPU)$(COMNAME)"=="FREEBSDIgcc3"
+#SHL1VERSIONMAP=gcc3_freebsd_intel.map
 .ENDIF
 
 # --- Targets ------------------------------------------------------
