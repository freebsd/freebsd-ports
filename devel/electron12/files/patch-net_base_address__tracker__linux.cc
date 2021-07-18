--- net/base/address_tracker_linux.cc.orig	2021-04-14 01:08:52 UTC
+++ net/base/address_tracker_linux.cc
@@ -5,7 +5,9 @@
 #include "net/base/address_tracker_linux.h"
 
 #include <errno.h>
+#if !defined(OS_BSD)
 #include <linux/if.h>
+#endif
 #include <stdint.h>
 #include <sys/ioctl.h>
 #include <utility>
@@ -190,6 +192,7 @@ void AddressTrackerLinux::Init() {
   DCHECK_LT(base::android::BuildInfo::GetInstance()->sdk_int(),
             base::android::SDK_VERSION_P);
 #endif
+#if !defined(OS_FREEBSD)
   netlink_fd_.reset(socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE));
   if (!netlink_fd_.is_valid()) {
     PLOG(ERROR) << "Could not create NETLINK socket";
@@ -274,6 +277,10 @@ void AddressTrackerLinux::Init() {
         base::BindRepeating(&AddressTrackerLinux::OnFileCanReadWithoutBlocking,
                             base::Unretained(this)));
   }
+#else  // !OS_FREEBSD
+  NOTIMPLEMENTED();
+  AbortAndForceOnline();
+#endif // !OS_FREEBSD
 }
 
 void AddressTrackerLinux::AbortAndForceOnline() {
@@ -285,6 +292,7 @@ void AddressTrackerLinux::AbortAndForceOnline() {
   connection_type_initialized_cv_.Broadcast();
 }
 
+#if !defined(OS_BSD)
 AddressTrackerLinux::AddressMap AddressTrackerLinux::GetAddressMap() const {
   AddressTrackerAutoLock lock(*this, address_map_lock_);
   return address_map_;
@@ -303,6 +311,7 @@ bool AddressTrackerLinux::IsInterfaceIgnored(int inter
   const char* interface_name = get_interface_name_(interface_index, buf);
   return ignored_interfaces_.find(interface_name) != ignored_interfaces_.end();
 }
+#endif // !OS_BSD
 
 NetworkChangeNotifier::ConnectionType
 AddressTrackerLinux::GetCurrentConnectionType() {
@@ -361,6 +370,7 @@ void AddressTrackerLinux::HandleMessage(const char* bu
                                         bool* address_changed,
                                         bool* link_changed,
                                         bool* tunnel_changed) {
+#if !defined(OS_FREEBSD)
   DCHECK(buffer);
   // Note that NLMSG_NEXT decrements |length| to reflect the number of bytes
   // remaining in |buffer|.
@@ -473,6 +483,9 @@ void AddressTrackerLinux::HandleMessage(const char* bu
         break;
     }
   }
+#else  // !OS_FREEBSD
+  NOTIMPLEMENTED();
+#endif // !OS_FREEBSD
 }
 
 void AddressTrackerLinux::OnFileCanReadWithoutBlocking() {
@@ -500,6 +513,7 @@ bool AddressTrackerLinux::IsTunnelInterfaceName(const 
 }
 
 void AddressTrackerLinux::UpdateCurrentConnectionType() {
+#if !defined(OS_FREEBSD)
   AddressTrackerLinux::AddressMap address_map = GetAddressMap();
   std::unordered_set<int> online_links = GetOnlineLinks();
 
@@ -525,6 +539,9 @@ void AddressTrackerLinux::UpdateCurrentConnectionType(
 
   AddressTrackerAutoLock lock(*this, connection_type_lock_);
   current_connection_type_ = type;
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 int AddressTrackerLinux::GetThreadsWaitingForConnectionTypeInitForTesting() {
