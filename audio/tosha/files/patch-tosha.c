--- tosha.c.orig	1999-01-01 23:57:49 UTC
+++ tosha.c
@@ -240,8 +240,10 @@ resolve_extension (char *template)
 		return template;
 	if (!(tmpstr = malloc(strlen(template) + strlen(formatspec->ext) - 1)))
 		out_of_memory();
-	if ((prefix = cptr - template))
+	if ((prefix = cptr - template)) {
 		strncpy (tmpstr, template, prefix);
+		tmpstr[prefix] = '\0';
+	}
 	strcat (tmpstr + prefix, formatspec->ext);
 	prefix += strlen(formatspec->ext);
 	strcat (tmpstr + prefix, cptr + 2);
@@ -369,11 +371,12 @@ is_audio (int track, ulong start)
 				frmctl = trackctl[i];
 				break;
 			}
-		if (frmctl < 0) /* Ugh! */
+		if (frmctl < 0) { /* Ugh! */
 			if (numtracks >= 1 && start >= trackstart[1])
 				frmctl = trackctl[numtracks - 1];
 			else
 				frmctl = trackctl[0];
+		}
 	}
 	if ((frmctl & 4) == 0)
 		return 1;
@@ -698,7 +701,7 @@ main (int argc, char *argv[])
 	 *   Now get us the stuff!
 	 */
 
-	if (!indexonly && (singlefile = startsec >= 0 || !strchr(outname, '%')))
+	if (!indexonly && (singlefile = startsec >= 0 || !strchr(outname, '%'))){
 		if (!strcmp(outname, "-"))
 			pcmfd = 1;
 		else {
@@ -710,6 +713,7 @@ main (int argc, char *argv[])
 					O_TRUNC, 0644)) < 0)
 				die ("open(output file)");
 		}
+	}
 	if (!quiet)
 		print_head();
 	get_time (&starttime);
