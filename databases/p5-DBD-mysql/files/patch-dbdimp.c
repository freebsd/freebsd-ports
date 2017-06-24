From 9ea49043522f1f1387384edf42ced7ad3ec44d3a Mon Sep 17 00:00:00 2001
From: Georg Richter <georg@mariadb.com>
Date: Sun, 28 May 2017 15:22:09 +0200
Subject: [PATCH] Fix for builing DBD-mysql together with MariaDB Connector/C.
 Use mysql_option function instead of accessing internal members of MYSQL
 structure.

---
 dbdimp.c | 3 ++-
 1 file changed, 2 insertions(+), 1 deletion(-)

diff --git a/dbdimp.c b/dbdimp.c
index da428ed..763b9fa 100644
--- dbdimp.c.orig	2017-02-28 13:36:40 UTC
+++ dbdimp.c
@@ -2139,6 +2139,7 @@ MYSQL *mysql_dr_connect(
 
     if (result)
     {
+      my_bool reconnect= 0;
 #if MYSQL_VERSION_ID >=SERVER_PREPARE_VERSION
       /* connection succeeded. */
       /* imp_dbh == NULL when mysql_dr_connect() is called from mysql.xs
@@ -2155,7 +2156,7 @@ MYSQL *mysql_dr_connect(
         we turn off Mysql's auto reconnect and handle re-connecting ourselves
         so that we can keep track of when this happens.
       */
-      result->reconnect=0;
+      mysql_options(result, MYSQL_OPT_RECONNECT, &reconnect);
     }
     else {
       /* 
