Bug-Id:  706753
Summary: Bugzilla will not work with newest version of 
         JSON::RPC 1.01 due to non-backward compatibility
URL:     https://bugzilla.mozilla.org/show_bug.cgi?id=706753


Index: Bugzilla/WebService/Server/JSONRPC.pm
===================================================================
RCS file: /cvsroot/mozilla/webtools/bugzilla/Bugzilla/WebService/Server/JSONRPC.pm,v
retrieving revision 1.18
diff -p -u -r1.18 JSONRPC.pm
--- Bugzilla/WebService/Server/JSONRPC.pm	14 Feb 2011 20:18:51 -0000	1.18
+++ Bugzilla/WebService/Server/JSONRPC.pm	5 Jan 2012 00:04:31 -0000
@@ -22,7 +22,18 @@
 package Bugzilla::WebService::Server::JSONRPC;
 
 use strict;
-use base qw(JSON::RPC::Server::CGI Bugzilla::WebService::Server);
+use Bugzilla::WebService::Server;
+BEGIN {
+    our @ISA = qw(Bugzilla::WebService::Server);
+
+    if (eval { require JSON::RPC::Server::CGI }) {
+        unshift(@ISA, 'JSON::RPC::Server::CGI');
+    }
+    else {
+        require JSON::RPC::Legacy::Server::CGI;
+        unshift(@ISA, 'JSON::RPC::Legacy::Server::CGI');
+    }
+}
 
 use Bugzilla::Error;
 use Bugzilla::WebService::Constants;
