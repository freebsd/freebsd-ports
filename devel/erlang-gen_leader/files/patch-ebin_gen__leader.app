--- ebin/gen_leader.app.orig	2015-06-02 14:02:02 UTC
+++ ebin/gen_leader.app
@@ -3,7 +3,7 @@
 {application, gen_leader,
  [
   {description, "The gen_leader behaviour"},
-  {vsn, "1.0"},
+  {vsn, "%%PORTVERSION%%"},
   {id, "gen_leader"},
   {modules, [gen_leader]},
   {registered, [ ]},
