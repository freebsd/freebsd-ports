#!/bin/sh
#                 Sun Public License Notice
# 
# The contents of this file are subject to the Sun Public License
# Version 1.0 (the "License"). You may not use this file except in
# compliance with the License. A copy of the License is available at
# http://www.sun.com/
# 
# The Original Code is NetBeans. The Initial Developer of the Original
# Code is Sun Microsystems, Inc. Portions Copyright 1997-2000 Sun
# Microsystems, Inc. All Rights Reserved.

#
# customization
#

# the value set here can be overriden by $JAVA_PATH or the -jdkhome switch
jdkhome="%%JDK13DIR%%"
export jdkhome
jreflags="-Xss1024k -Xms24m -Xverify:none"
# default userdir, can be overriden by -userdir switch.  This value should be
# changed for each new version so that the user can switch between versions of
# the IDE without risking loss of settings, e.g. ~/nbdev for Dev builds,
# ~/nbuser32 for NB 3.2, ~/nbuser33 for NB 3.3, etc.

userdir="${HOME}/ffjuser30"

#
# end of customization 
#

PRG=$0

#
# resolve symlinks
#

while [ -h "$PRG" ]; do
   ls=`ls -ld "$PRG"`
   link=`expr "$ls" : '^.*-> \(.*\)$' 2>/dev/null`
   if expr "$link" : '^/' 2> /dev/null >/dev/null; then
       PRG="$link"
   else
       PRG="`dirname $PRG`/$link"
   fi
done

progdir=`dirname $PRG`
progname=`basename $0`

idehome="$progdir/.."

# absolutize idehome

oldpwd=`pwd` ; cd ${idehome}; idehome=`pwd`; cd $oldpwd; unset oldpwd

thread_flag=""

jargs=${jreflags}
jargs="$jargs -Dnetbeans.home=$idehome"
jargs="$jargs -Djava.security.policy=$idehome/bin/ide.policy"

args=""

prefixcp=""
postfixcp=""

updater_class=org.netbeans.updater.UpdaterFrame
ide_class=org.netbeans.Main

#
# defaults
#

# if JAVA_PATH is set it overrides the default in the script

if [ ! -z "$JAVA_PATH" ] ; then
   jdkhome=$JAVA_PATH
fi

# if JDK_HOME is set it overrides the default in the script and ${JAVA_PATH}

if [ ! -z "$JDK_HOME" ] ; then
   jdkhome=$JDK_HOME
fi

#
# parse arguments
#

while [ $# -gt 0 ] ; do
   case "$1" in
       -h|-help) cat <<EOF
Usage: $0 {options} arguments

Options can be

    -h -help
          shows usage
    -jdkhome <path>
       specifies the JDK directory

    -hotspot
    -client
    -server
    -classic
    -native
    -green
       specifies the type of JVM
        
    -J<jvm_options>
       passes <jvm_option> to JVM
    -userdir <path>
       specifies userdir (\$HOME/nbuser32 by default)
    -single
       runs the IDE in single user mode
    -cp:p <classpath>
       prepends <classpath> to IDE's classpath
    -cp:a <classpath>
       appends <classpath> to IDE's classpath

All other options and arguments are passed to the IDE.
See documentations for details

EOF
exit 1
;;
       -jdkhome) shift; if [ $# -gt 0 ] ; then jdkhome=$1; fi;;
       -userdir) shift; if [ $# -gt 0 ] ; then userdir=$1; fi;;
       -single) userdir="";;
       -mainclass) shift; if [ $# -gt 0 ] ; then ide_class=$1; fi;;
       -cp|-cp:a)
           shift;
           if [ $# -gt 0 ] ; then
               if [ ! -z "$postfixcp" ] ; then postfixcp="$postfixcp:" ; fi
               postfixcp=$postfixcp$1;
           fi
           ;;
        
       -cp:p)
           shift;
           if [ $# -gt 0 ] ; then
               if [ ! -z "$prefixcp" ] ; then prefixcp="$prefixcp:" ; fi
               prefixcp=$prefixcp$1;
           fi
           ;;
        
       -hotspot|-client|-server|-classic|-native|-green) thread_flag=$1;;
       -J-hotspot|-J-client|-J-server|-J-classic|-J-native|-J-green) thread_flag=`expr $1 : '-J\(.*\)'`;;
       -J*) jopt=`expr "$1" : '-J\(.*\)'`; jargs="$jargs \"$jopt\"";;
       *) args="$args \"$1\"" ;;
   esac
   shift
