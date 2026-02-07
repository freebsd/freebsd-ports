--- net/quic/quic_network_transaction_unittest.cc.orig	2025-04-22 20:15:27 UTC
+++ net/quic/quic_network_transaction_unittest.cc
@@ -5202,10 +5202,10 @@ TEST_P(QuicNetworkTransactionTest, BrokenAlternateProt
 
 TEST_P(QuicNetworkTransactionTest, BrokenAlternateProtocol) {
   // Alternate-protocol job
-  std::unique_ptr<quic::QuicEncryptedPacket> close(
+  std::unique_ptr<quic::QuicEncryptedPacket> test_close(
       ConstructServerConnectionClosePacket(1));
   MockRead quic_reads[] = {
-      MockRead(ASYNC, close->data(), close->length()),
+      MockRead(ASYNC, test_close->data(), test_close->length()),
       MockRead(ASYNC, ERR_IO_PENDING),  // No more data to read
       MockRead(ASYNC, OK),              // EOF
   };
@@ -5248,10 +5248,10 @@ TEST_P(QuicNetworkTransactionTest,
   http_server_properties_ = std::make_unique<HttpServerProperties>();
 
   // Alternate-protocol job
-  std::unique_ptr<quic::QuicEncryptedPacket> close(
+  std::unique_ptr<quic::QuicEncryptedPacket> test_close(
       ConstructServerConnectionClosePacket(1));
   MockRead quic_reads[] = {
-      MockRead(ASYNC, close->data(), close->length()),
+      MockRead(ASYNC, test_close->data(), test_close->length()),
       MockRead(ASYNC, ERR_IO_PENDING),  // No more data to read
       MockRead(ASYNC, OK),              // EOF
   };
