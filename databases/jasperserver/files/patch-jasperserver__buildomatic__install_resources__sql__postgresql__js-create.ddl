--- ./jasperserver/buildomatic/install_resources/sql/postgresql/js-create.ddl.orig	2011-02-21 16:48:37.000000000 -0800
+++ ./jasperserver/buildomatic/install_resources/sql/postgresql/js-create.ddl	2011-02-21 15:45:58.000000000 -0800
@@ -1,6 +1,6 @@
 
     create table JIAccessEvent (
-        id int8 not null,
+        id bigserial not null,
         user_id int8 not null,
         event_date timestamp not null,
         resource_id int8 not null,
@@ -108,7 +108,7 @@
     );
 
     create table JILogEvent (
-        id int8 not null,
+        id bigserial not null,
         occurrence_date timestamp not null,
         event_type int2 not null,
         component varchar(100),
@@ -136,7 +136,7 @@
     );
 
     create table JIObjectPermission (
-        id int8 not null,
+        id bigserial not null,
         uri varchar(250) not null,
         recipientobjectclass varchar(250),
         recipientobjectid int8,
@@ -158,7 +158,7 @@
     );
 
     create table JIProfileAttribute (
-        id int8 not null,
+        id bigserial not null,
         attrName varchar(255) not null,
         attrValue varchar(255) not null,
         principalobjectclass varchar(255) not null,
@@ -175,7 +175,7 @@
     );
 
     create table JIReportJob (
-        id int8 not null,
+        id bigserial not null,
         version int4 not null,
         owner int8 not null,
         label varchar(100) not null,
@@ -190,7 +190,7 @@
     );
 
     create table JIReportJobCalendarTrigger (
-        id int8 not null,
+        id bigserial not null,
         minutes varchar(200) not null,
         hours varchar(80) not null,
         days_type int2 not null,
@@ -201,7 +201,7 @@
     );
 
     create table JIReportJobMail (
-        id int8 not null,
+        id bigserial not null,
         version int4 not null,
         subject varchar(100) not null,
         message varchar(2000),
@@ -232,7 +232,7 @@
     );
 
     create table JIReportJobRepoDest (
-        id int8 not null,
+        id bigserial not null,
         version int4 not null,
         folder_uri varchar(250) not null,
         sequential_filenames bool not null,
@@ -251,7 +251,7 @@
     );
 
     create table JIReportJobTrigger (
-        id int8 not null,
+        id bigserial not null,
         version int4 not null,
         timezone varchar(40),
         start_type int2 not null,
@@ -287,7 +287,7 @@
     );
 
     create table JIRepositoryCache (
-        id int8 not null,
+        id bigserial not null,
         uri varchar(250) not null,
         cache_name varchar(20) not null,
         data bytea,
@@ -299,7 +299,7 @@
     );
 
     create table JIResource (
-        id int8 not null,
+        id bigserial not null,
         version int4 not null,
         name varchar(100) not null,
         parent_folder int8 not null,
@@ -328,7 +328,7 @@
     );
 
     create table JIRole (
-        id int8 not null,
+        id bigserial not null,
         rolename varchar(100) not null,
         tenantId int8 not null,
         externallyDefined bool,
@@ -352,7 +352,7 @@
     );
 
     create table JIUser (
-        id int8 not null,
+        id bigserial not null,
         username varchar(100) not null,
         tenantId int8 not null,
         fullname varchar(100) not null,
