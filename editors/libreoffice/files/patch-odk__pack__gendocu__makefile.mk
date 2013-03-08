--- ./odk/pack/gendocu/makefile.mk.orig	2013-01-31 05:54:53.000000000 -0500
+++ ./odk/pack/gendocu/makefile.mk	2013-02-18 18:38:29.000000000 -0500
@@ -97,7 +97,7 @@
 $(JAVA_SRC_FILES) : $(SOLARCOMMONPCKDIR)$/$$(@:f)
     -$(MKDIRHIER) $(@:d)        
     $(MY_COPY) $< $@
-    cd $(JAVA_SRC_DIR) && unzip -quo $(@:f)
+    cd $(JAVA_SRC_DIR) && unzip -qu $(@:f)
 
 #$(JAVA_SRC_DIR)$/com$/sun$/star$/beans$/%.java : $(PRJ)$/source$/bean$/com$/sun$/star$/beans$/%.java 
 #	-$(MKDIRHIER) $(@:d)        
