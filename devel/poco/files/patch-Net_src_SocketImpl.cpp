--- Net/src/SocketImpl.cpp.orig	2017-03-06 05:45:17 UTC
+++ Net/src/SocketImpl.cpp
@@ -473,7 +473,7 @@ bool SocketImpl::poll(const Poco::Timesp
 		}
 	}
 	while (rc < 0 && lastError() == POCO_EINTR);
-	if (rc < 0) error(errorCode);
+	if (rc < 0) error();
 	return rc > 0; 
 
 #else
