--- docs/poweradmin-mysql-db-structure.sql.orig	2008-03-27 22:38:03.000000000 +0200
+++ docs/poweradmin-mysql-db-structure.sql	2010-03-14 17:07:14.000000000 +0200
@@ -1,4 +1,3 @@
-DROP TABLE IF EXISTS `users`;
 CREATE TABLE `users` (
   `id` int(11) NOT NULL auto_increment,
   `username` varchar(16) NOT NULL default '',
@@ -15,7 +14,6 @@
 INSERT INTO `users` VALUES (1,'admin','21232f297a57a5a743894a0e4a801fc3','Administrator','admin@example.net','Administrator with full rights.',1,1);
 UNLOCK TABLES;
 
-DROP TABLE IF EXISTS `perm_items`;
 CREATE TABLE `perm_items` (
   `id` int(11) NOT NULL auto_increment,
   `name` varchar(64) NOT NULL,
@@ -27,7 +25,6 @@
 INSERT INTO `perm_items` VALUES (41,'zone_master_add','User is allowed to add new master zones.'),(42,'zone_slave_add','User is allowed to add new slave zones.'),(43,'zone_content_view_own','User is allowed to see the content and meta data of zones he owns.'),(44,'zone_content_edit_own','User is allowed to edit the content of zones he owns.'),(45,'zone_meta_edit_own','User is allowed to edit the meta data of zones he owns.'),(46,'zone_content_view_others','User is allowed to see the content and meta data  of zones he does not own.'),(47,'zone_content_edit_others','User is allowed to edit the content of zones he does not own.'),(48,'zone_meta_edit_others','User is allowed to edit the meta data of zones he does not own.'),(49,'search','User is allowed to perform searches.'),(50,'supermaster_view','User is allowed to view supermasters.'),(51,'supermaster_add','User is allowed to add new supermasters.'),(52,'supermaster_edit','User is allowed to edit supermasters.'),(53,'user_is_ueberuser','User has full access. God-like. Redeemer.'),(54,'user_view_others','User is allowed to see other users and their details.'),(55,'user_add_new','User is allowed to add new users.'),(56,'user_edit_own','User is allowed to edit their own details.'),(57,'user_edit_others','User is allowed to edit other users.'),(58,'user_passwd_edit_others','User is allowed to edit the password of other users.'),(59,'user_edit_templ_perm','User is allowed to change the permission template that is assigned to a us er.'),(60,'templ_perm_add','User is allowed to add new permission templates.'),(61,'templ_perm_edit','User is allowed to edit existing permission templates.');
 UNLOCK TABLES;
 
-DROP TABLE IF EXISTS `perm_templ`;
 CREATE TABLE `perm_templ` (
   `id` int(11) NOT NULL auto_increment,
   `name` varchar(128) NOT NULL,
@@ -39,7 +36,6 @@
 INSERT INTO `perm_templ` VALUES (1,'Administrator','Administrator template with full rights.');
 UNLOCK TABLES;
 
-DROP TABLE IF EXISTS `perm_templ_items`;
 CREATE TABLE `perm_templ_items` (
   `id` int(11) NOT NULL auto_increment,
   `templ_id` int(11) NOT NULL,
@@ -51,7 +47,6 @@
 INSERT INTO `perm_templ_items` VALUES (249,1,53);
 UNLOCK TABLES;
 
-DROP TABLE IF EXISTS `zones`;
 CREATE TABLE `zones` (
   `id` int(11) NOT NULL auto_increment,
   `domain_id` int(11) NOT NULL default '0',
@@ -60,3 +55,22 @@
   PRIMARY KEY  (`id`),
   KEY `owner` (`owner`)
 ) ENGINE=MyISAM AUTO_INCREMENT=22001 DEFAULT CHARSET=latin1;
+
+CREATE TABLE IF NOT EXISTS `zone_templ` (
+  `id` int(11) NOT NULL auto_increment,
+  `name` varchar(128) NOT NULL,
+  `descr` varchar(1024) NOT NULL,
+  `owner` int(11) NOT NULL,
+  PRIMARY KEY  (`id`)
+) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=latin1;
+
+CREATE TABLE IF NOT EXISTS `zone_templ_records` (
+  `id` int(11) NOT NULL auto_increment,
+  `zone_templ_id` int(11) NOT NULL,
+  `name` varchar(255) NOT NULL,
+  `type` varchar(6) NOT NULL,
+  `content` varchar(255) NOT NULL,
+  `ttl` int(11) NOT NULL,
+  `prio` int(11) NOT NULL,
+  PRIMARY KEY  (`id`)
+) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=latin1;
