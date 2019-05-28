--- services/network/network_service.h.orig	2019-03-16 09:15:20 UTC
+++ services/network/network_service.h
@@ -138,7 +138,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) NetworkService
   void GetTotalNetworkUsages(
       mojom::NetworkService::GetTotalNetworkUsagesCallback callback) override;
   void UpdateSignedTreeHead(const net::ct::SignedTreeHead& sth) override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void SetCryptConfig(mojom::CryptConfigPtr crypt_config) override;
 #endif
 
