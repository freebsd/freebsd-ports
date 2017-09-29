https://github.com/PowerDNS/pdns/pull/5498/commits/0f8f34997afc2c3609b2f3df72ca808940d2a778#diff-a69f1deeeb9a0d7ebabc200a4c24c9f9L184
--- botan110signers.cc.orig	2017-07-04 15:43:07 UTC
+++ botan110signers.cc
@@ -181,8 +181,9 @@ std::string GOSTDNSCryptoKeyEngine::getP
 
 std::string GOSTDNSCryptoKeyEngine::getPublicKeyString() const
 {
-  const BigInt&x =d_key->public_point().get_affine_x();
-  const BigInt&y =d_key->public_point().get_affine_y();
+  std::shared_ptr<GOST_3410_PublicKey> pk = d_pubkey ? d_pubkey : d_key;
+  const BigInt&x =pk->public_point().get_affine_x();
+  const BigInt&y =pk->public_point().get_affine_y();
   
   size_t part_size = std::max(x.bytes(), y.bytes());
  
