Backport of:
	https://github.com/PowerDNS/pdns/commit/e7c6996eb650d17372548899408160bb2d712511

--- dnsdist-console.cc.orig	2020-08-28 19:39:07 UTC
+++ dnsdist-console.cc
@@ -526,7 +526,7 @@ const std::vector<ConsoleKeyword> g_consoleKeywords{
   { "setMaxTCPQueriesPerConnection", true, "n", "set the maximum number of queries in an incoming TCP connection. 0 means unlimited" },
   { "setMaxTCPQueuedConnections", true, "n", "set the maximum number of TCP connections queued (waiting to be picked up by a client thread)" },
   { "setMaxUDPOutstanding", true, "n", "set the maximum number of outstanding UDP queries to a given backend server. This can only be set at configuration time and defaults to 65535" },
-  { "SetNegativeAndSOAAction", "true", "nxd, zone, ttl, mname, rname, serial, refresh, retry, expire, minimum [, options]", "Turn a query into a NXDomain or NoData answer and sets a SOA record in the additional section" },
+  { "SetNegativeAndSOAAction", true, "nxd, zone, ttl, mname, rname, serial, refresh, retry, expire, minimum [, options]", "Turn a query into a NXDomain or NoData answer and sets a SOA record in the additional section" },
   { "setPayloadSizeOnSelfGeneratedAnswers", true, "payloadSize", "set the UDP payload size advertised via EDNS on self-generated responses" },
   { "setPoolServerPolicy", true, "policy, pool", "set the server selection policy for this pool to that policy" },
   { "setPoolServerPolicyLua", true, "name, func, pool", "set the server selection policy for this pool to one named 'name' and provided by 'function'" },
