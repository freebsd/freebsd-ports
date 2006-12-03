#! /bin/sh
[ ${JAVA_HOME} ] && JAVA=${JAVA_HOME}/bin/java || JAVA=java

# Are we running within Cygwin on some version of Windows?
cygwin=false;
case "`uname -s`" in
	CYGWIN*) cygwin=true ;;
esac

# Squirrel home.
SQUIRREL_SQL_HOME=`dirname "$0"`

# SQuirreL home in Unix format.
if $cygwin ; then
	UNIX_STYLE_HOME=`cygpath "$SQUIRREL_SQL_HOME"`
else
	UNIX_STYLE_HOME=$SQUIRREL_SQL_HOME
fi

# First entry in classpath is the Squirrel application.
TMP_CP=$UNIX_STYLE_HOME/squirrel-sql.jar

# Then add all library jars to the classpath.
IFS=""
for a in $UNIX_STYLE_HOME/lib/*; do
	TMP_CP="$TMP_CP":"$a";
done

# Now add the system classpath to the classpath. If running
# Cygwin we also need to change the classpath to Windows format.
if $cygwin ; then
	TMP_CP=`cygpath -w -p $TMP_CP`
	TMP_CP=$TMP_CP';'$CLASSPATH
else
	TMP_CP=$TMP_CP:$CLASSPATH
fi

#To add translation working directories to your classpath edit and uncomment this line:
#$JAVA -Xmx256m -cp $TMP_CP:<your working dir here> net.sourceforge.squirrel_sql.client.Main --log-config-file $SQUIRREL_SQL_HOME/log4j.properties --squirrel-home $SQUIRREL_SQL_HOME $1 $2 $3 $4 $5 $6 $7 $8 $9

#To change the language edit and uncomment this line:
#$JAVA -Xmx256m -cp $TMP_CP:<your working dir here> -Duser.language=<your language here> net.sourceforge.squirrel_sql.client.Main --log-config-file $SQUIRREL_SQL_HOME/log4j.properties --squirrel-home $SQUIRREL_SQL_HOME $1 $2 $3 $4 $5 $6 $7 $8 $9


$JAVA -Xmx256m -cp $TMP_CP net.sourceforge.squirrel_sql.client.Main --log-config-file $SQUIRREL_SQL_HOME/log4j.properties --squirrel-home $SQUIRREL_SQL_HOME $1 $2 $3 $4 $5 $6 $7 $8 $9

