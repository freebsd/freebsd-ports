--- fowsr.c.orig	2016-09-18 13:31:19 UTC
+++ fowsr.c
@@ -321,6 +321,7 @@ void CWS_Cache(char isStoring)
 	
 	if (isStoring == WS_CACHE_READ) {
 		if (f=fopen(fname,"rb")) {
+			printf("using cache file %s\n", fname);          
 			n=fread(&m_previous_timestamp,sizeof(m_previous_timestamp),1,f);
 			n=fread(m_buf,sizeof(m_buf[0]),WS_BUFFER_SIZE,f);
 		}
@@ -691,6 +692,7 @@ int CWF_Write(char arg, const char* fnam
 		f = fopen(s1,"a+t");
 		if(!f)
 			return -1;
+        printf("writing to %s\n", s1);
 	}
 
 	if((old_pos==0)||(old_pos==0xFFFF))	//cachefile empty or empty eeprom was read
