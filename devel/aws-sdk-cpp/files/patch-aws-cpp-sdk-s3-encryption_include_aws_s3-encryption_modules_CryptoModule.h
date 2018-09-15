--- aws-cpp-sdk-s3-encryption/include/aws/s3-encryption/modules/CryptoModule.h.orig	2018-09-13 15:58:35 UTC
+++ aws-cpp-sdk-s3-encryption/include/aws/s3-encryption/modules/CryptoModule.h
@@ -48,6 +48,12 @@ namespace Aws
                 */
                 CryptoModule(const std::shared_ptr<Aws::Utils::Crypto::EncryptionMaterials>& encryptionMaterials, const CryptoConfiguration & cryptoConfig);
 
+
+		/*
+		* Default destructor
+		*/
+		virtual ~CryptoModule() = default;
+
                 /*
                 * Function to put an encrypted object to S3.
                 */
