--- ../connectivity/source/drivers/mozab/mozillasrc/makefile.mk.orig	Tue Apr 15 19:39:14 2003
+++ ../connectivity/source/drivers/mozab/mozillasrc/makefile.mk	Sat May 31 22:34:31 2003
@@ -64,8 +64,8 @@
 #mozilla specific stuff.
 MOZ_LIB=$(SOLARVERSION)$/$(INPATH)$/lib$(UPDMINOREXT)
 MOZ_INC=$(SOLARVERSION)$/$(INPATH)$/inc$(UPDMINOREXT)$/mozilla
-#MOZ_LIB=$(PRJ)$/$(INPATH)$/lib
-#MOZ_INC=$(PRJ)$/$(INPATH)$/inc$/mozilla
+#MOZ_LIB=$(PRJ)$/..$/moz$/$(INPATH)$/lib
+#MOZ_INC=$(PRJ)$/..$/moz$/$(INPATH)$/inc$/mozilla
 #End of mozilla specific stuff.
 
 PRJ=..$/..$/..$/..
@@ -132,7 +132,7 @@
 	    -I$(MOZ_INC)$/addrbook -I$(MOZ_INC)$/mork -I$(MOZ_INC)$/locale \
 	    -I$(MOZ_INC)$/pref -I$(MOZ_INC)$/mime -I$(MOZ_INC)$/chrome \
 	    -I$(MOZ_INC)$/necko -I$(MOZ_INC)$/intl -I$(MOZ_INC)$/profile \
-	    -I$(MOZ_INC)$/embed_base -I$(MOZ_INC)$/mozldap
+	    -I$(MOZ_INC)$/embed_base -I$(MOZ_INC)$/mozldap -I$(MOZ_INC)$/ldap-nspr
 CDEFS +=    -DWINVER=0x400 -DMOZILLA_CLIENT \
 	    -DNS_NET_FILE -DCookieManagement -DSingleSignon -DClientWallet \
             -DTRACING -DXP_PC -DXP_WIN -DXP_WIN32 -DHW_THREADS \
@@ -150,7 +150,7 @@
 	    -I$(MOZ_INC)$/addrbook -I$(MOZ_INC)$/mork -I$(MOZ_INC)$/locale \
 	    -I$(MOZ_INC)$/pref -I$(MOZ_INC)$/mime -I$(MOZ_INC)$/chrome \
 	    -I$(MOZ_INC)$/necko -I$(MOZ_INC)$/intl -I$(MOZ_INC)$/profile \
-	    -I$(MOZ_INC)$/embed_base -I$(MOZ_INC)$/mozldap
+	    -I$(MOZ_INC)$/embed_base -I$(MOZ_INC)$/mozldap -I$(MOZ_INC)$/ldap-nspr
 CDEFS+=	    -DMOZILLA_CLIENT \
             -DOSTYPE=\"Linux2.2.14-5\" -DOJI
 .IF "$(OS)" == "LINUX"
@@ -166,6 +166,13 @@
             -fno-rtti -Wall -Wconversion -Wpointer-arith \
             -Wbad-function-cast -Wcast-align -Woverloaded-virtual -Wsynth \
             -Wno-long-long
+CDEFS     += -DTRACING
+.ELIF "$(OS)" == "FREEBSD"
+CFLAGS +=   -fPIC
+CFLAGSCXX += \
+            -fno-rtti -Wall -Wconversion -Wpointer-arith \
+            -Wbad-function-cast -Wcast-align -Woverloaded-virtual -Wsynth \
+            -Wno-long-long -pthread
 CDEFS     += -DTRACING
 .ENDIF
 .ENDIF
