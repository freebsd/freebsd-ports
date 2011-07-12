 --- lib/getcap.c	30 Sep 2008 08:02:59 -0000	1.1.1.1
 +++ lib/getcap.c	23 Oct 2008 09:24:33 -0000
 @@ -73,8 +73,10 @@
  		fprintf(stderr, "cap %s redefined (default %s)\r\n", name,
  			def_value ? def_value : "None");
  #endif
 +		SafeFree(cp->name);
  		cp->name = strdup(name);
  		cp->func = func;
 +		SafeFree(cp->def_value);
  		if (def_value)
  			cp->def_value = strdup(def_value);
  		return;
 @@ -86,8 +88,10 @@
  			fprintf(stderr, "cap %s defined (default %s)\r\n", name,
  				def_value ? def_value : "None");
  #endif
 +			SafeFree(cp->name);
  			cp->name = strdup(name);
  			cp->func = func;
 +			SafeFree(cp->def_value);
  			if (def_value)
  				cp->def_value = strdup(def_value);
  			return;
 @@ -110,12 +114,9 @@
  			fprintf(stderr, "cap %s deleted\r\n", cp->name);
  #endif
  		cp->initialized = 0;
 -		if (cp->name)
 -			free(cp->name);
 -		if (cp->arg)
 -			free(cp->arg);
 -		if (cp->def_value)
 -			free(cp->def_value);
 +		SafeFree(cp->name);
 +		SafeFree(cp->arg);
 +		SafeFree(cp->def_value);
  		cp->name = cp->arg = cp->def_value = NULL;
  	}
  }
 @@ -149,10 +150,13 @@
  			if ((c = FindCap(p)) != NULL) {
  				/* Found matching capability.  Get body from file. */
  				char *l = buf;
 +				int bnum = 0;
  				while (fgets(line, MAX_COLS, capFp) != NULL
  				       && line[0] == '\t') {
  					char *l2 = line;
  					while (*l2 != '\n' && *l2 != '#') {
 +						if (++bnum > BUF_SIZE - 2)
 +							fatal("buffer overflow at configuration file\n");
  						*l++ = *l2++;
  					}
  					*l++ = '\n';
 @@ -223,6 +227,7 @@
  		/* Protected capability. */
  		return FAILURE;
  	}
 +	SafeFree(cp->arg);
  	cp->arg = strdup(value);
  #ifdef	DEBUG
  	fprintf(stderr, "Setting arg for %s to %s\r\n", capName, value);
 @@ -234,8 +239,12 @@
  
  bool BoolConf(const char *confstr)
  {
 -	char name[MAX_COLS];
 -	sscanf(confstr, "%s", name);
 +	char *name, *last, *sep = " \t\r\n";
 +
 +	name = strtok_r((char *)confstr, sep, &last);
 +	if (name == NULL)
 +	    return FALSE;
 +
  	if (strcasecmp(name, "On") == 0 ||
  	    strcasecmp(name, "True") == 0) {
  		return TRUE;
