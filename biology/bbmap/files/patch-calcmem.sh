--- calcmem.sh.orig	2024-12-10 19:13:48 UTC
+++ calcmem.sh
@@ -78,26 +78,6 @@ function setEnvironment(){
 	if [[ "$SHIFTER_RUNTIME" = "1" ]]; then
 		#Ignore NERSC_HOST
 		shifter=1
-	elif [ -z "$EC2_HOME" ]; then
-		#Let's assume this is the AWS taxonomy server...
-		PATH=/test1/binaries/bgzip:$PATH
-		PATH=/test1/binaries/lbzip2/bin:$PATH
-		PATH=/test1/binaries/sambamba:$PATH
-		#PATH=/test1/binaries/java/jdk-11.0.2/bin:$PATH
-		PATH=/test1/binaries/pigz2/pigz-2.4:$PATH
-	elif [ -z "$NERSC_HOST" ]; then
-		#Not NERSC; do nothing
-		:
-	elif [ -z "$NERSC_HOST" ]; then
-		#Not NERSC; do nothing
-		:
-	else
-		PATH=/global/cfs/cdirs/bbtools/bgzip:$PATH
-		PATH=/global/cfs/cdirs/bbtools/lbzip2/bin:$PATH
-                PATH=/global/cfs/cdirs/bbtools/samtools116/samtools-1.16.1:$PATH
-		#PATH=/global/projectb/sandbox/gaag/bbtools/sambamba:$PATH
-		PATH=/global/cfs/cdirs/bbtools/java/jdk-17/bin:$PATH
-		PATH=/global/cfs/cdirs/bbtools/pigz2/pigz-2.4:$PATH
 	fi
 }
 
