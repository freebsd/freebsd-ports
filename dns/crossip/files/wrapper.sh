#!/bin/sh

JAVAVM="%%JAVAVM%%"
JAR_DIR="%%JAR_DIR%%"

${JAVAVM} -jar ${JAR_DIR}/CrossIP.jar "${@}"
