--- ext/em.cpp.orig	2018-01-18 19:46:12 UTC
+++ ext/em.cpp
@@ -375,7 +375,7 @@ void EventMachine_t::_InitializeLoopBrea
 	for (i=0; i < 100; i++) {
 		int r = (rand() % 10000) + 20000;
 		LoopBreakerTarget.sin_port = htons (r);
-		if (bind (sd, (struct sockaddr*)&LoopBreakerTarget, sizeof(LoopBreakerTarget)) == 0)
+		if (::bind (sd, (struct sockaddr*)&LoopBreakerTarget, sizeof(LoopBreakerTarget)) == 0)
 			break;
 	}
 
@@ -1239,7 +1239,7 @@ const uintptr_t EventMachine_t::ConnectT
 			snprintf (buf, sizeof(buf)-1, "invalid bind address: %s", gai_strerror(gai));
 			throw std::runtime_error (buf);
 		}
-		if (bind (sd, (struct sockaddr *)&bind_to, bind_to_len) < 0) {
+		if (::bind (sd, (struct sockaddr *)&bind_to, bind_to_len) < 0) {
 			close (sd);
 			throw std::runtime_error ("couldn't bind to address");
 		}
@@ -1620,7 +1620,7 @@ const uintptr_t EventMachine_t::CreateTc
 	}
 
 
-	if (bind (sd_accept, (struct sockaddr *)&bind_here, bind_here_len)) {
+	if (::bind (sd_accept, (struct sockaddr *)&bind_here, bind_here_len)) {
 		//__warning ("binding failed");
 		goto fail;
 	}
@@ -1667,7 +1667,7 @@ const uintptr_t EventMachine_t::OpenData
 	if (!SetSocketNonblocking (sd))
 		goto fail;
 
-	if (bind (sd, (struct sockaddr *)&bind_here, bind_here_len) != 0)
+	if (::bind (sd, (struct sockaddr *)&bind_here, bind_here_len) != 0)
 		goto fail;
 
 	{ // Looking good.
@@ -1953,7 +1953,7 @@ const uintptr_t EventMachine_t::CreateUn
 		#endif
 	}
 
-	if (bind (sd_accept, (struct sockaddr*)&s_sun, sizeof(s_sun))) {
+	if (::bind (sd_accept, (struct sockaddr*)&s_sun, sizeof(s_sun))) {
 		//__warning ("binding failed");
 		goto fail;
 	}
