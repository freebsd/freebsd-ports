--- scripts/fetchPufferfish.sh.orig	2025-07-26 17:38:39 UTC
+++ scripts/fetchPufferfish.sh
@@ -11,53 +11,6 @@ INSTALL_DIR=${CURR_DIR}/../external/install
 EXTERNAL_DIR=${CURR_DIR}/../external
 INSTALL_DIR=${CURR_DIR}/../external/install
 
-if [ -d ${EXTERNAL_DIR}/pufferfish ] ; then
-    rm -fr ${EXTERNAL_DIR}/pufferfish
-fi
-
-if [ -d ${INSTALL_DIR}/include/pufferfish ] ; then
-    rm -fr ${INSTALL_DIR}/include/pufferfish
-fi
-
-if [ -d ${INSTALL_DIR}/src/pufferfish ] ; then
-    rm -fr ${INSTALL_DIR}/src/pufferfish
-fi
-
-SVER=salmon-v1.10.3
-#SVER=develop
-#SVER=sketch-mode
-
-EXPECTED_SHA256=52b6699de0d33814b73edb3455175568c2330d8014be017dce7b564e54134860 
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
-
 mkdir -p ${INSTALL_DIR}/include/pufferfish
 
 cp ${EXTERNAL_DIR}/pufferfish/include/ProgOpts.hpp ${INSTALL_DIR}/include/pufferfish
@@ -90,7 +43,6 @@ cp ${EXTERNAL_DIR}/pufferfish/include/BinWriter.hpp ${
 cp ${EXTERNAL_DIR}/pufferfish/include/BulkChunk.hpp ${INSTALL_DIR}/include/pufferfish
 cp ${EXTERNAL_DIR}/pufferfish/include/BinWriter.hpp ${INSTALL_DIR}/include/pufferfish
 
-cp -r ${EXTERNAL_DIR}/pufferfish/include/libdivide ${INSTALL_DIR}/include/pufferfish
 cp -r ${EXTERNAL_DIR}/pufferfish/include/ksw2pp ${INSTALL_DIR}/include/pufferfish
 # this is now automatically tracked and inherited via twopaco (on which libpuffer depends)
 # cp -r ${EXTERNAL_DIR}/pufferfish/include/compact_vector ${INSTALL_DIR}/include/pufferfish
