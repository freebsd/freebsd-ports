--- src/openhbci/core/deskey.cpp.orig	2002-12-10 15:54:07 UTC
+++ src/openhbci/core/deskey.cpp
@@ -42,11 +42,11 @@
 namespace HBCI {
 
 DESKey::DESKey(string password) {
-	des_cblock left, right;
+	DES_cblock left, right;
 	keyData = "";
 	
 	// transform password to 2 keys
-	des_string_to_2keys(password.c_str(), &left, &right);
+	DES_string_to_2keys(password.c_str(), &left, &right);
 	
 	// set the keydata
 	for (int i=0; i<8; i++)
@@ -64,8 +64,8 @@ DESKey::~DESKey(){
 
 DESKey DESKey::createKey() {
 	int result = 1;
-	des_cblock nativeDESKey;
-	des_key_schedule key;
+	DES_cblock nativeDESKey;
+	DES_key_schedule key;
 
 	DESKey *newKey = new DESKey();
 	newKey->keyData = "";
@@ -73,16 +73,16 @@ DESKey DESKey::createKey() {
  	RAND_seed(getRndData(1024), 1024);
 
 	while (result != 0) {
-		des_random_key(&nativeDESKey);
-		result = des_set_key_checked(&nativeDESKey, key);
+		DES_random_key(&nativeDESKey);
+		result = DES_set_key_checked(&nativeDESKey, &key);
 	}
 	for (int i=0; i<8; i++)
 		newKey->keyData += nativeDESKey[i];
 	
  	result = 1;
 	while (result != 0) {
-		des_random_key(&nativeDESKey);
-		result = des_set_key_checked(&nativeDESKey, key);
+		DES_random_key(&nativeDESKey);
+		result = DES_set_key_checked(&nativeDESKey, &key);
 	}
 	for (int i=0; i<8; i++)
 		newKey->keyData += nativeDESKey[i];
@@ -116,24 +116,24 @@ bool DESKey::crypt(int enDeCrypt) {
 	//2-key-tripple-des
 	//dataToCrypt.length() % 8 has to be 0, padding/ depadding in calling method
 	
-	des_cblock left, right;
+	DES_cblock left, right;
 	keyData.copy((char*) &left,8);	
 	keyData.copy((char*) &right,8,8);
 
-	des_cblock initVector;
-	des_key_schedule key1, key2;
+	DES_cblock initVector;
+	DES_key_schedule key1, key2;
 	unsigned char source[intData.length()];
 	unsigned char dest[intData.length()];
 	for (unsigned int i=0; i<intData.length(); i++)
 		source[i]=intData[i];
 		
-	des_set_key(&left, key1);
-	des_set_key(&right, key2);
+	DES_set_key(&left, &key1);
+	DES_set_key(&right, &key2);
 	for (int i=0; i<8; i++)
 		initVector[i] = 0;	
 
-	des_ede2_cbc_encrypt((unsigned char*) &source, (unsigned char*) &dest, intData.length(),
-		key1, key2, &initVector, enDeCrypt);
+	DES_ede2_cbc_encrypt((unsigned char*) &source, (unsigned char*) &dest, intData.length(),
+		&key1, &key2, &initVector, enDeCrypt);
 
 	intData = string((const char*) &dest, intData.length());
 	
