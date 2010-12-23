--- include/zrtp_config_user.h.orig	2009-03-22 06:26:34.000000000 -0700
+++ include/zrtp_config_user.h	2010-12-01 14:28:15.963667063 -0800
@@ -14,6 +14,8 @@
 #ifndef __ZRTP_CONFIG_USER_H__
 #define __ZRTP_CONFIG_USER_H__
 
+#include "zrtp_config_unix.h"
+
 /**
  * \defgroup zrtp_config Build Configuration
  * \{
@@ -52,6 +54,8 @@
 /** \brief Define Platform manually there */
 //#undefine ZRTP_PLATFORM
 
+#define ZRTP_PLATFORM ZP_LINUX
+
 
 /** \brief Constant to define Big Endian Platform */
 #define ZBO_BIG_ENDIAN				0x4321
@@ -59,7 +63,7 @@
 #define ZBO_LITTLE_ENDIAN			0x1234
 
 /** \brief Define Platform Byte Order manually there */
-//#define ZRTP_BYTE_ORDER
+#define ZRTP_BYTE_ORDER ZBO_LITTLE_ENDIAN
 
 /** \brief Defines the max length in bytes of a binary SAS digest */
 #ifndef ZRTP_SAS_DIGEST_LENGTH
