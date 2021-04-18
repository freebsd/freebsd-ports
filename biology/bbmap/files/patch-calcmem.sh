--- calcmem.sh.orig	2021-04-13 14:05:28 UTC
+++ calcmem.sh
@@ -72,30 +72,6 @@ function setEnvironment(){
 	if [[ $SHIFTER_RUNTIME == 1 ]]; then
 		#Ignore NERSC_HOST
 		shifter=1
-	elif [ -v "$EC2_HOME" ]; then
-		#Let's assume this is the AWS taxonomy server...
-		PATH=/test1/binaries/bgzip:$PATH
-		PATH=/test1/binaries/lbzip2/bin:$PATH
-		PATH=/test1/binaries/sambamba:$PATH
-		#PATH=/test1/binaries/java/jdk-11.0.2/bin:$PATH
-		PATH=/test1/binaries/pigz2/pigz-2.4:$PATH
-	elif [ -z "$NERSC_HOST" ]; then
-		#Not NERSC; do nothing
-		:
-	else
-		PATH=/global/projectb/sandbox/gaag/bbtools/bgzip:$PATH
-		PATH=/global/projectb/sandbox/gaag/bbtools/lbzip2/bin:$PATH
-		PATH=/global/projectb/sandbox/gaag/bbtools/sambamba:$PATH
-		PATH=/global/projectb/sandbox/gaag/bbtools/java/jdk-11.0.2/bin:$PATH
-		PATH=/global/projectb/sandbox/gaag/bbtools/pigz2/pigz-2.4:$PATH
-		
-		if [[ $NERSC_HOST == cori ]]; then
-
-			#module unload PrgEnv-intel
-			#module load PrgEnv-gnu/7.1
-			PATH=/global/projectb/sandbox/gaag/bbtools/samtools_cori/bin:$PATH
-			:
-		fi
 	fi
 }
 
