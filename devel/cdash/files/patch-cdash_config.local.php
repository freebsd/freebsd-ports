--- /dev/null	2011-08-12 12:09:43.000000000 +0200
+++ cdash/config.local.php	2011-08-12 11:57:38.000000000 +0200
@@ -0,0 +1,108 @@
+<?php
+/*=========================================================================
+
+  Program:   CDash - Cross-Platform Dashboard System
+  Module:    $Id: config.php 2618 2010-08-04 19:28:36Z david.cole $
+  Language:  PHP
+  Date:      $Date: 2010-08-04 21:28:36 +0200 (mer., 04 août 2010) $
+  Version:   $Revision: 2618 $
+
+  Copyright (c) 2002 Kitware, Inc.  All rights reserved.
+  See Copyright.txt or http://www.cmake.org/HTML/Copyright.html for details.
+
+     This software is distributed WITHOUT ANY WARRANTY; without even 
+     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
+     PURPOSE.  See the above copyright notices for more information.
+
+=========================================================================*/
+/** WARNING: It's recommended to create a config.local.php file and leave
+ * this file as is.
+ * If creating the config.local.php from config.php make sure you DELETE
+ * any text after the 'DO NOT EDIT AFTER THIS LINE' otherwise your
+ * configuration file will be referencing each other. */
+
+// Hostname of the database server
+$CDASH_DB_HOST = 'localhost';
+// Login for database access
+$CDASH_DB_LOGIN = 'root';
+// Password for database access
+$CDASH_DB_PASS = '';
+// Name of the database
+$CDASH_DB_NAME = 'cdash';
+// Database type (empty means mysql)
+$CDASH_DB_TYPE = '%%DB_TYPE%%';
+// Turn this variable ON when CDash has been installed
+// Prevents from running the install.php again
+$CDASH_PRODUCTION_MODE = false;
+$CDASH_TESTING_MODE = false;
+// Should we use asynchronous submission
+$CDASH_ASYNCHRONOUS_SUBMISSION = false;
+// Default from email
+$CDASH_EMAILADMIN = 'admin@cdash.org';
+$CDASH_EMAIL_FROM = 'admin@cdash.org';
+$CDASH_EMAIL_REPLY = 'noreply@cdash.org';
+// Duration of the cookie session (in seconds)
+$CDASH_COOKIE_EXPIRATION_TIME='3600';
+// Using HTTPS protocol to access CDash
+$CDASH_USE_HTTPS ='0';
+// Name of the server running CDash. 
+// Leave empty to use current name.
+$CDASH_SERVER_NAME = '';
+// If the remote request should use localhost or the full name
+// This variable should be set to 1 in most of the server configurations
+$CDASH_CURL_REQUEST_LOCALHOST='1';
+$CDASH_CURL_LOCALHOST_PREFIX='';
+// Define the location of the local directory
+$CDASH_USE_LOCAL_DIRECTORY = '0';
+// CSS file 
+$CDASH_CSS_FILE = 'cdash.css';
+// Backup directory
+$CDASH_BACKUP_DIRECTORY = 'backup';
+// Log file location
+$CDASH_LOG_FILE = $CDASH_BACKUP_DIRECTORY."/cdash.log";
+// Using external authentication
+$CDASH_EXTERNAL_AUTH = '0';
+// Backup timeframe
+$CDASH_BACKUP_TIMEFRAME = '48'; // 48 hours
+// Request full email address to add new users
+// instead of displaying a list
+$CDASH_FULL_EMAIL_WHEN_ADDING_USER = '0';
+// Use getIPfromApache script to get IP addresses
+// when using forwarding script
+$CDASH_FORWARDING_IP='192.%'; // should be an SQL format 
+$CDASH_DEFAULT_IP_LOCATIONS = array();
+// Use compression (default on)
+$CDASH_USE_COMPRESSION='1';
+// Use LDAP
+$CDASH_USE_LDAP='0';
+$CDASH_LDAP_HOSTNAME='localhost';
+$CDASH_LDAP_BASEDN='ou=people,dc=organization,dc=com';
+$CDASH_LDAP_PROTOCOL_VERSION='3';
+// For authentication against Active Directory, set CDASH_LDAP_AUTHENTICATED to '1' 
+// CDASH_LDAP_OPT_REFERRALS to '0', and specify a bind DN and password
+$CDASH_LDAP_OPT_REFERRALS='1';
+$CDASH_LDAP_AUTHENTICATED='0';
+$CDASH_LDAP_BIND_DN='cn=user,ou=people,dc=orgranization,dc=com';
+$CDASH_LDAP_BIND_PASSWORD='password';
+// Allow rememberme
+$CDASH_ALLOW_LOGIN_COOKIE='1';
+// Set to start the autoremoval on the first build of the day
+$CDASH_AUTOREMOVE_BUILDS='0';
+// Google Map API
+$CDASH_GOOGLE_MAP_API_KEY = array();
+$CDASH_GOOGLE_MAP_API_KEY['localhost'] = 'ABQIAAAAT7I3XxP5nXC2xZUbg5AhLhQlpUmSySBnNeRIYFXQdqJETZJpYBStoWsCJtLvtHDiIJzsxJ953H3rgg';
+// Enable Google Analytics
+$CDASH_DEFAULT_GOOGLE_ANALYTICS='';
+// How long since the last submission before considering a project
+// non active
+$CDASH_ACTIVE_PROJECT_DAYS = '7'; // a week
+// Use CDash to manage build submissions
+// This feature is currently experimental
+$CDASH_MANAGE_CLIENTS = '0';
+// Define the git command
+$CDASH_GIT_COMMAND = 'git';
+// The default git directory where the bare repositories should be created
+$CDASH_DEFAULT_GIT_DIRECTORY = 'git';
+// Number of seconds to allow processing a single submission before resetting
+$CDASH_SUBMISSION_PROCESSING_TIME_LIMIT = '450';
+?>
