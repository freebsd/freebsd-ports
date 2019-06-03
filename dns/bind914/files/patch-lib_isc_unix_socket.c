From e517c18d98c248e891558ce5194e3663d244f956 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Witold=20Kr=C4=99cicki?= <wpk@isc.org>
Date: Fri, 31 May 2019 10:40:52 +0200
Subject: [PATCH 1/2] Fix a possible race between udp dispatch and socket code

There's a small possibility of race between udp dispatcher and
socket code - socket code can still hold internal reference to a
socket while dispatcher calls isc_socket_open, which can cause
an assertion failure. Fix it by relaxing the assertion test, and
instead simply locking the socket in isc_socket_open.

--- lib/isc/unix/socket.c.orig	2019-05-10 04:51:34 UTC
+++ lib/isc/unix/socket.c
@@ -2598,15 +2598,16 @@ isc_socket_open(isc_socket_t *sock0) {
 
 	REQUIRE(VALID_SOCKET(sock));
 
-	REQUIRE(isc_refcount_current(&sock->references) == 1);
-	/*
-	 * We don't need to retain the lock hereafter, since no one else has
-	 * this socket.
-	 */
+	LOCK(&sock->lock);
+
+	REQUIRE(isc_refcount_current(&sock->references) >= 1);
 	REQUIRE(sock->fd == -1);
 	REQUIRE(sock->threadid == -1);
 
 	result = opensocket(sock->manager, sock, NULL);
+
+	UNLOCK(&sock->lock);
+
 	if (result != ISC_R_SUCCESS) {
 		sock->fd = -1;
 	} else {
