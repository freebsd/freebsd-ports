--- mozilla/js/src/config/config.mk.orgi	2009-04-21 15:12:51.000000000 +0200
+++ mozilla/js/src/config/config.mk	2009-04-21 15:15:37.000000000 +0200
@@ -490,7 +490,7 @@
 INCLUDES	= $(LOCAL_INCLUDES) $(REQ_INCLUDES) $(REQ_INCLUDES_SDK) -I$(PUBLIC) $(OS_INCLUDES)
 
 ifndef MOZILLA_INTERNAL_API
-INCLUDES	+= -I$(LIBXUL_DIST)/sdk/include
+INCLUDES	+= -I$(LIBXUL_DIST)/sdk/include -I%%LOCALBASE%%/include
 endif
 
 include $(topsrcdir)/config/static-checking-config.mk
