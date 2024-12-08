--- client/ServerRunner.h.orig	2024-08-25 21:27:47 UTC
+++ client/ServerRunner.h
@@ -45,7 +45,7 @@ class ServerThreadRunner : public IServerRunner, boost
 
 #ifndef VCMI_MOBILE
 
-namespace boost::process {
+namespace boost::process::v1 {
 class child;
 }
 
@@ -53,7 +53,7 @@ class child;
 /// Available only on desktop systems where process management is allowed
 class ServerProcessRunner : public IServerRunner, boost::noncopyable
 {
-	std::unique_ptr<boost::process::child> child;
+	std::unique_ptr<boost::process::v1::child> child;
 
 public:
 	void start(uint16_t port, bool connectToLobby, std::shared_ptr<StartInfo> startingInfo) override;
