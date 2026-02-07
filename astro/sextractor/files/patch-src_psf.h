--- src/psf.h.orig	2006-01-12 18:30:35 UTC
+++ src/psf.h
@@ -89,9 +89,9 @@ typedef struct
   }	psfitstruct;
 
 /*----------------------------- Global variables ----------------------------*/
-psfstruct	*psf,*ppsf,*thepsf;
-psfitstruct	*thepsfit,*ppsfit,*psfit;
-PIXTYPE		*checkmask;
+EXTERN psfstruct	*psf,*ppsf,*thepsf;
+EXTERN psfitstruct	*thepsfit,*ppsfit,*psfit;
+EXTERN PIXTYPE		*checkmask;
 
 /*-------------------------------- functions --------------------------------*/
 extern void	compute_pos(int *pnpsf,int *pconvflag,int *pnpsfflag,
