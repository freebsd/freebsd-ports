--- ace/OS_NS_Thread.h.orig	2006-05-30 17:15:25.000000000 +0400
+++ ace/OS_NS_Thread.h	2009-04-10 17:59:13.000000000 +0400
@@ -38,6 +38,8 @@
 # include "ace/ACE_export.h"
 # include "ace/Object_Manager_Base.h"
 
+# include <sys/cpuset.h>
+
 # if defined (ACE_EXPORT_MACRO)
 #   undef ACE_EXPORT_MACRO
 # endif
