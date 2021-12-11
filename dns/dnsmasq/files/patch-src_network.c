From 26bbf5a314d833beaf0f147d24409969f05f3dba Mon Sep 17 00:00:00 2001
From: Simon Kelley <simon@thekelleys.org.uk>
Date: Thu, 23 Sep 2021 10:54:46 +0100
Subject: [PATCH] Fix --address=/#/...... which was lost in 2.86

A victim of the domain-search rewrite. Apologies.
---
 CHANGELOG     |  8 ++++++++
 src/network.c |  3 ++-
 src/option.c  | 17 ++++++++++++-----
 3 files changed, 22 insertions(+), 6 deletions(-)

diff --git a/CHANGELOG b/CHANGELOG
index 5e54df9..8652dd8 100644
--- a/CHANGELOG
+++ b/CHANGELOG
@@ -1,3 +1,11 @@
+version 2.87
+        Allow arbitrary prefix lengths in --rev-server and
+	--domain=....,local
+
+	Replace --address=/#/..... functionality which got
+	missed in the 2.86 domain search rewrite.
+
+	
 version 2.86
 	Handle DHCPREBIND requests in the DHCPv6 server code.
 	Thanks to Aichun Li for spotting this omission, and the initial
diff --git a/src/network.c b/src/network.c
index 296c7bd..3c1c176 100644
--- a/src/network.c
+++ b/src/network.c
@@ -1626,7 +1626,8 @@ void check_servers(int no_loop_check)
 	 continue;
        
        if ((serv->flags & SERV_LITERAL_ADDRESS) &&
-	   !(serv->flags & (SERV_6ADDR | SERV_4ADDR | SERV_ALL_ZEROS)))
+	   !(serv->flags & (SERV_6ADDR | SERV_4ADDR | SERV_ALL_ZEROS)) &&
+	   strlen(serv->domain))
 	 {
 	   count--;
 	   if (++locals <= LOCALS_LOGGED)
diff --git a/src/option.c b/src/option.c
index e64c3ab..54d89aa 100644
--- a/src/option.c
+++ b/src/option.c
@@ -2764,7 +2764,7 @@ static int one_opt(int option, char *arg, char *errstr, char *gen_err, int comma
 	
 	if (!arg || !*arg)
 	  flags = SERV_LITERAL_ADDRESS;
-	else if (option == 'A')
+	else if (option != 'S')
 	  {
 	    /* # as literal address means return zero address for 4 and 6 */
 	    if (strcmp(arg, "#") == 0)
@@ -2788,11 +2788,18 @@ static int one_opt(int option, char *arg, char *errstr, char *gen_err, int comma
 	while (1)
 	  {
 	    /* server=//1.2.3.4 is special. */
-	    if (strlen(domain) == 0 && lastdomain)
-	      flags |= SERV_FOR_NODOTS;
-	    else
-	      flags &= ~SERV_FOR_NODOTS;
+	    if (lastdomain)
+	      {
+		if (strlen(domain) == 0)
+		  flags |= SERV_FOR_NODOTS;
+		else
+		  flags &= ~SERV_FOR_NODOTS;
 
+		/* address=/#/ matches the same as without domain */
+		if (option != 'S' && domain[0] == '#' && domain[1] == 0)
+		  domain[0] = 0;
+	      }
+	    
 	    if (!add_update_server(flags, &serv_addr, &source_addr, interface, domain, &addr))
 	      ret_err(gen_err);
 	    
-- 
2.20.1

