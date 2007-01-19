
$FreeBSD$

--- Slim/Networking/mDNS.pm.orig
+++ Slim/Networking/mDNS.pm
@@ -100,7 +100,6 @@
 
 		print CONF "$name\n";
 		print CONF "$service\n";
-		print CONF "TXT\n";
 		print CONF "$port\n";
 		print CONF "\n";
 	}
@@ -113,7 +112,7 @@
 		return;
 	}
 
-	my $command = sprintf("%s -d -f %s -P %s", $mDNSBin, $confFile, $pidFile);
+	my $command = sprintf("%s -b -f %s -P %s", $mDNSBin, $confFile, $pidFile);
 
 	$::d_mdns && msg("mDNS: About to run: $command\n");
 
