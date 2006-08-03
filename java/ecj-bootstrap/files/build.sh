#!/bin/sh
# taken from eclipse.spec of
# <fedora mirror>/fedora/core/5/source/SRPMS/eclipse-3.1.2-1jpp_13fc.src.rpm
# for fedora mirror, please consult following site.
# http://fedora.redhat.com/download/mirrors.html

  # Bootstrapping is 3 parts:
  # 1. Build ecj with gcj -C 
  # 2. Build ecj with gcj-built ecj ("javac")
  # 3. Re-build ecj with output of 2.
  
  # Unzip the "stable compiler" source into a temp dir and build it.
  # Note:  we don't want to build the CompilerAdapter.

  mkdir ecj-bootstrap-tmp
  unzip -qq -d ecj-bootstrap-tmp jdtcoresrc/src/ecj.zip
  rm -f ecj-bootstrap-tmp/org/eclipse/jdt/core/JDTCompilerAdapter.java

  # 1a. Build ecj with gcj -C
  cd ecj-bootstrap-tmp
  for f in `find . -name '*.java' | cut -c 3-`; do
    ${GCJ} -Wno-deprecated -C $f
  done
  find . -name '*.class' -or -name '*.properties' -or -name '*.rsc' |\
      xargs ${JAR} cf ../ecj-bootstrap.jar
  cd ..

  # Delete our modified ecj and restore the backup
  rm -rf ecj-bootstrap-tmp

  # 1b. Natively-compile it

  ${GCJ} -fPIC -fjni -findirect-dispatch -shared -Wl,-Bsymbolic -o ecj-bootstrap.jar.so ecj-bootstrap.jar
 
  ${GCJDBTOOL} -n ecj-bootstrap.db 30000
  ${GCJDBTOOL} -a ecj-bootstrap.db ecj-bootstrap.jar ecj-bootstrap.jar.so

  # 2a. Build ecj
  export CLASSPATH=ecj-bootstrap.jar:$ORIGCLASSPATH
  export ANT_OPTS="-Dgnu.gcj.precompiled.db.path=`pwd`/ecj-bootstrap.db"
  ${ANT} -Dbuild.compiler=gcj -buildfile jdtcoresrc/compilejdtcorewithjavac.xml

  ${GCJ} -fPIC -fjni -findirect-dispatch -shared -Wl,-Bsymbolic \
    -o jdtcoresrc/ecj.jar.so jdtcoresrc/ecj.jar
   
  ${GCJDBTOOL} -n jdtcoresrc/ecj.db 30000
  ${GCJDBTOOL} -a jdtcoresrc/ecj.db jdtcoresrc/ecj.jar jdtcoresrc/ecj.jar.so

  # Remove our gcj-built ecj
  rm ecj-bootstrap.db ecj-bootstrap.jar ecj-bootstrap.jar.so

  # To enSURE we're not using any pre-compiled ecj on the build system, set this
  export ANT_OPTS="-Dgnu.gcj.precompiled.db.path=`pwd`/jdtcoresrc/ecj.db"

  # 3. Use this ecj to rebuild itself
  export CLASSPATH=`pwd`/jdtcoresrc/ecj.jar:$ORIGCLASSPATH
  ${ANT} -Dbuild.compiler=gcj -buildfile jdtcoresrc/compilejdtcore.xml

  # Natively-compile it
  ${GCJ} -fPIC -fjni -findirect-dispatch -shared -Wl,-Bsymbolic \
      -o ecj.jar.so ecj.jar
  ${GCJDBTOOL} -n ecj.db 30000
  ${GCJDBTOOL} -a ecj.db ecj.jar ecj.jar.so
  export ANT_OPTS="-Dgnu.gcj.precompiled.db.path=`pwd`/ecj.db"
  rm jdtcoresrc/ecj.db jdtcoresrc/ecj.jar.so

  # Creating native executable
  ${GCJ} -O2 -g -Wl,-Bsymbolic -fPIC -fjni -findirect-dispatch  --main=org.eclipse.jdt.internal.compiler.batch.Main -o ecj-bootstrap-gcj ecj.jar
