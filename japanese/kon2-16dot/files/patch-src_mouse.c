 --- src/mouse.c	30 Sep 2008 08:09:56 -0000	1.1.1.2
 +++ src/mouse.c	23 Oct 2008 09:24:33 -0000
 @@ -122,11 +122,11 @@
  		}
  };
  
 -static int mouseBaud;
 +static int mouseBaud = B1200;
  
  static int	ConfigMouseBaud(const char *config)
  {
 -	int baud;
 +	int baud = 0;
  
  	sscanf(config, "%d", &baud);
  
 @@ -149,19 +149,23 @@
  	return SUCCESS;
  }
  
 -static char *mouseDev;
 +static char *mouseDev = NULL;
  
  static int	ConfigMouseDev(const char *config)
  {
 -	char name[MAX_COLS];
 -	sscanf(config, "%s", name);
 +	char *name, *last, *sep = " \t\r\n";
  
 -	if (mouseDev) free(mouseDev);
 +	name = strtok_r((char *)config, sep, &last);
 +	if (name == NULL) {
 +		warn("unknown mouse type ignored; assuming no mouse\r\n");
 +		return SUCCESS;
 +	}
 +	SafeFree(mouseDev);
  	mouseDev = strdup(name);
  	return SUCCESS;
  }
  
 -static int	pasteButton;
 +static int	pasteButton = MOUSE_RGT;
  
  static int      Config3Buttons(const char *config)
  { 
 @@ -172,12 +176,15 @@
  static int	ConfigMouse(const char *config)
  {
  	struct mouseconf *p;
 -	char name[MAX_COLS];
 +	char *name, *last, *sep = " \t\r\n";
  
  	mouseType = MOUSE_NONE;
  	mInfo.has_mouse = FALSE;
 -	strncpy(name, config, MAX_COLS - 1);
 -	name[MAX_COLS - 1] = '\0';
 +	name = strtok_r((char *)config, sep, &last);
 +	if (name == NULL) {
 +		warn("unknown mouse type ignored; assuming no mouse\r\n");
 +		return SUCCESS;
 +	}
  	for (p = mice; p->name != NULL; p++) {
  		if (strcasecmp(name, p->name) == 0) {
  			mouseType = p->type;
 @@ -254,7 +261,7 @@
      if ((mfd = open(mouseDev, O_RDWR|O_NONBLOCK)) < 0) {
  	warn("couldn't open mouse device; mouse disabled\n");
  	Perror(mouseDev);
 -	free(mouseDev);
 +	SafeFree(mouseDev);
  	mouseDev = NULL;
  	mInfo.has_mouse = FALSE;
  	return -1;
