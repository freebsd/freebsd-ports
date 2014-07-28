*** tosha.c.orig	Fri Jan  1 16:57:49 1999
--- tosha.c	Wed Feb  7 13:29:21 2001
***************
*** 240,247 ****
  		return template;
  	if (!(tmpstr = malloc(strlen(template) + strlen(formatspec->ext) - 1)))
  		out_of_memory();
! 	if ((prefix = cptr - template))
  		strncpy (tmpstr, template, prefix);
  	strcat (tmpstr + prefix, formatspec->ext);
  	prefix += strlen(formatspec->ext);
  	strcat (tmpstr + prefix, cptr + 2);
--- 240,249 ----
  		return template;
  	if (!(tmpstr = malloc(strlen(template) + strlen(formatspec->ext) - 1)))
  		out_of_memory();
! 	if ((prefix = cptr - template)) {
  		strncpy (tmpstr, template, prefix);
+ 		tmpstr[prefix] = '\0';
+ 	}
  	strcat (tmpstr + prefix, formatspec->ext);
  	prefix += strlen(formatspec->ext);
  	strcat (tmpstr + prefix, cptr + 2);
***************
*** 369,379 ****
  				frmctl = trackctl[i];
  				break;
  			}
! 		if (frmctl < 0) /* Ugh! */
  			if (numtracks >= 1 && start >= trackstart[1])
  				frmctl = trackctl[numtracks - 1];
  			else
  				frmctl = trackctl[0];
  	}
  	if ((frmctl & 4) == 0)
  		return 1;
--- 371,382 ----
  				frmctl = trackctl[i];
  				break;
  			}
! 		if (frmctl < 0) { /* Ugh! */
  			if (numtracks >= 1 && start >= trackstart[1])
  				frmctl = trackctl[numtracks - 1];
  			else
  				frmctl = trackctl[0];
+ 		}
  	}
  	if ((frmctl & 4) == 0)
  		return 1;
***************
*** 698,704 ****
  	 *   Now get us the stuff!
  	 */
  
! 	if (!indexonly && (singlefile = startsec >= 0 || !strchr(outname, '%')))
  		if (!strcmp(outname, "-"))
  			pcmfd = 1;
  		else {
--- 701,707 ----
  	 *   Now get us the stuff!
  	 */
  
! 	if (!indexonly && (singlefile = startsec >= 0 || !strchr(outname, '%'))){
  		if (!strcmp(outname, "-"))
  			pcmfd = 1;
  		else {
***************
*** 710,715 ****
--- 713,719 ----
  					O_TRUNC, 0644)) < 0)
  				die ("open(output file)");
  		}
+ 	}
  	if (!quiet)
  		print_head();
  	get_time (&starttime);
