--- lib/net/imap.rb.orig	Tue Feb 13 02:01:19 2007
+++ lib/net/imap.rb	Tue May 22 20:44:37 2007
@@ -284,7 +284,11 @@
 
     # Disconnects from the server.
     def disconnect
-      @sock.shutdown unless @usessl
+      if SSL::SSLSocket === @sock
+        @sock.io.shutdown
+      else
+        @sock.shutdown
+      end
       @receiver_thread.join
       @sock.close
     end
