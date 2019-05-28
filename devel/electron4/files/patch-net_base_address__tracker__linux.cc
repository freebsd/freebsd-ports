--- net/base/address_tracker_linux.cc.orig	2019-03-15 06:37:29 UTC
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
@@ -153,93 +67,8 @@ AddressTrackerLinux::~AddressTrackerLinux() {
 }
 
 void AddressTrackerLinux::Init() {
-  netlink_fd_ = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
-  if (netlink_fd_ < 0) {
-    PLOG(ERROR) << "Could not create NETLINK socket";
-    AbortAndForceOnline();
-    return;
-  }
-
-  int rv;
-
-  if (tracking_) {
-    // Request notifications.
-    struct sockaddr_nl addr = {};
-    addr.nl_family = AF_NETLINK;
-    addr.nl_pid = getpid();
-    // TODO(szym): Track RTMGRP_LINK as well for ifi_type,
-    // http://crbug.com/113993
-    addr.nl_groups =
-        RTMGRP_IPV4_IFADDR | RTMGRP_IPV6_IFADDR | RTMGRP_NOTIFY | RTMGRP_LINK;
-    rv = bind(
-        netlink_fd_, reinterpret_cast<struct sockaddr*>(&addr), sizeof(addr));
-    if (rv < 0) {
-      PLOG(ERROR) << "Could not bind NETLINK socket";
-      AbortAndForceOnline();
-      return;
-    }
-  }
-
-  // Request dump of addresses.
-  struct sockaddr_nl peer = {};
-  peer.nl_family = AF_NETLINK;
-
-  struct {
-    struct nlmsghdr header;
-    struct rtgenmsg msg;
-  } request = {};
-
-  request.header.nlmsg_len = NLMSG_LENGTH(sizeof(request.msg));
-  request.header.nlmsg_type = RTM_GETADDR;
-  request.header.nlmsg_flags = NLM_F_REQUEST | NLM_F_DUMP;
-  request.header.nlmsg_pid = getpid();
-  request.msg.rtgen_family = AF_UNSPEC;
-
-  rv = HANDLE_EINTR(sendto(netlink_fd_, &request, request.header.nlmsg_len,
-                           0, reinterpret_cast<struct sockaddr*>(&peer),
-                           sizeof(peer)));
-  if (rv < 0) {
-    PLOG(ERROR) << "Could not send NETLINK request";
-    AbortAndForceOnline();
-    return;
-  }
-
-  // Consume pending message to populate the AddressMap, but don't notify.
-  // Sending another request without first reading responses results in EBUSY.
-  bool address_changed;
-  bool link_changed;
-  bool tunnel_changed;
-  ReadMessages(&address_changed, &link_changed, &tunnel_changed);
-
-  // Request dump of link state
-  request.header.nlmsg_type = RTM_GETLINK;
-
-  rv = HANDLE_EINTR(sendto(netlink_fd_, &request, request.header.nlmsg_len, 0,
-                           reinterpret_cast<struct sockaddr*>(&peer),
-                           sizeof(peer)));
-  if (rv < 0) {
-    PLOG(ERROR) << "Could not send NETLINK request";
-    AbortAndForceOnline();
-    return;
-  }
-
-  // Consume pending message to populate links_online_, but don't notify.
-  ReadMessages(&address_changed, &link_changed, &tunnel_changed);
-  {
-    AddressTrackerAutoLock lock(*this, connection_type_lock_);
-    connection_type_initialized_ = true;
-    connection_type_initialized_cv_.Broadcast();
-  }
-
-  if (tracking_) {
-    rv = base::MessageLoopCurrentForIO::Get()->WatchFileDescriptor(
-        netlink_fd_, true, base::MessagePumpForIO::WATCH_READ, &watcher_, this);
-    if (rv < 0) {
-      PLOG(ERROR) << "Could not watch NETLINK socket";
-      AbortAndForceOnline();
-      return;
-    }
-  }
+NOTIMPLEMENTED();
+AbortAndForceOnline();
 }
 
 void AddressTrackerLinux::AbortAndForceOnline() {
@@ -250,25 +79,6 @@ void AddressTrackerLinux::AbortAndForceOnline() {
   connection_type_initialized_cv_.Broadcast();
 }
 
-AddressTrackerLinux::AddressMap AddressTrackerLinux::GetAddressMap() const {
-  AddressTrackerAutoLock lock(*this, address_map_lock_);
-  return address_map_;
-}
-
-std::unordered_set<int> AddressTrackerLinux::GetOnlineLinks() const {
-  AddressTrackerAutoLock lock(*this, online_links_lock_);
-  return online_links_;
-}
-
-bool AddressTrackerLinux::IsInterfaceIgnored(int interface_index) const {
-  if (ignored_interfaces_.empty())
-    return false;
-
-  char buf[IFNAMSIZ] = {0};
-  const char* interface_name = get_interface_name_(interface_index, buf);
-  return ignored_interfaces_.find(interface_name) != ignored_interfaces_.end();
-}
-
 NetworkChangeNotifier::ConnectionType
 AddressTrackerLinux::GetCurrentConnectionType() {
   // http://crbug.com/125097
@@ -323,6 +133,7 @@ void AddressTrackerLinux::HandleMessage(char* buffer,
                                         bool* address_changed,
                                         bool* link_changed,
                                         bool* tunnel_changed) {
+#if !defined(OS_BSD)
   DCHECK(buffer);
   for (struct nlmsghdr* header = reinterpret_cast<struct nlmsghdr*>(buffer);
        NLMSG_OK(header, length);
@@ -419,6 +230,9 @@ void AddressTrackerLinux::HandleMessage(char* buffer,
         break;
     }
   }
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 void AddressTrackerLinux::OnFileCanReadWithoutBlocking(int fd) {
@@ -455,6 +269,7 @@ bool AddressTrackerLinux::IsTunnelInterfaceName(const 
 }
 
 void AddressTrackerLinux::UpdateCurrentConnectionType() {
+#if !defined(OS_BSD)
   AddressTrackerLinux::AddressMap address_map = GetAddressMap();
   std::unordered_set<int> online_links = GetOnlineLinks();
 
@@ -483,6 +298,9 @@ void AddressTrackerLinux::UpdateCurrentConnectionType(
 
   AddressTrackerAutoLock lock(*this, connection_type_lock_);
   current_connection_type_ = type;
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 int AddressTrackerLinux::GetThreadsWaitingForConnectionTypeInitForTesting()
