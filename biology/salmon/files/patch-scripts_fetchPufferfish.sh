--- scripts/fetchPufferfish.sh.orig	2023-07-21 13:59:29 UTC
+++ scripts/fetchPufferfish.sh
@@ -11,52 +11,12 @@ CURR_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && p
 EXTERNAL_DIR=${CURR_DIR}/../external
 INSTALL_DIR=${CURR_DIR}/../external/install
 
-if [ -d ${EXTERNAL_DIR}/pufferfish ] ; then
-    rm -fr ${EXTERNAL_DIR}/pufferfish
-fi
+# Pufferfish is downloaded using GH_TUPLE in the FreeBSD port, so remove
+# code here that downloads and unpacks
 
-if [ -d ${INSTALL_DIR}/include/pufferfish ] ; then
-    rm -fr ${INSTALL_DIR}/include/pufferfish
-fi
-
-if [ -d ${INSTALL_DIR}/src/pufferfish ] ; then
-    rm -fr ${INSTALL_DIR}/src/pufferfish
-fi
-
 SVER=salmon-v1.10.2
 #SVER=develop
 #SVER=sketch-mode
-
-EXPECTED_SHA256=f225b74833f71dcf767a565345224357fb091f90ce79717abc836814d9ccd101
-
-mkdir -p ${EXTERNAL_DIR}
-curl -k -L https://github.com/COMBINE-lab/pufferfish/archive/${SVER}.zip -o ${EXTERNAL_DIR}/pufferfish.zip
-
-hashcheck=""
-if exists sha256sum; then
-	hashcheck="sha256sum"
-elif exists shasum; then
-	hashcheck="shasum -a256"
-else
-	unset hashcheck
-fi
-
-
-if [ -z "${hashcheck-}" ]; then
-    echo "Couldn't find shasum command; can't verify contents of downloaded pufferfish";
-else
-
-    if [[ $SVER != develop && $SVER != onetbb ]]; then
-        echo "${EXPECTED_SHA256}  ${EXTERNAL_DIR}/pufferfish.zip" | ${hashcheck} -c - || { echo "pufferfish.zip did not match expected SHA1! Exiting."; exit 1; }
-    else
-        echo "not testing sha since pulling from develop"
-    fi
-fi
-
-
-rm -fr ${EXTERNAL_DIR}/pufferfish
-unzip ${EXTERNAL_DIR}/pufferfish.zip -d ${EXTERNAL_DIR}
-mv ${EXTERNAL_DIR}/pufferfish-${SVER} ${EXTERNAL_DIR}/pufferfish
 
 mkdir -p ${INSTALL_DIR}/include/pufferfish
 
