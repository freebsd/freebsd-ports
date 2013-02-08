--- ./odk/pack/gendocu/makefile.mk.orig	2013-02-06 20:11:03.000000000 -0500
+++ ./odk/pack/gendocu/makefile.mk	2013-02-07 13:26:20.000000000 -0500
@@ -106,7 +106,7 @@
 $(JAVA_SRC_FILES) : $(SOLARCOMMONPCKDIR)$/$$(@:f)
     -$(MKDIRHIER) $(@:d)        
     $(MY_COPY) $< $@
-    cd $(JAVA_SRC_DIR) && unzip -quo $(@:f)
+    cd $(JAVA_SRC_DIR) && unzip -qu $(@:f)
 
 #$(JAVA_SRC_DIR)$/com$/sun$/star$/beans$/%.java : $(PRJ)$/source$/bean$/com$/sun$/star$/beans$/%.java 
 #	-$(MKDIRHIER) $(@:d)        
