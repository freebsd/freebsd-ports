--- lib/neuralnet.c.orig	2007-11-25 22:55:20.000000000 +0100
+++ lib/neuralnet.c	2007-11-25 23:00:22.000000000 +0100
@@ -384,15 +384,17 @@
 
     return 0;
 }
-extern void *NeuralNetCreateDirect( neuralnet *pnn, void *p ) {
+extern void *NeuralNetCreateDirect( neuralnet *pnn, void *v_p ) {
+   int *p = v_p;
+   float *fp = v_p;
  
    pnn->cInput = *( ( (int *) p )++ );
    pnn->cHidden = *( ( (int *) p )++ );
    pnn->cOutput = *( ( (int *) p )++ );
    pnn->nTrained = *( ( (int *) p )++ );
    pnn->fDirect = TRUE;
-   pnn->rBetaHidden = *( ( (float *) p )++ );
-   pnn->rBetaOutput = *( ( (float *) p )++ );
+   pnn->rBetaHidden = *( ( fp )++ );
+   pnn->rBetaOutput = *( ( fp )++ );
  
    if( pnn->cInput < 1 || pnn->cHidden < 1 || pnn->cOutput < 1 ||
      pnn->nTrained < 0 || pnn->rBetaHidden <= 0.0 ||
@@ -402,14 +404,14 @@
      return NULL;
    }
  
-   pnn->arHiddenWeight = p;
-   ( (float *) p ) += pnn->cInput * pnn->cHidden;
-   pnn->arOutputWeight = p;
-   ( (float *) p ) += pnn->cHidden * pnn->cOutput;
-   pnn->arHiddenThreshold = p;
-   ( (float *) p ) += pnn->cHidden;
-   pnn->arOutputThreshold = p;
-   ( (float *) p ) += pnn->cOutput;
+   pnn->arHiddenWeight = fp;
+   fp += pnn->cInput * pnn->cHidden;
+   pnn->arOutputWeight = fp;
+   fp += pnn->cHidden * pnn->cOutput;
+   pnn->arHiddenThreshold = fp;
+   fp += pnn->cHidden;
+   pnn->arOutputThreshold = fp;
+   fp += pnn->cOutput;
 
    pnn->savedBase = malloc( pnn->cHidden * sizeof( float ) ); 
    pnn->savedIBase = malloc( pnn->cInput * sizeof( float ) ); 
