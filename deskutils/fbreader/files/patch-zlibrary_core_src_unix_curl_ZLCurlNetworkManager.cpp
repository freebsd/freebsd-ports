--- zlibrary/core/src/unix/curl/ZLCurlNetworkManager.cpp.orig	2014-01-11 12:45:25 UTC
+++ zlibrary/core/src/unix/curl/ZLCurlNetworkManager.cpp
@@ -285,9 +285,11 @@ std::string ZLCurlNetworkManager::perfor
 #endif
 					errors.insert(ZLStringUtil::printf(errorResource["peerFailedVerificationMessage"].value(), ZLNetworkUtil::hostFromUrl(url)));
 					break;
+#if LIBCURL_VERSION_NUM < 0x073e00
 				case CURLE_SSL_CACERT:
 					errors.insert(ZLStringUtil::printf(errorResource["sslCertificateAuthorityMessage"].value(), ZLNetworkUtil::hostFromUrl(url)));
 					break;
+#endif
 				case CURLE_SSL_CACERT_BADFILE:
 					errors.insert(ZLStringUtil::printf(errorResource["sslBadCertificateFileMessage"].value(), request.sslCertificate().Path));
 					break;
