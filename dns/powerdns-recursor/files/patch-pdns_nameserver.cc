--- pdns_recursor.cc.orig	Wed Jan 17 23:45:51 2007
+++ pdns_recursor.cc	Thu Jan 18 00:01:47 2007
@@ -1691,7 +1691,7 @@
     ::arg().set("client-tcp-timeout","Timeout in seconds when talking to TCP clients")="2";
     ::arg().set("max-tcp-clients","Maximum number of simultaneous TCP clients")="128";
     ::arg().set("hint-file", "If set, load root hints from this file")="";
-    ::arg().set("max-cache-entries", "If set, maximum number of entries in the main cache")="0";
+    ::arg().set("max-cache-entries", "If set, maximum number of entries in the main cache")="500000";
     ::arg().set("max-negative-ttl", "maximum number of seconds to keep a negative cached entry in memory")="3600";
     ::arg().set("server-id", "Returned when queried for 'server.id' TXT, defaults to hostname")="";
     ::arg().set("remotes-ringbuffer-entries", "maximum number of packets to store statistics for")="0";
