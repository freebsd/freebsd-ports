
$FreeBSD$

--- setup.sh.orig
+++ setup.sh
@@ -87,19 +87,12 @@
        echo "Compilation of $file failed"
        exit 1
     fi
-    printf "  Checking consistency of ebin/*.beam files... "
-    $DIALYZER_OTP_OTP -pa utils/ -noshell -s dialyzer_chk test `pwd` -s init stop
-    rm -f utils/dialyzer_chk.beam
 
     ## create the dialyzer script
     sed -e "s;%OTP_DIR%;$DIALYZER_OTP_DIR;" \
 	-e "s;%VSN%;$VSN;" -e "s;%DATE%;`date`;" \
-	-e "s;%DIALYZER_DIR%;`pwd`;" src/dialyzer.src > dialyzer
+	-e "s;%DIALYZER_DIR%;%%DIALYZER_DIR%%;" src/dialyzer.src > dialyzer
     chmod +x dialyzer
-    echo "Dialyzer is analyzing itself..."
-    ./dialyzer --src --command-line "`pwd`/src"
-    echo "Dialyzer setup done!"
-    echo "  For the full set of Dialyzer options type: ./dialyzer --help"
 else
     echo "Could not find ${DIALYZER_OTP_ERLC}"
 fi
