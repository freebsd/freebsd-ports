--- spice3f5/common/util/makelib.sh.orig	1994-01-29 19:16:27 UTC
+++ spice3f5/common/util/makelib.sh
@@ -35,7 +35,7 @@ ENDOFMAKEDEFS
 			cat >> makedefs <<ENDOFMAKEDEFSX
 
 INCLUDE		= -I$(INCLUDE_DIR) $(INCX)
-CFLAGS		= $(CC_OPT) $(SYS_CFLAGS) $(INTERFACE_OPTS)
+REAL_CFLAGS		= $(CC_OPT) $(SYS_CFLAGS) $(INTERFACE_OPTS)
 CONF_DEP_EXTRA	= $(CONF_XCC)
 ENDOFMAKEDEFSX
 		fi
