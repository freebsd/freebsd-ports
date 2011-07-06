--- ./daemon/libvirtd.h
+++ ./daemon/libvirtd.h
@@ -38,7 +38,9 @@
 # include "logging.h"
 # include "threads.h"
 # include "network.h"
-# include "virnetsaslcontext.h"
+# if HAVE_SASL
+#  include "virnetsaslcontext.h"
+# endif
 # include "virnetserverprogram.h"
 
 # if WITH_DTRACE
@@ -70,7 +72,9 @@ struct daemonClientPrivate {
 
     int domainEventCallbackID[VIR_DOMAIN_EVENT_ID_LAST];
 
+# if HAVE_SASL
     virNetSASLSessionPtr sasl;
+# endif
 
     /* This is only valid if a remote open call has been made on this
      * connection, otherwise it will be NULL.  Also if remote close is
@@ -81,7 +85,9 @@ struct daemonClientPrivate {
     daemonClientStreamPtr streams;
 };
 
+# if HAVE_SASL
 extern virNetSASLContextPtr saslCtxt;
+# endif
 extern virNetServerProgramPtr remoteProgram;
 extern virNetServerProgramPtr qemuProgram;
