--- net/socket/udp_socket_unittest.cc.orig	2022-05-19 05:17:45 UTC
+++ net/socket/udp_socket_unittest.cc
@@ -324,7 +324,7 @@ TEST_F(UDPSocketTest, PartialRecv) {
   EXPECT_EQ(second_packet, received);
 }
 
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // - MacOS: requires root permissions on OSX 10.7+.
 // - Android: devices attached to testbots don't have default network, so
 // broadcasting to 255.255.255.255 returns error -109 (Address not reachable).
@@ -584,7 +584,7 @@ TEST_F(UDPSocketTest, ClientSetDoNotFragment) {
     EXPECT_THAT(rv, IsOk());
 
     rv = client.SetDoNotFragment();
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/945590): IP_MTU_DISCOVER is not implemented on Fuchsia.
     EXPECT_THAT(rv, IsError(ERR_NOT_IMPLEMENTED));
 #else
@@ -606,7 +606,7 @@ TEST_F(UDPSocketTest, ServerSetDoNotFragment) {
     EXPECT_THAT(rv, IsOk());
 
     rv = server.SetDoNotFragment();
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/945590): IP_MTU_DISCOVER is not implemented on Fuchsia.
     EXPECT_THAT(rv, IsError(ERR_NOT_IMPLEMENTED));
 #else
@@ -665,7 +665,7 @@ TEST_F(UDPSocketTest, JoinMulticastGroup) {
 
 // TODO(https://crbug.com/947115): failing on device on iOS 12.2.
 // TODO(https://crbug.com/1227554): flaky on Mac 11.
-#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #define MAYBE_SharedMulticastAddress DISABLED_SharedMulticastAddress
 #else
 #define MAYBE_SharedMulticastAddress SharedMulticastAddress
@@ -719,7 +719,7 @@ TEST_F(UDPSocketTest, MAYBE_SharedMulticastAddress) {
                                 NetLogSource());
   ASSERT_THAT(client_socket.Connect(send_address), IsOk());
 
-#if !BUILDFLAG(IS_CHROMEOS_ASH)
+#if !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_BSD)
   // Send a message via the multicast group. That message is expected be be
   // received by both receving sockets.
   //
