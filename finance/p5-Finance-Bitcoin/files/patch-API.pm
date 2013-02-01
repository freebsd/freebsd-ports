--- ./lib/Finance/Bitcoin/API.pm.orig	2012-02-29 16:33:14.557825312 -0500
+++ ./lib/Finance/Bitcoin/API.pm	2012-02-29 16:33:22.505825441 -0500
@@ -2,7 +2,7 @@
 
 use 5.010;
 use common::sense;
-use JSON::RPC::Client;
+use JSON::RPC::Legacy::Client;
 use Any::Moose;
 use Object::AUTHORITY;
 use Scalar::Util qw[blessed];
