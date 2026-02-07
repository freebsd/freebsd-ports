--- src/header.c.orig	2000-10-05 17:36:03 UTC
+++ src/header.c
@@ -320,8 +320,8 @@ generic_to_unix_stamp(t)
 	dostm.tm_min = t >> 5 & 0x3f;
 	dostm.tm_hour = t >> 11 & 0x1f;
 	dostm.tm_mday = t >> 16 & 0x1f;
-	dostm.tm_mon = (t >> 16 + 5 & 0x0f) - 1;	/* 0..11 */
-	dostm.tm_year = (t >> 16 + 9 & 0x7f) + 80;
+	dostm.tm_mon = (t >> (16 + 5) & 0x0f) - 1;	/* 0..11 */
+	dostm.tm_year = (t >> (16 + 9) & 0x7f) + 80;
 #if 0
 	dostm.tm_isdst = 0;	/* correct? */
 #endif
@@ -538,6 +538,10 @@ get_header(fp, hdr)
 				/*
 				 * filename
 				 */
+				if (header_size >= 256) {
+				  fprintf(stderr, "Possible buffer overflow hack attack, type #1\n");
+				  exit(109);
+				}
 				for (i = 0; i < header_size - 3; i++)
 					hdr->name[i] = (char) get_byte();
 				hdr->name[header_size - 3] = '\0';
@@ -547,6 +551,10 @@ get_header(fp, hdr)
 				/*
 				 * directory
 				 */
+				if (header_size >= FILENAME_LENGTH) {
+				  fprintf(stderr, "Possible buffer overflow hack attack, type #2\n");
+				  exit(110);
+				}
 				for (i = 0; i < header_size - 3; i++)
 					dirname[i] = (char) get_byte();
 				dirname[header_size - 3] = '\0';
@@ -648,8 +656,16 @@ get_header(fp, hdr)
 	}
 
 	if (dir_length) {
+		if ((dir_length + name_length) >= sizeof(dirname)) {
+			fprintf(stderr, "Insufficient buffer size\n");
+			exit(112);
+		}
 		strcat(dirname, hdr->name);
-		strcpy(hdr->name, dirname);
+		if ((dir_length + name_length) >= sizeof(hdr->name)) {
+			fprintf(stderr, "Insufficient buffer size\n");
+			exit(112);
+		}
+		strncpy(hdr->name, dirname, sizeof(hdr->name));
 		name_length += dir_length;
 	}
 
@@ -754,7 +770,7 @@ write_header(nafp, hdr)
 
 	convdelim(hdr->name, DELIM2);
 	if (hdr->header_level != HEADER_LEVEL2) {
-		if (p = (char *) rindex(hdr->name, DELIM2))
+		if ((p = (char *) rindex(hdr->name, DELIM2)))
 			name_length = strlen(++p);
 		else
 			name_length = strlen(hdr->name);
@@ -812,7 +828,7 @@ write_header(nafp, hdr)
 			put_word(hdr->unix_gid);
 			put_word(hdr->unix_uid);
 
-			if (p = (char *) rindex(hdr->name, DELIM2)) {
+			if ((p = (char *) rindex(hdr->name, DELIM2))) {
 				int             i;
 
 				name_length = p - hdr->name + 1;
@@ -838,7 +854,7 @@ write_header(nafp, hdr)
 			data[I_HEADER_CHECKSUM] = calc_sum(data + I_METHOD, header_size);
 		} else {		/* header level 2 */
 			int             i;
-			if (p = (char *) rindex(hdr->name, DELIM2))
+			if ((p = (char *) rindex(hdr->name, DELIM2)))
 				name_length = strlen(++p);
 			else {
 				p = hdr->name;
