--- net/base/address_tracker_linux.cc.orig	2019-09-10 10:42:42 UTC
+++ net/base/address_tracker_linux.cc
@@ -21,96 +21,10 @@
 namespace net {
 namespace internal {
 
-namespace {
-
-// Some kernel functions such as wireless_send_event and rtnetlink_ifinfo_prep
-// may send spurious messages over rtnetlink. RTM_NEWLINK messages where
-// ifi_change == 0 and rta_type == IFLA_WIRELESS should be ignored.
-bool IgnoreWirelessChange(const struct nlmsghdr* header,
-                          const struct ifinfomsg* msg) {
-  size_t length = IFLA_PAYLOAD(header);
-  for (const struct rtattr* attr = IFLA_RTA(msg); RTA_OK(attr, length);
-       attr = RTA_NEXT(attr, length)) {
-    if (attr->rta_type == IFLA_WIRELESS && msg->ifi_change == 0)
-      return true;
-  }
-  return false;
-}
-
-// Retrieves address from NETLINK address message.
-// Sets |really_deprecated| for IPv6 addresses with preferred lifetimes of 0.
-bool GetAddress(const struct nlmsghdr* header,
-                IPAddress* out,
-                bool* really_deprecated) {
-  if (really_deprecated)
-    *really_deprecated = false;
-  const struct ifaddrmsg* msg =
-      reinterpret_cast<struct ifaddrmsg*>(NLMSG_DATA(header));
-  size_t address_length = 0;
-  switch (msg->ifa_family) {
-    case AF_INET:
-      address_length = IPAddress::kIPv4AddressSize;
-      break;
-    case AF_INET6:
-      address_length = IPAddress::kIPv6AddressSize;
-      break;
-    default:
-      // Unknown family.
-      return false;
-  }
-  // Use IFA_ADDRESS unless IFA_LOCAL is present. This behavior here is based on
-  // getaddrinfo in glibc (check_pf.c). Judging from kernel implementation of
-  // NETLINK, IPv4 addresses have only the IFA_ADDRESS attribute, while IPv6
-  // have the IFA_LOCAL attribute.
-  uint8_t* address = NULL;
-  uint8_t* local = NULL;
-  size_t length = IFA_PAYLOAD(header);
-  for (const struct rtattr* attr =
-           reinterpret_cast<const struct rtattr*>(IFA_RTA(msg));
-       RTA_OK(attr, length);
-       attr = RTA_NEXT(attr, length)) {
-    switch (attr->rta_type) {
-      case IFA_ADDRESS:
-        DCHECK_GE(RTA_PAYLOAD(attr), address_length);
-        address = reinterpret_cast<uint8_t*>(RTA_DATA(attr));
-        break;
-      case IFA_LOCAL:
-        DCHECK_GE(RTA_PAYLOAD(attr), address_length);
-        local = reinterpret_cast<uint8_t*>(RTA_DATA(attr));
-        break;
-      case IFA_CACHEINFO: {
-        const struct ifa_cacheinfo *cache_info =
-            reinterpret_cast<const struct ifa_cacheinfo*>(RTA_DATA(attr));
-        if (really_deprecated)
-          *really_deprecated = (cache_info->ifa_prefered == 0);
-      } break;
-      default:
-        break;
-    }
-  }
-  if (local)
-    address = local;
-  if (!address)
-    return false;
-  *out = IPAddress(address, address_length);
-  return true;
-}
-
-}  // namespace
-
 // static
 char* AddressTrackerLinux::GetInterfaceName(int interface_index, char* buf) {
-  memset(buf, 0, IFNAMSIZ);
-  base::ScopedFD ioctl_socket = GetSocketForIoctl();
-  if (!ioctl_socket.is_valid())
-    return buf;
-
-  struct ifreq ifr = {};
-  ifr.ifr_ifindex = interface_index;
-
-  if (ioctl(ioctl_socket.get(), SIOCGIFNAME, &ifr) == 0)
-    strncpy(buf, ifr.ifr_name, IFNAMSIZ - 1);
-  return buf;
+  NOTIMPLEMENTED();
+  return NULL;
 }
 
 AddressTrackerLinux::AddressTrackerLinux()
@@ -147,6 +61,7 @@ AddressTrackerLinux::AddressTrackerLinux(
 AddressTrackerLinux::~AddressTrackerLinux() = default;
 
 void AddressTrackerLinux::Init() {
+#if !defined(OS_FREEBSD)
   netlink_fd_.reset(socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE));
   if (!netlink_fd_.is_valid()) {
     PLOG(ERROR) << "Could not create NETLINK socket";
@@ -242,6 +157,7 @@ void AddressTrackerLinux::AbortAndForceOnline() {
   connection_type_initialized_cv_.Broadcast();
 }
 
+#if !defined(OS_BSD)
 AddressTrackerLinux::AddressMap AddressTrackerLinux::GetAddressMap() const {
   AddressTrackerAutoLock lock(*this, address_map_lock_);
   return address_map_;
@@ -260,6 +176,7 @@ bool AddressTrackerLinux::IsInterfaceIgnored(int inter
   const char* interface_name = get_interface_name_(interface_index, buf);
   return ignored_interfaces_.find(interface_name) != ignored_interfaces_.end();
 }
+#endif // !OS_BSD
 
 NetworkChangeNotifier::ConnectionType
 AddressTrackerLinux::GetCurrentConnectionType() {
@@ -318,6 +235,7 @@ void AddressTrackerLinux::HandleMessage(char* buffer,
                                         bool* address_changed,
                                         bool* link_changed,
                                         bool* tunnel_changed) {
+#if !defined(OS_FREEBSD)
   DCHECK(buffer);
   for (struct nlmsghdr* header = reinterpret_cast<struct nlmsghdr*>(buffer);
        NLMSG_OK(header, length);
@@ -414,6 +332,10 @@ void AddressTrackerLinux::HandleMessage(char* buffer,
         break;
     }
   }
+#else  // !OS_FREEBSD
+  NOTIMPLEMENTED();
+  AbortAndForceOnline();
+#endif // !OS_FREEBSD
 }
 
 void AddressTrackerLinux::OnFileCanReadWithoutBlocking() {
@@ -441,31 +363,7 @@ bool AddressTrackerLinux::IsTunnelInterfaceName(const 
 }
 
 void AddressTrackerLinux::UpdateCurrentConnectionType() {
-  AddressTrackerLinux::AddressMap address_map = GetAddressMap();
-  std::unordered_set<int> online_links = GetOnlineLinks();
-
-  // Strip out tunnel interfaces from online_links
-  for (auto it = online_links.cbegin(); it != online_links.cend();) {
-    if (IsTunnelInterface(*it)) {
-      it = online_links.erase(it);
-    } else {
-      ++it;
-    }
-  }
-
-  NetworkInterfaceList networks;
-  NetworkChangeNotifier::ConnectionType type =
-      NetworkChangeNotifier::CONNECTION_NONE;
-  if (GetNetworkListImpl(&networks, 0, online_links, address_map,
-                         get_interface_name_)) {
-    type = NetworkChangeNotifier::ConnectionTypeFromInterfaceList(networks);
-  } else {
-    type = online_links.empty() ? NetworkChangeNotifier::CONNECTION_NONE
-                                : NetworkChangeNotifier::CONNECTION_UNKNOWN;
-  }
-
-  AddressTrackerAutoLock lock(*this, connection_type_lock_);
-  current_connection_type_ = type;
+  NOTIMPLEMENTED();
 }
 
 int AddressTrackerLinux::GetThreadsWaitingForConnectionTypeInitForTesting()
