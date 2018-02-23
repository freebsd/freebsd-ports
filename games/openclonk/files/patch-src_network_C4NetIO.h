--- src/network/C4NetIO.h.orig	2018-02-04 15:39:08 UTC
+++ src/network/C4NetIO.h
@@ -94,6 +94,7 @@ public:
 		HostAddress(const sockaddr *addr) { SetHost(addr); }
 
 		AddressFamily GetFamily() const;
+		size_t GetAddrLen() const;
 		
 		void SetScopeId(int scopeId);
 		int GetScopeId() const;
