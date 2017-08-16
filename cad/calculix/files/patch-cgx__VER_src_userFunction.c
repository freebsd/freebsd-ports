--- cgx_2.12/src/userFunction.c.orig	2017-04-30 15:13:54 UTC
+++ cgx_2.12/src/userFunction.c
@@ -57,7 +57,12 @@ void sendFacesNodes( char *setname );
 /*                                                                       */
 /*                                                                       */
 /* --------------------------------------------------------------------  */
-                                                                
+
+  int assembleFEM(char *parameters, Summen   *sum, SumGeo   *sumGeo ) { return(0); }
+  int assembleFEMVane(char *parameters, Summen   *sum, SumGeo   *sumGeo ) { return(0); }
+  int createAF(char *sections, char *parameters, Summen   *sum, SumGeo   *sumGeo ){ return(0); }
+  int createAF_nlb(char *sections, char *parameters, Summen   *sum, SumGeo   *sumGeo ){ return(0); }
+  int sendFlutter(Summen *sum, char string[2][MAX_LINE_LENGTH] ) { return(0); }                                                                  
 void userFunction(char *string, Summen   *sum, SumGeo   *sumGeo )
 {                                                               
   int i,j,k,l,n;
@@ -89,11 +94,6 @@ void userFunction(char *string, Summen  
   // aflib addons
   char buf[12][MAX_LINE_LENGTH];                                            
 
-  int assembleFEM(char *parameters, Summen   *sum, SumGeo   *sumGeo ) { return(0); }
-  int assembleFEMVane(char *parameters, Summen   *sum, SumGeo   *sumGeo ){ return(0); }
-  int createAF(char *sections, char *parameters, Summen   *sum, SumGeo   *sumGeo ){ return(0); }
-  int createAF_nlb(char *sections, char *parameters, Summen   *sum, SumGeo   *sumGeo ){ return(0); }
-  int sendFlutter(Summen *sum, char string[2][MAX_LINE_LENGTH] ) { return(0); }                  
   // end
 
   /* list the implemented user-functions if no parameter was provided for the "call" command */
