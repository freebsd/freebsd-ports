# Description: Backport fix building test suite on non-x86 platforms
# PR: ports/182549
# Upstream Issue: https://svn.boost.org/trac/boost/ticket/3897
# Upstream Change: https://svn.boost.org/trac/boost/changeset/62780

--- ./boost/test/impl/execution_monitor.ipp.orig	2013-12-14 18:22:41.772892518 +1100
+++ ./boost/test/impl/execution_monitor.ipp	2013-12-14 18:23:15.554395963 +1100
@@ -156,6 +156,8 @@
 
 #  if defined(__FreeBSD__)  
 
+#    include <osreldate.h>
+
 #    ifndef SIGPOLL
 #      define SIGPOLL SIGIO
 #    endif
