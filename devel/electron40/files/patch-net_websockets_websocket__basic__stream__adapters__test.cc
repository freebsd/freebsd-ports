--- net/websockets/websocket_basic_stream_adapters_test.cc.orig	2025-10-21 20:19:54 UTC
+++ net/websockets/websocket_basic_stream_adapters_test.cc
@@ -1097,10 +1097,10 @@ TEST_F(WebSocketSpdyStreamAdapterTest,
        OnCloseOkShouldBeTranslatedToConnectionClose) {
   spdy::SpdySerializedFrame response_headers(
       spdy_util_.ConstructSpdyResponseHeaders(1, ResponseHeaders(), false));
-  spdy::SpdySerializedFrame close(
+  spdy::SpdySerializedFrame test_close(
       spdy_util_.ConstructSpdyRstStream(1, spdy::ERROR_CODE_NO_ERROR));
   MockRead reads[] = {CreateMockRead(response_headers, 1),
-                      CreateMockRead(close, 2), MockRead(ASYNC, 0, 3)};
+                      CreateMockRead(test_close, 2), MockRead(ASYNC, 0, 3)};
   spdy::SpdySerializedFrame request_headers(spdy_util_.ConstructSpdyHeaders(
       1, RequestHeaders(), DEFAULT_PRIORITY, false));
   MockWrite writes[] = {CreateMockWrite(request_headers, 0)};
