--- aws-cpp-sdk-s3-encryption/include/aws/s3-encryption/modules/CryptoModuleFactory.h.orig	2018-09-13 15:58:48 UTC
+++ aws-cpp-sdk-s3-encryption/include/aws/s3-encryption/modules/CryptoModuleFactory.h
@@ -80,6 +80,11 @@ namespace Aws
                 CryptoModuleFactoryEO();
 
                 /*
+                * Default Destructor.
+                */
+                virtual ~CryptoModuleFactoryEO() = default;
+
+                /*
                 * Creates a encryption only crypto module or returns an existing one using
                 * the encryption materials, crypto configuration, and AWS credentials provider.
                 */
@@ -102,6 +107,11 @@ namespace Aws
                 CryptoModuleFactoryAE();
 
                 /*
+                * Default Destructor.
+                */
+                virtual ~CryptoModuleFactoryAE() = default;
+
+                /*
                 * Creates a authenticated encryption crypto module or returns an existing one using
                 * the encryption materials, crypto configuration, and AWS credentials provider.
                 */
@@ -122,6 +132,11 @@ namespace Aws
                 * Default Constructor.
                 */
                 CryptoModuleFactoryStrictAE();
+
+                /*
+                * Default Destructor.
+                */
+                virtual ~CryptoModuleFactoryStrictAE() = default;
 
                 /*
                 * Creates a strict authenticated encryption crypto module or returns an existing one using
