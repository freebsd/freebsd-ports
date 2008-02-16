#!/bin/sh
# Invoke Jython.
# jython.sh,v 1.5 2007/09/28 09:13:55 martin Exp
#
# The path names below are for Jython 2.2 on FreeBSD.
#

CP="/usr/local/lib/jython22/jython.jar"
defs=
wrapper=

case "${JYTHON_CONSOLE:-Editline}" in
    *[Ee]dit[Ll]ine)
	CP="$CP:/usr/local/share/java/classes/libreadline-java.jar"
	defs="-Dpython.console=org.python.util.ReadlineConsole"
	defs="$defs -Dpython.console.readlinelib=Editline"
	;;
    *[Gg]et[Ll]ine)
	CP="$CP:/usr/local/share/java/classes/libreadline-java.jar"
	defs="-Dpython.console=org.python.util.ReadlineConsole"
	defs="$defs -Dpython.console.readlinelib=Getline"
	;;
    *[Jj][Ll]ine)
	CP="$CP:/usr/local/share/java/classes/jline.jar"
	defs="-Dpython.console="
	wrapper=jline.ConsoleRunner
	;;
    *[Rr]ead[Ll]ine)
	CP="$CP:/usr/local/share/java/classes/libreadline-java.jar"
	defs="-Dpython.console=org.python.util.ReadlineConsole"
	defs="$defs -Dpython.console.readlinelib=GnuReadline"
	;;
    *)
	echo >&2 "$0: illegal value of JYTHON_CONSOLE: $JYTHON_CONSOLE"
	exit 64
	;;
esac


if [ -n "$CLASSPATH" ]; then
  CP="$CP:$CLASSPATH"
fi

exec java -Dpython.home="/usr/local/lib/jython22"	\
    -Dpython.cachedir="${HOME}/.jython-cachedir"	\
    -classpath "$CP" $wrapper org.python.util.jython $defs "$@"

#EOF#
