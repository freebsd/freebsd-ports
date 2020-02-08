--- src/utils/transmit_camp.cxx.orig	2020-02-08 03:12:42 UTC
+++ src/utils/transmit_camp.cxx
@@ -285,7 +285,7 @@ void * create_tx_table(void *ptr)
 
 			LOG_DEBUG("Mode %s overhead=%f", mode_name.c_str(), overhead);
 
-			fprintf(fd, "\t{\n\t\t(char *) \"%s\", 1.0, "P_RELSOL2", \n\t\t{\n\t\t\t", mode_name.c_str(), overhead);
+			fprintf(fd, "\t{\n\t\t(char *) \"%s\", 1.0, " P_RELSOL2 ", \n\t\t{\n\t\t\t", mode_name.c_str(), overhead);
 			fflush(fd);
 
 			if(mode_name.find("Olivia") != string::npos || mode_name.find("MT63") != string::npos) {
