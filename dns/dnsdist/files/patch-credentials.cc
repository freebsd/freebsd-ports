--- credentials.cc.orig	2021-11-23 18:39:17 UTC
+++ credentials.cc
@@ -28,7 +28,7 @@
 #include <sodium.h>
 #endif
 
-#ifdef HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT
+#if defined(HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT) && defined(EVP_PKEY_SCRYPT)
 #include <openssl/evp.h>
 #include <openssl/kdf.h>
 #include <openssl/rand.h>
@@ -42,7 +42,7 @@
 #include "credentials.hh"
 #include "misc.hh"
 
-#ifdef HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT
+#if defined(HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT) && defined(EVP_PKEY_SCRYPT)
 static size_t const pwhash_max_size = 128U; /* maximum size of the output */
 static size_t const pwhash_output_size = 32U; /* size of the hashed output (before base64 encoding) */
 static unsigned int const pwhash_salt_size = 16U; /* size of the salt (before base64 encoding */
@@ -95,7 +95,7 @@ void SensitiveData::clear()
 
 static std::string hashPasswordInternal(const std::string& password, const std::string& salt, uint64_t workFactor, uint64_t parallelFactor, uint64_t blockSize)
 {
-#ifdef HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT
+#if defined(HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT) && defined(EVP_PKEY_SCRYPT)
   auto pctx = std::unique_ptr<EVP_PKEY_CTX, void (*)(EVP_PKEY_CTX*)>(EVP_PKEY_CTX_new_id(EVP_PKEY_SCRYPT, nullptr), EVP_PKEY_CTX_free);
   if (!pctx) {
     throw std::runtime_error("Error getting a scrypt context to hash the supplied password");
@@ -142,7 +142,7 @@ static std::string hashPasswordInternal(const std::str
 
 static std::string generateRandomSalt()
 {
-#ifdef HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT
+#if defined(HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT) && defined(EVP_PKEY_SCRYPT)
   /* generate a random salt */
   std::string salt;
   salt.resize(pwhash_salt_size);
@@ -159,7 +159,7 @@ static std::string generateRandomSalt()
 
 std::string hashPassword(const std::string& password, uint64_t workFactor, uint64_t parallelFactor, uint64_t blockSize)
 {
-#ifdef HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT
+#if defined(HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT) && defined(EVP_PKEY_SCRYPT)
   std::string result;
   result.reserve(pwhash_max_size);
 
@@ -187,7 +187,7 @@ std::string hashPassword(const std::string& password, 
 
 std::string hashPassword(const std::string& password)
 {
-#ifdef HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT
+#if defined(HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT) && defined(EVP_PKEY_SCRYPT)
   return hashPassword(password, CredentialsHolder::s_defaultWorkFactor, CredentialsHolder::s_defaultParallelFactor, CredentialsHolder::s_defaultBlockSize);
 #else
   throw std::runtime_error("Hashing a password requires scrypt support in OpenSSL, and it is not available");
@@ -196,7 +196,7 @@ std::string hashPassword(const std::string& password)
 
 bool verifyPassword(const std::string& binaryHash, const std::string& salt, uint64_t workFactor, uint64_t parallelFactor, uint64_t blockSize, const std::string& binaryPassword)
 {
-#ifdef HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT
+#if defined(HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT) && defined(EVP_PKEY_SCRYPT)
   auto expected = hashPasswordInternal(binaryPassword, salt, workFactor, parallelFactor, blockSize);
   return constantTimeStringEquals(expected, binaryHash);
 #else
@@ -207,7 +207,7 @@ bool verifyPassword(const std::string& binaryHash, con
 /* parse a hashed password in PHC string format */
 static void parseHashed(const std::string& hash, std::string& salt, std::string& hashedPassword, uint64_t& workFactor, uint64_t& parallelFactor, uint64_t& blockSize)
 {
-#ifdef HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT
+#if defined(HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT) && defined(EVP_PKEY_SCRYPT)
   auto parametersEnd = hash.find('$', pwhash_prefix.size());
   if (parametersEnd == std::string::npos || parametersEnd == hash.size()) {
     throw std::runtime_error("Invalid hashed password format, no parameters");
@@ -276,7 +276,7 @@ bool verifyPassword(const std::string& hash, const std
     return false;
   }
 
-#ifdef HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT
+#if defined(HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT) && defined(EVP_PKEY_SCRYPT)
   std::string salt;
   std::string hashedPassword;
   uint64_t workFactor = 0;
@@ -294,7 +294,7 @@ bool verifyPassword(const std::string& hash, const std
 
 bool isPasswordHashed(const std::string& password)
 {
-#ifdef HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT
+#if defined(HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT) && defined(EVP_PKEY_SCRYPT)
   if (password.size() < pwhash_prefix_size || password.size() > pwhash_max_size) {
     return false;
   }
@@ -389,7 +389,7 @@ bool CredentialsHolder::matches(const std::string& pas
 
 bool CredentialsHolder::isHashingAvailable()
 {
-#ifdef HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT
+#if defined(HAVE_EVP_PKEY_CTX_SET1_SCRYPT_SALT) && defined(EVP_PKEY_SCRYPT)
   return true;
 #else
   return false;
