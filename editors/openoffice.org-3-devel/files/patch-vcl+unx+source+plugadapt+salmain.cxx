http://qa.openoffice.org/issues/show_bug.cgi?id=27042

include <sys/types.h>
Note:  
--
*  $RCSfile: salmain.cxx,v $
*
*  $Revision: 1.8.12.2 $
*  
*  last change: $Author: hr $ $Date: 2004/01/09 18:14:00 $
--
includes this patch

--- ../vcl/unx/source/plugadapt/salmain.cxx~	Mon Mar 29 09:50:50 2004
+++ ../vcl/unx/source/plugadapt/salmain.cxx	Mon Mar 29 10:08:28 2004
@@ -59,7 +59,7 @@
  *
  ************************************************************************/
 
-#ifdef MACOSX
+#if defined(MACOSX) || defined(FREEBSD)
 // rlimit needs sys/types.h
 #include <sys/types.h>
 #include <sys/time.h>
