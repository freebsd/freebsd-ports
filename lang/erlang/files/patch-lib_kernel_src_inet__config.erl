
$FreeBSD$

--- lib/kernel/src/inet_config.erl.orig	Mon Jul  7 14:06:28 2003
+++ lib/kernel/src/inet_config.erl	Fri Sep 19 14:21:14 2003
@@ -78,7 +78,12 @@
 			    error("can't set lookup to native: ~p", [Reason])
 		    end;
 		freebsd -> %% we may have to check version (2.2.2)
-		    load_resolv(filename:join(Etc,"host.conf"), host_conf_freebsd);
+		    case os:version() of
+			{Major,_,_} when Major >= 5 ->
+			    load_resolv(filename:join(Etc,"nsswitch.conf"), nsswitch_conf);
+			_ ->
+			    load_resolv(filename:join(Etc,"host.conf"), host_conf_freebsd)
+		    end;
 		'bsd/os' ->
 		    load_resolv(filename:join(Etc,"irs.conf"), host_conf_bsdos);
 		linux ->
