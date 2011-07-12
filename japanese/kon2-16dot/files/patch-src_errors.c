 --- src/errors.c	30 Sep 2008 08:02:59 -0000	1.1.1.1
 +++ src/errors.c	23 Oct 2008 09:24:33 -0000
 @@ -48,7 +48,7 @@
  		vfprintf(stderr, format, args);
  	} else {
  		VtEmu(head, strlen(head));
 -		vsprintf(buf, format, args);
 +		vsnprintf(buf, sizeof(buf), format, args);
  		VtEmu(buf, strlen(buf));
  	}
  }
