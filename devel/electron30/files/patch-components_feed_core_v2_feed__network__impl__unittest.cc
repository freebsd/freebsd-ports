--- components/feed/core/v2/feed_network_impl_unittest.cc.orig	2023-11-29 21:39:58 UTC
+++ components/feed/core/v2/feed_network_impl_unittest.cc
@@ -781,8 +781,8 @@ TEST_F(FeedNetworkTest, SendApiRequest_DecodesClientIn
 
   EXPECT_EQ(feedwire::ClientInfo::CHROME_ANDROID, client_info.app_type());
   EXPECT_EQ(feedwire::Version::RELEASE, client_info.app_version().build_type());
-  EXPECT_EQ(1, client_info.app_version().major());
-  EXPECT_EQ(2, client_info.app_version().minor());
+  EXPECT_EQ(1, client_info.app_version().gmajor());
+  EXPECT_EQ(2, client_info.app_version().gminor());
   EXPECT_EQ(3, client_info.app_version().build());
   EXPECT_EQ(4, client_info.app_version().revision());
   EXPECT_FALSE(client_info.chrome_client_info().start_surface());