done

#
# check JDK
#

if [ -z "$jdkhome" ] ; then
   echo "Cannot find JDK. Please set the JDK_HOME environment variable to point"
   echo "to your JDK installation directory, or use the -jdkhome switch"
   echo ""
   exit 1
fi

if [ ! -x "${jdkhome}/bin/java" ] ; then
   echo "Cannot find JDK at ${jdkhome}. Please set the JDK_HOME"
   echo "environment variable to point to your JDK installation directory,"
   echo "or use the -jdkhome switch"
   echo ""
   exit 1
fi

#
# check userdir
#

if [ ! -z "$userdir" ] ; then
   echo "Using ${userdir} as user directory...";
   jargs="$jargs -Dnetbeans.user=$userdir"
fi

#
# increase file descriptor's limit, on Solaris it's set to 64, too small for
# fastjavac
#

ulimit -n 1024

append_jars_to_cp() {
   dir="$1"
   for ex in jar zip ; do
       if [ "`echo ${dir}/*.$ex`" != "${dir}/*.$ex" ] ; then
           for x in ${dir}/*.$ex ; do
               if [ "$x" != "$idehome/lib/updater.jar" -a "$x" != "$userdir/lib/updater.jar" ] ; then
                   if [ ! -z "$cp" ] ; then cp="$cp:" ; fi
                   cp="$cp$x"
               fi
           done
       fi
   done
}

build_cp() {
   base="$1"

   append_jars_to_cp "${base}/lib/patches/locale"
   append_jars_to_cp "${base}/lib/patches"
   append_jars_to_cp "${base}/lib/ext/locale"
   append_jars_to_cp "${base}/lib/ext"

   append_jars_to_cp "${base}/lib/locale"
   append_jars_to_cp "${base}/lib"
}

#
# dump the OS env variables into a temp file
#

nbenvfile=/tmp/nbenv.$$
if [ -x /usr/bin/env ] ; then
   /usr/bin/env > $nbenvfile
else
   echo "" >  $nbenvfile
fi

#
# main loop
#

while true; do

   #
   # build CLASSPATH
   #
    
   cp=""
   updatercp=""
    
   # userdir comes first
    
   if [ ! -z "${userdir}" ] ; then
       build_cp ${userdir}

       if [ -f "${userdir}/lib/updater.jar" ] ; then
           updatercp="${userdir}/lib/updater.jar"
       fi
   fi

   # idehome comes second
    
   build_cp ${idehome}
    
   if [ -f "${idehome}/lib/updater.jar" ] ; then
       if [ ! -z "$updatercp" ] ; then updatercp="${updatercp}:" ; fi
       updatercp="${updatercp}${idehome}/lib/updater.jar"
   fi

   # JDK tools
    
   for ex in jar zip ; do
       if [ "`echo ${jdkhome}/lib/*.$ex`" != "${jdkhome}/lib/*.$ex" ] ;then
           for x in ${jdkhome}/lib/*.$ex ; do
               if [ ! -z "$cp" ] ; then cp="$cp:" ; fi
               cp="${cp}$x"
           done
       fi
   done

   # user-specified prefix and postfix CLASSPATH
    
   if [ ! -z "${prefixcp}" ] ; then
       cp="${prefixcp}:$cp"
   fi
    
   if [ ! -z "${postfixcp}" ] ; then
       cp="$cp:${postfixcp}"
   fi


   # prepend IDE's classpath to updater's classpath
    
   if [ ! -z "$updatercp" ] ; then
       updatercp=${cp}:${updatercp}
   else
       updatercp=${cp}
   fi
    
   #
   # let's go
   #
    
   eval $jdkhome/bin/java $thread_flag $jargs -classpath "\"$cp\"" \
       -Dnetbeans.osenv=${nbenvfile} \
$ide_class $args

    # AutoUpdate exit?
    
    rc=$?
    if [ $rc -ne 66 ] ; then
        rm $nbenvfile
        exit $rc
    fi

    # runs updater
    
    eval $jdkhome/bin/java $thread_flag $jargs -classpath "\"${updatercp}\"" $updater_class
    done   


