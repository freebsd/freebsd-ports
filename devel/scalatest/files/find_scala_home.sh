#!/bin/sh

PREFIX=$1
SOURCE=$PREFIX"/bin/scala";
SCRIPT=`basename "$SOURCE"`;
while [ -h "$SOURCE" ]; do
    SCRIPT=`basename "$SOURCE"`;
    LOOKUP=`ls -ld "$SOURCE"`;
    TARGET=`expr "$LOOKUP" : '.*-> \(.*\)$'`;
    if expr "${TARGET:-.}/" : '/.*/$' > /dev/null; then
        SOURCE=${TARGET:-.};
    else
        SOURCE=`dirname "$SOURCE"`/${TARGET:-.};
    fi;
done;

SCALA_HOME=`dirname "$SOURCE"`
SCALA_HOME=`cd "$SCALA_HOME"; pwd -P`
SCALA_HOME=`cd "$SCALA_HOME"/..; pwd`
SCALA_HOME=`expr $SCALA_HOME : "$PREFIX/\(.*\)"`

echo $SCALA_HOME

exit 0
