--- bootstrap.sh.orig	2019-12-23 09:00:56 UTC
+++ bootstrap.sh
@@ -230,9 +230,9 @@ TRANS_VER="0.5.5.0";   TRANS_VER_REGEXP="0\.[45]\."
                        # >= 0.2.* && < 0.6
 MTL_VER="2.2.2";       MTL_VER_REGEXP="[2]\."
                        #  >= 2.0 && < 3
-HTTP_VER="4000.3.12";  HTTP_VER_REGEXP="4000\.(2\.([5-9]|1[0-9]|2[0-9])|3\.?)"
+HTTP_VER="4000.3.14";  HTTP_VER_REGEXP="4000\.(2\.([5-9]|1[0-9]|2[0-9])|3\.?)"
                        # >= 4000.2.5 < 4000.4
-ZLIB_VER="0.6.2";      ZLIB_VER_REGEXP="(0\.5\.([3-9]|1[0-9])|0\.6)"
+ZLIB_VER="0.6.2.1";      ZLIB_VER_REGEXP="(0\.5\.([3-9]|1[0-9])|0\.6)"
                        # >= 0.5.3 && <= 0.7
 TIME_VER="1.9.1"       TIME_VER_REGEXP="1\.[1-9]\.?"
                        # >= 1.1 && < 1.10
@@ -240,9 +240,9 @@ RANDOM_VER="1.1"       RANDOM_VER_REGEXP="1\.[01]\.?"
                        # >= 1 && < 1.2
 STM_VER="2.4.5.0";     STM_VER_REGEXP="2\."
                        # == 2.*
-HASHABLE_VER="1.2.7.0"; HASHABLE_VER_REGEXP="1\."
+HASHABLE_VER="1.3.0.0"; HASHABLE_VER_REGEXP="1\."
                        # 1.*
-ASYNC_VER="2.2.1";     ASYNC_VER_REGEXP="2\."
+ASYNC_VER="2.2.2";     ASYNC_VER_REGEXP="2\."
                        # 2.*
 BASE16_BYTESTRING_VER="0.1.1.6"; BASE16_BYTESTRING_VER_REGEXP="0\.1"
                        # 0.1.*
@@ -250,7 +250,7 @@ BASE64_BYTESTRING_VER="1.0.0.1"; BASE64_BYTESTRING_VER
                        # >=1.0
 CRYPTOHASH_SHA256_VER="0.11.101.0"; CRYPTOHASH_SHA256_VER_REGEXP="0\.11\.?"
                        # 0.11.*
-RESOLV_VER="0.1.1.1";  RESOLV_VER_REGEXP="0\.1\.[1-9]"
+RESOLV_VER="0.1.1.3";  RESOLV_VER_REGEXP="0\.1\.[1-9]"
                        # >= 0.1.1 && < 0.2
 MINTTY_VER="0.1.2";    MINTTY_VER_REGEXP="0\.1\.?"
                        # 0.1.*
@@ -262,11 +262,11 @@ ED25519_VER="0.0.5.0"; ED25519_VER_REGEXP="0\.0\.?"
                        # 0.0.*
 HACKAGE_SECURITY_VER="0.6.0.0"; HACKAGE_SECURITY_VER_REGEXP="0\.6\."
                        # >= 0.7.0.0 && < 0.7
-TAR_VER="0.5.1.0";     TAR_VER_REGEXP="0\.5\.([1-9]|1[0-9]|0\.[3-9]|0\.1[0-9])\.?"
+TAR_VER="0.5.1.1";     TAR_VER_REGEXP="0\.5\.([1-9]|1[0-9]|0\.[3-9]|0\.1[0-9])\.?"
                        # >= 0.5.0.3  && < 0.6
 DIGEST_VER="0.0.1.2"; DIGEST_REGEXP="0\.0\.(1\.[2-9]|[2-9]\.?)"
                        # >= 0.0.1.2 && < 0.1
-LUKKO_VER="0.1.1";     LUKKO_VER_REGEXP="0\.1\.[1-9]"
+LUKKO_VER="0.1.1.1";     LUKKO_VER_REGEXP="0\.1\.[1-9]"
                        # >= 0.1.1 && <0.2
 
 HACKAGE_URL="https://hackage.haskell.org/package"
