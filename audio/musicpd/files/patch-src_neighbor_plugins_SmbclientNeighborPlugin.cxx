--- src/neighbor/plugins/SmbclientNeighborPlugin.cxx.orig	2021-10-14 13:25:21 UTC
+++ src/neighbor/plugins/SmbclientNeighborPlugin.cxx
@@ -33,6 +33,8 @@
 
 #include <libsmbclient.h>
 
+#include <cerrno>
+#include <cstring>
 #include <utility>
 
 class SmbclientNeighborExplorer final : public NeighborExplorer {
@@ -45,12 +47,12 @@ class SmbclientNeighborExplorer final : public Neighbo
 
 		Server(const Server &) = delete;
 
-		gcc_pure
+		[[gnu::pure]]
 		bool operator==(const Server &other) const noexcept {
 			return name == other.name;
 		}
 
-		[[nodiscard]] gcc_pure
+		[[nodiscard]] [[gnu::pure]]
 		NeighborInfo Export() const noexcept {
 			return { "smb://" + name + "/", comment };
 		}
@@ -165,11 +167,11 @@ ReadServers(SmbclientContext &ctx, const char *uri,
 		ReadServers(ctx, handle, list);
 		ctx.CloseDirectory(handle);
 	} else
-		FormatErrno(smbclient_domain, "smbc_opendir('%s') failed",
-			    uri);
+		FmtError(smbclient_domain, "smbc_opendir('{}') failed: {}",
+			 uri, strerror(errno));
 }
 
-gcc_pure
+[[gnu::pure]]
 static NeighborExplorer::List
 DetectServers(SmbclientContext &ctx) noexcept
 {
@@ -178,7 +180,7 @@ DetectServers(SmbclientContext &ctx) noexcept
 	return list;
 }
 
-gcc_pure
+[[gnu::pure]]
 static NeighborExplorer::List::iterator
 FindBeforeServerByURI(NeighborExplorer::List::iterator prev,
 		      NeighborExplorer::List::iterator end,
