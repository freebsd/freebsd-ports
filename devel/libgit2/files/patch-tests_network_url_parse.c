--- tests/network/url/parse.c.orig	2021-09-27 20:09:50 UTC
+++ tests/network/url/parse.c
@@ -63,18 +63,6 @@ void test_network_url_parse__hostname_implied_root_cus
 	cl_assert_equal_i(git_net_url_is_default_port(&conndata), 0);
 }
 
-void test_network_url_parse__hostname_implied_root_empty_port(void)
-{
-	cl_git_pass(git_net_url_parse(&conndata, "http://example.com:"));
-	cl_assert_equal_s(conndata.scheme, "http");
-	cl_assert_equal_s(conndata.host, "example.com");
-	cl_assert_equal_s(conndata.port, "80");
-	cl_assert_equal_s(conndata.path, "/");
-	cl_assert_equal_p(conndata.username, NULL);
-	cl_assert_equal_p(conndata.password, NULL);
-	cl_assert_equal_i(git_net_url_is_default_port(&conndata), 1);
-}
-
 void test_network_url_parse__hostname_encoded_password(void)
 {
 	cl_git_pass(git_net_url_parse(&conndata,
@@ -129,18 +117,6 @@ void test_network_url_parse__hostname_port(void)
 	cl_assert_equal_i(git_net_url_is_default_port(&conndata), 0);
 }
 
-void test_network_url_parse__hostname_empty_port(void)
-{
-	cl_git_pass(git_net_url_parse(&conndata, "http://example.com:/resource"));
-	cl_assert_equal_s(conndata.scheme, "http");
-	cl_assert_equal_s(conndata.host, "example.com");
-	cl_assert_equal_s(conndata.port, "80");
-	cl_assert_equal_s(conndata.path, "/resource");
-	cl_assert_equal_p(conndata.username, NULL);
-	cl_assert_equal_p(conndata.password, NULL);
-	cl_assert_equal_i(git_net_url_is_default_port(&conndata), 1);
-}
-
 void test_network_url_parse__hostname_user_port(void)
 {
 	/* user@hostname.tld:port/resource */
@@ -219,18 +195,6 @@ void test_network_url_parse__ipv4_implied_root_custom_
 	cl_assert_equal_i(git_net_url_is_default_port(&conndata), 0);
 }
 
-void test_network_url_parse__ipv4_implied_root_empty_port(void)
-{
-	cl_git_pass(git_net_url_parse(&conndata, "http://192.168.1.1:"));
-	cl_assert_equal_s(conndata.scheme, "http");
-	cl_assert_equal_s(conndata.host, "192.168.1.1");
-	cl_assert_equal_s(conndata.port, "80");
-	cl_assert_equal_s(conndata.path, "/");
-	cl_assert_equal_p(conndata.username, NULL);
-	cl_assert_equal_p(conndata.password, NULL);
-	cl_assert_equal_i(git_net_url_is_default_port(&conndata), 1);
-}
-
 void test_network_url_parse__ipv4_encoded_password(void)
 {
 	cl_git_pass(git_net_url_parse(&conndata,
@@ -283,18 +247,6 @@ void test_network_url_parse__ipv4_port(void)
 	cl_assert_equal_i(git_net_url_is_default_port(&conndata), 0);
 }
 
-void test_network_url_parse__ipv4_empty_port(void)
-{
-	cl_git_pass(git_net_url_parse(&conndata, "http://192.168.1.1:/resource"));
-	cl_assert_equal_s(conndata.scheme, "http");
-	cl_assert_equal_s(conndata.host, "192.168.1.1");
-	cl_assert_equal_s(conndata.port, "80");
-	cl_assert_equal_s(conndata.path, "/resource");
-	cl_assert_equal_p(conndata.username, NULL);
-	cl_assert_equal_p(conndata.password, NULL);
-	cl_assert_equal_i(git_net_url_is_default_port(&conndata), 1);
-}
-
 void test_network_url_parse__ipv4_user_port(void)
 {
 	cl_git_pass(git_net_url_parse(&conndata,
@@ -371,18 +323,6 @@ void test_network_url_parse__ipv6_implied_root_custom_
 	cl_assert_equal_i(git_net_url_is_default_port(&conndata), 0);
 }
 
-void test_network_url_parse__ipv6_implied_root_empty_port(void)
-{
-	cl_git_pass(git_net_url_parse(&conndata, "http://[fe80::dcad:beff:fe00:0001]:"));
-	cl_assert_equal_s(conndata.scheme, "http");
-	cl_assert_equal_s(conndata.host, "fe80::dcad:beff:fe00:0001");
-	cl_assert_equal_s(conndata.port, "80");
-	cl_assert_equal_s(conndata.path, "/");
-	cl_assert_equal_p(conndata.username, NULL);
-	cl_assert_equal_p(conndata.password, NULL);
-	cl_assert_equal_i(git_net_url_is_default_port(&conndata), 1);
-}
-
 void test_network_url_parse__ipv6_encoded_password(void)
 {
 	cl_git_pass(git_net_url_parse(&conndata,
@@ -433,18 +373,6 @@ void test_network_url_parse__ipv6_port(void)
 	cl_assert_equal_p(conndata.username, NULL);
 	cl_assert_equal_p(conndata.password, NULL);
 	cl_assert_equal_i(git_net_url_is_default_port(&conndata), 0);
-}
-
-void test_network_url_parse__ipv6_empty_port(void)
-{
-	cl_git_pass(git_net_url_parse(&conndata, "http://[fe80::dcad:beff:fe00:0001]:/resource"));
-	cl_assert_equal_s(conndata.scheme, "http");
-	cl_assert_equal_s(conndata.host, "fe80::dcad:beff:fe00:0001");
-	cl_assert_equal_s(conndata.port, "80");
-	cl_assert_equal_s(conndata.path, "/resource");
-	cl_assert_equal_p(conndata.username, NULL);
-	cl_assert_equal_p(conndata.password, NULL);
-	cl_assert_equal_i(git_net_url_is_default_port(&conndata), 1);
 }
 
 void test_network_url_parse__ipv6_user_port(void)
