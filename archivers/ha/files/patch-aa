*** nix/machine.c.bak	Thu Jan 12 09:53:00 1995
--- nix/machine.c	Tue Jan 24 19:38:07 1995
***************
*** 417,423 ****
      if (plainname!=NULL) free(plainname),plainname=NULL;
      if ((plainname=malloc(strlen(mdfullpath)+1))==NULL) 
        error(1,ERR_MEM,"md_stripname()");
!     for (i=strlen(mdfullpath)-1;i>0;i--) {
  	if (mdfullpath[i]=='/') {
  	    i++;
  	    break;
--- 417,423 ----
      if (plainname!=NULL) free(plainname),plainname=NULL;
      if ((plainname=malloc(strlen(mdfullpath)+1))==NULL) 
        error(1,ERR_MEM,"md_stripname()");
!     for (i=strlen(mdfullpath)-1;i>=0;i--) {
  	if (mdfullpath[i]=='/') {
  	    i++;
  	    break;
