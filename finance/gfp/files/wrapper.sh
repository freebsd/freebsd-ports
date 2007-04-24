#!/bin/sh

export JAVA_OS
export JAVA_VERSION

JAVA_OS="%%JAVA_OS%%"
JAVA_VERSION="%%JAVA_VERSION%%"

APP_DIR=${HOME}/.gfp
DATA_DIR="%%DATADIR%%"
#
APP_FILES_LINK="
  db/ddl.sql
  db/hsqldb.jar
  gfd.jar
  setup.dat
  temp/license.txt
"
APP_DIR_LINK="
  ext
  helpFiles
  lookAndFeel
  plugins
  resources
"
APP_SUBDIR_MKDIR="db temp"
#
JAVA_CMD="%%JAVAVM%%"
LN_CMD="%%LN%%"
MKDIR_CMD="%%MKDIR%%"
RM_CMD="%%RM%%"
#
JAR_FILE="%%JAR_FILE%%"

# create application home dir
${MKDIR_CMD} -p ${APP_DIR}

# create subdirs
for dir in ${APP_SUBDIR_MKDIR}
do
  ${MKDIR_CMD} -p ${APP_DIR}/${dir}
done

# create links
for link in ${APP_FILES_LINK}
do
  ${LN_CMD} -sf "${DATA_DIR}/${link}" "${APP_DIR}/${link}"
done
for link in ${APP_DIR_LINK}
do
  ${RM_CMD} -f "${APP_DIR}/${link}"
  ${LN_CMD} -sf "${DATA_DIR}/${link}" "${APP_DIR}/${link}"
done

( cd ${APP_DIR} && exec ${JAVA_CMD} -jar ${JAR_FILE} )
