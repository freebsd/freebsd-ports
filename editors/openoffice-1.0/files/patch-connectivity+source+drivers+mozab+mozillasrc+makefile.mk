--- connectivity/source/drivers/mozab/mozillasrc/makefile.mk.orig	Tue Mar 19 12:56:24 2002
+++ connectivity/source/drivers/mozab/mozillasrc/makefile.mk	Sat May 18 15:51:13 2002
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
@@ -107,7 +107,7 @@
 	    -I$(MOZ_INC)$/addrbook -I$(MOZ_INC)$/mork -I$(MOZ_INC)$/locale \
 	    -I$(MOZ_INC)$/pref -I$(MOZ_INC)$/mime -I$(MOZ_INC)$/chrome \
 	    -I$(MOZ_INC)$/necko -I$(MOZ_INC)$/intl -I$(MOZ_INC)$/profile \
-	    -I$(MOZ_INC)$/embed_base -I$(MOZ_INC)$/mozldap 
+	    -I$(MOZ_INC)$/embed_base -I$(MOZ_INC)$/mozldap -I$(MOZ_INC)$/ldap-nspr
 CDEFS +=    -DWINVER=0x400 -DMOZILLA_CLIENT \
 	    -DNS_NET_FILE -DCookieManagement -DSingleSignon -DClientWallet \
             -DTRACING -DXP_PC -DXP_WIN -DXP_WIN32 -DHW_THREADS \
@@ -123,7 +123,7 @@
 	    -I$(MOZ_INC)$/addrbook -I$(MOZ_INC)$/mork -I$(MOZ_INC)$/locale \
 	    -I$(MOZ_INC)$/pref -I$(MOZ_INC)$/mime -I$(MOZ_INC)$/chrome \
 	    -I$(MOZ_INC)$/necko -I$(MOZ_INC)$/intl -I$(MOZ_INC)$/profile \
-	    -I$(MOZ_INC)$/embed_base -I$(MOZ_INC)$/mozldap 
+	    -I$(MOZ_INC)$/embed_base -I$(MOZ_INC)$/mozldap -I$(MOZ_INC)$/ldap-nspr
 CDEFS +=    -DDEBUG -DWINVER=0x400 -DMOZILLA_CLIENT \
 	    -DNS_NET_FILE -DCookieManagement -DSingleSignon -DClientWallet \
             -DTRACING -DXP_PC -DXP_WIN -DXP_WIN32 -DHW_THREADS \
@@ -141,7 +141,7 @@
 	    -I$(MOZ_INC)$/addrbook -I$(MOZ_INC)$/mork -I$(MOZ_INC)$/locale \
 	    -I$(MOZ_INC)$/pref -I$(MOZ_INC)$/mime -I$(MOZ_INC)$/chrome \
 	    -I$(MOZ_INC)$/necko -I$(MOZ_INC)$/intl -I$(MOZ_INC)$/profile \
-	    -I$(MOZ_INC)$/embed_base -I$(MOZ_INC)$/mozldap 
+	    -I$(MOZ_INC)$/embed_base -I$(MOZ_INC)$/mozldap -I$(MOZ_INC)$/ldap-nspr
 CDEFS+=	    -DMOZILLA_CLIENT \
             -DOSTYPE=\"Linux2.2.14-5\" -DOJI
 .IF "$(OS)" == "LINUX"
@@ -157,6 +157,13 @@
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
