--- adminer/include/xxtea.inc.php.orig	2025-11-14 10:44:16 UTC
+++ adminer/include/xxtea.inc.php
@@ -45,6 +45,11 @@
 	return int32((($z >> 5 & 0x7FFFFFF) ^ $y << 2) + (($y >> 3 & 0x1FFFFFFF) ^ $z << 4)) ^ int32(($sum ^ $y) + ($k ^ $z));
 }
 
+const AES256_NAME = 'aes-256-gcm';
+const AES256_KEY_BYTES = 32;
+const AES256_NONCE_BYTES = 12;
+const AES256_TAG_BYTES = 16;
+
 /** Cipher
 * @param string $str plain-text password
 * @return string binary cipher
@@ -53,6 +58,20 @@
 	if ($str == "") {
 		return "";
 	}
+	$key = hash_hkdf('sha256', $key, AES256_KEY_BYTES, AES256_NAME);
+	$nonce = random_bytes(AES256_NONCE_BYTES);
+	$cipherText = openssl_encrypt(
+		$str,
+		AES256_NAME,
+		$key,
+		OPENSSL_RAW_DATA,
+		$nonce,
+		$tag,
+		'',
+		AES256_TAG_BYTES
+	);
+	return $nonce . $tag . $cipherText;
+/*
 	$key = array_values(unpack("V*", pack("H*", md5($key))));
 	$v = str2long($str, true);
 	$n = count($v) - 1;
@@ -75,6 +94,7 @@
 		$v[$n] = $z;
 	}
 	return long2str($v, false);
+*/
 }
 
 /** Decipher
@@ -88,6 +108,20 @@
 	if (!$key) {
 		return false;
 	}
+	$key = hash_hkdf('sha256', $key, AES256_KEY_BYTES, AES256_NAME);
+	$nonce = substr($str, 0, AES256_NONCE_BYTES);
+	$tag = substr($str, AES256_NONCE_BYTES, AES256_TAG_BYTES);
+	$cipherText = substr($str, AES256_NONCE_BYTES + AES256_TAG_BYTES);
+	return openssl_decrypt(
+		$cipherText,
+		AES256_NAME,
+		$key,
+		OPENSSL_RAW_DATA,
+		$nonce,
+		$tag,
+		''
+	);
+/*
 	$key = array_values(unpack("V*", pack("H*", md5($key))));
 	$v = str2long($str, false);
 	$n = count($v) - 1;
@@ -110,4 +144,5 @@
 		$sum = int32($sum - 0x9E3779B9);
 	}
 	return long2str($v, true);
+*/
 }
