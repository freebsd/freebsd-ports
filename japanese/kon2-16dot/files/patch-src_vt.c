 --- src/vt.c	30 Sep 2008 08:09:56 -0000	1.1.1.2
 +++ src/vt.c	23 Oct 2008 09:24:33 -0000
 @@ -107,7 +107,7 @@
  	con.bcol = saveAttr->bcol;
  	tmp = saveAttr;
  	saveAttr = tmp->prev;
 -	free(tmp);
 +	SafeFree(tmp);
      }
  }
  
 @@ -606,20 +606,23 @@
  
  static int	ConfigCoding(const char *confstr)
  {
 -    char reg[3][MAX_COLS];
 +    char *name, *last, *sep = " \t\r\n";
      int n, i;
  
 -    *reg[0] = *reg[1] = *reg[2] = '\0';
 -    sscanf(confstr, "%s %s %s", reg[0], reg[1], reg[2]);
 -    for (i = 0; i < 3 && *reg[i]; i ++) {
 -	n = (int)CodingByRegistry(reg[i]);
 +    name = strtok_r((char *)confstr, sep, &last);
 +    for (i = 0; i < 3; i++) {
 +	if (name == NULL) {
 +	    error("invalid coding system\n");
 +	    return FAILURE;
 +	}
 +	n = (int)CodingByRegistry(name);
  	if (n < 0) {
 -	    if (!strcasecmp(reg[i], "EUC"))
 +	    if (!strcasecmp(name, "EUC"))
  		lInfo.sc = CODE_EUC;
 -	    else if (!strcasecmp(reg[i], "SJIS"))
 +	    else if (!strcasecmp(name, "SJIS"))
  		lInfo.sc = CODE_SJIS;
  /*
 -	    else if (!strcasecmp(reg[i], "BIG5"))
 +	    else if (!strcasecmp(name, "BIG5"))
  		lInfo.sc = CODE_BIG5;
  */
  	    else
 @@ -633,6 +636,7 @@
  fprintf(fp,"[<%s> %d %d %d %d]\n", reg[i], n, lInfo.sb, lInfo.db, lInfo.sc);
  fclose(fp);}
  #endif
 +    	name = strtok_r(NULL, sep, &last);
      }
      return SUCCESS;
  }
