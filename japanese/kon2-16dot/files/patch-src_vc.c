 --- src/vc.c	30 Sep 2008 08:09:56 -0000	1.1.1.2
 +++ src/vc.c	23 Oct 2008 09:24:33 -0000
 @@ -792,22 +792,21 @@
      return SUCCESS;
  }
  
 -static	char	*videoName;
 +static	char	*videoName = NULL;
  
  static int	ConfigDisplay(const char *config)
  {
      struct videoconf *v;
 -    char name[MAX_COLS];
 -    
 -    sscanf(config, "%s", name);
 +    char *name, *last, *sep = " \t\r\n";
 +
 +    name = strtok_r((char *)config, sep, &last);
 +    if (name == NULL) {
 +	error("invalid entry for %s\r\n", videoName);
 +	return FAILURE;
 +    } 
      for (v = videos; v->name != NULL; v++) {
  	if (strcasecmp(name, v->name) == 0) {
 -	    config = strchr(config, '\n');
 -	    if (config == NULL) {
 -		error("invalid entry for %s\r\n", videoName);
 -		return FAILURE;
 -	    }
 -	    if (v->set(&vInfo, config) == FAILURE)
 +	    if (v->set(&vInfo, last) == FAILURE)
  		return FAILURE;
  	    message("video type `%s' selected\r\n", name);
  	    if (vInfo.has_hard_scroll) {
 @@ -873,6 +872,7 @@
  
  void	ConsoleInit(const char *video)
  {
 +    SafeFree(videoName);
      videoName = strdup(video);
      DefineCap(videoName, ConfigDisplay, NULL);
      DefineCap("BeepCounter", ConfigBeep, "5");
 @@ -900,12 +900,12 @@
  {
      scrollLine = textHead = 0;
      vInfo.detatch();
 -    SafeFree((void **)&textBuff);
 -    SafeFree((void **)&attrBuff);
 -    SafeFree((void **)&flagBuff);
 +    SafeFree(textBuff);
 +    SafeFree(attrBuff);
 +    SafeFree(flagBuff);
  #ifdef linux
      ioperm(COUNTER_ADDR, 1, FALSE);
  #endif
      
 -    SafeFree((void **)&videoName);
 +    SafeFree(videoName);
  }
