#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# bsd.java.mk - Support for Java-based ports.
#
# Created by: Ernst de Haan <znerd@FreeBSD.org>
#
# For FreeBSD committers:
# Please send all suggested changes to the maintainer instead of committing
# them to CVS yourself.
#
# $FreeBSD$
#

.if !defined(Java_Include)

Java_Include=				bsd.java.mk
Java_Include_MAINTAINER=	znerd@FreeBSD.org

#
# There are the following stages:
#
# Stage 1: Define constants
# Stage 2: Deal with JAVA_HOME if it is already set
# Stage 3: Determine which JDK ports are installed
# Stage 4: Decide the exact JDK version if only a minimum version is specified
# Stage 5: Decide the exact JDK to use
# Stage 6: Define all settings for the port to use
# Stage 7: Add any dependencies if necessary
#

.	if defined(USE_JAVA)


#-----------------------------------------------------------------------------
# Stage 1: Define constants
#

# System-global directories
JAVASHAREDIR?=	${PREFIX}/share/java
JAVAJARDIR?=	${JAVASHAREDIR}/classes

# The complete list of Java versions supported.
_JAVA_VERSIONS=		1.1 1.2 1.3 1.4

# Set the JAVA_HOME directories for all recognized JDK's
_JAVA_HOME_FREEBSD_1_1=			${LOCALBASE}/jdk1.1.8
_JAVA_HOME_FREEBSD_1_2=			${LOCALBASE}/jdk1.2.2
_JAVA_HOME_FREEBSD_1_3=			${LOCALBASE}/jdk1.3.1
_JAVA_HOME_FREEBSD_1_4=			${LOCALBASE}/jdk1.4.2
_JAVA_HOME_DIABLO_FREEBSD_1_3=		${LOCALBASE}/diablo-jdk1.3.1
_JAVA_HOME_BLACKDOWN_LINUX_1_2=	${LOCALBASE}/linux-blackdown-jdk1.2.2
_JAVA_HOME_BLACKDOWN_LINUX_1_3=	${LOCALBASE}/linux-blackdown-jdk1.3.1
_JAVA_HOME_BLACKDOWN_LINUX_1_4=	${LOCALBASE}/linux-blackdown-jdk1.4.1
_JAVA_HOME_IBM_LINUX_1_3=		${LOCALBASE}/linux-ibm-jdk1.3.1
_JAVA_HOME_IBM_LINUX_1_4=		${LOCALBASE}/linux-ibm-jdk1.4.1
_JAVA_HOME_SUN_LINUX_1_2=		${LOCALBASE}/linux-sun-jdk1.2.2
_JAVA_HOME_SUN_LINUX_1_3=		${LOCALBASE}/linux-sun-jdk1.3.1
_JAVA_HOME_SUN_LINUX_1_4=		${LOCALBASE}/linux-sun-jdk1.4.2

# Set the JDK ports for all recognized JDK's
_JAVA_PORT_FREEBSD_1_1=			java/jdk11
_JAVA_PORT_FREEBSD_1_2=			java/jdk12
_JAVA_PORT_FREEBSD_1_3=			java/jdk13
_JAVA_PORT_FREEBSD_1_4=			java/jdk14
_JAVA_PORT_DIABLO_FREEBSD_1_3=		java/diablo-jdk13
_JAVA_PORT_BLACKDOWN_LINUX_1_2=	java/linux-blackdown-jdk12
_JAVA_PORT_BLACKDOWN_LINUX_1_3=	java/linux-blackdown-jdk13
_JAVA_PORT_BLACKDOWN_LINUX_1_4=	java/linux-blackdown-jdk14
_JAVA_PORT_IBM_LINUX_1_3=		java/linux-ibm-jdk13
_JAVA_PORT_IBM_LINUX_1_4=		java/linux-ibm-jdk14
_JAVA_PORT_SUN_LINUX_1_2=		java/linux-sun-jdk12
_JAVA_PORT_SUN_LINUX_1_3=		java/linux-sun-jdk13
_JAVA_PORT_SUN_LINUX_1_4=		java/linux-sun-jdk14

# Set the name of the file that indicates that a JDK is indeed installed, as a
# relative path within the JAVA_HOME directory.
_JDK_FILE=bin/javac

# Set the path to Jikes and define the Jikes dependency
_JIKES_PATH=	${LOCALBASE}/bin/jikes
_DEPEND_JIKES=	${_JIKES_PATH}:${PORTSDIR}/java/jikes


#-----------------------------------------------------------------------------
# Stage 2: Determine which JDK ports are installed
#

.		undef HAVE_JAVA_FREEBSD_1_1
.		undef HAVE_JAVA_FREEBSD_1_2
.		undef HAVE_JAVA_FREEBSD_1_3
.		undef HAVE_JAVA_FREEBSD_1_4
.		undef HAVE_JAVA_DIABLO_FREEBSD_1_3
.		undef HAVE_JAVA_BLACKDOWN_LINUX_1_2
.		undef HAVE_JAVA_BLACKDOWN_LINUX_1_3
.		undef HAVE_JAVA_BLACKDOWN_LINUX_1_4
.		undef HAVE_JAVA_IBM_LINUX_1_3
.		undef HAVE_JAVA_IBM_LINUX_1_4
.		undef HAVE_JAVA_SUN_LINUX_1_2
.		undef HAVE_JAVA_SUN_LINUX_1_3
.		undef HAVE_JAVA_SUN_LINUX_1_4

.		if exists(${_JAVA_HOME_FREEBSD_1_1}/${_JDK_FILE})
HAVE_JAVA_FREEBSD_1_1=	YES
.		endif
.		if exists(${_JAVA_HOME_FREEBSD_1_2}/${_JDK_FILE})
HAVE_JAVA_FREEBSD_1_2=	YES
.		endif
.		if exists(${_JAVA_HOME_FREEBSD_1_3}/${_JDK_FILE})
HAVE_JAVA_FREEBSD_1_3=	YES
.		endif
.		if exists(${_JAVA_HOME_FREEBSD_1_4}/${_JDK_FILE})
HAVE_JAVA_FREEBSD_1_4=	YES
.		endif
.		if exists(${_JAVA_HOME_DIABLO_FREEBSD_1_3}/${_JDK_FILE})
HAVE_JAVA_DIABLO_FREEBSD_1_3=	YES
.		endif
.		if exists(${_JAVA_HOME_BLACKDOWN_LINUX_1_2}/${_JDK_FILE})
HAVE_JAVA_BLACKDOWN_LINUX_1_2=	YES
.		endif
.		if exists(${_JAVA_HOME_BLACKDOWN_LINUX_1_3}/${_JDK_FILE})
HAVE_JAVA_BLACKDOWN_LINUX_1_3=	YES
.		endif
.		if exists(${_JAVA_HOME_BLACKDOWN_LINUX_1_4}/${_JDK_FILE})
HAVE_JAVA_BLACKDOWN_LINUX_1_4=	YES
.		endif
.		if exists(${_JAVA_HOME_IBM_LINUX_1_3}/${_JDK_FILE})
HAVE_JAVA_IBM_LINUX_1_3=	YES
.		endif
.		if exists(${_JAVA_HOME_IBM_LINUX_1_4}/${_JDK_FILE})
HAVE_JAVA_IBM_LINUX_1_4=	YES
.		endif
.		if exists(${_JAVA_HOME_SUN_LINUX_1_2}/${_JDK_FILE})
HAVE_JAVA_SUN_LINUX_1_2=	YES
.		endif
.		if exists(${_JAVA_HOME_SUN_LINUX_1_3}/${_JDK_FILE})
HAVE_JAVA_SUN_LINUX_1_3=	YES
.		endif
.		if exists(${_JAVA_HOME_SUN_LINUX_1_4}/${_JDK_FILE})
HAVE_JAVA_SUN_LINUX_1_4=	YES
.		endif


#-----------------------------------------------------------------------------
# Stage 3: Deal with JAVA_HOME if it is already set
#

# See if JAVA_HOME points to a known JDK. If it does, then undefine JAVA_HOME
# and actually use JAVA_PORT instead, so that we do not screw with our
# dependencies.
.		if defined(JAVA_HOME)
_JAVA_HOME=	${JAVA_HOME}
.			undef(JAVA_HOME)
.			if ${_JAVA_HOME} == ${_JAVA_HOME_FREEBSD_1_1}
JAVA_PORT=	${_JAVA_PORT_FREEBSD_1_1}
.			elif ${_JAVA_HOME} == ${_JAVA_HOME_FREEBSD_1_2}
JAVA_PORT=	${_JAVA_PORT_FREEBSD_1_2}
.			elif ${_JAVA_HOME} == ${_JAVA_HOME_FREEBSD_1_3}
JAVA_PORT=	${_JAVA_PORT_FREEBSD_1_3}
.			elif ${_JAVA_HOME} == ${_JAVA_HOME_FREEBSD_1_4}
JAVA_PORT=	${_JAVA_PORT_FREEBSD_1_4}
.			elif ${_JAVA_HOME} == ${_JAVA_HOME_DIABLO_FREEBSD_1_3}
JAVA_PORT=	${_JAVA_PORT_DIABLO_FREEBSD_1_3}
.			elif ${_JAVA_HOME} == ${_JAVA_HOME_BLACKDOWN_LINUX_1_2}
JAVA_PORT=	${_JAVA_PORT_BLACKDOWN_LINUX_1_2}
.			elif ${_JAVA_HOME} == ${_JAVA_HOME_BLACKDOWN_LINUX_1_3}
JAVA_PORT=	${_JAVA_PORT_BLACKDOWN_LINUX_1_3}
.			elif ${_JAVA_HOME} == ${_JAVA_HOME_BLACKDOWN_LINUX_1_4}
JAVA_PORT=	${_JAVA_PORT_BLACKDOWN_LINUX_1_4}
.			elif ${_JAVA_HOME} == ${_JAVA_HOME_IBM_LINUX_1_3}
JAVA_PORT=	${_JAVA_PORT_IBM_LINUX_1_3}
.			elif ${_JAVA_HOME} == ${_JAVA_HOME_IBM_LINUX_1_4}
JAVA_PORT=	${_JAVA_PORT_IBM_LINUX_1_4}
.			elif ${_JAVA_HOME} == ${_JAVA_HOME_SUN_LINUX_1_2}
JAVA_PORT=	${_JAVA_PORT_SUN_LINUX_1_2}
.			elif ${_JAVA_HOME} == ${_JAVA_HOME_SUN_LINUX_1_3}
JAVA_PORT=	${_JAVA_PORT_SUN_LINUX_1_3}
.			elif ${_JAVA_HOME} == ${_JAVA_HOME_SUN_LINUX_1_4}
JAVA_PORT=	${_JAVA_PORT_SUN_LINUX_1_4}
.			else
JAVA_HOME=	${_JAVA_HOME}
.			endif
.		endif


#-----------------------------------------------------------------------------
# Stage 4: Decide the exact JDK version if only a minimum version is specified
#
# If USE_JAVA is 1.1+, 1.2+, 1.3+ or 1.4+, then set it to 1.1, 1.2, 1.3 or
# 1.4, depending on what JDK's are already installed. The FreeBSD JDK will be
# preferred. Any JDK 1.4 for Linux are always the least preferred JDK.
# However, the most respected rule is that if a JDK is already installed, then
# no JDK will be downloaded unless necessary.
#
# The following rules will be used, per setting:
#
# If the setting is 1.1+, then use an existing 1.2, 1.3 or 1.4 JDK if installed,
# otherwise use the JDK 1.1.8 for FreeBSD if it is already installed. The
# FreeBSD JDK 1.4 is preferred over any JDK's.
#
# If the setting is 1.2+, then use an already installed 1.2, 1.3 or 1.4 JDK.
# If there is no such JDK, then set USE_JAVA to 1.2. The FreeBSD JDK 1.4 or
# any of 1.3 JDK is preferred over 1.2 JDK's.
#
# If the setting is 1.3+, then use an already installed 1.3 or 1.4 JDK. If
# there is no such JDK, then set USE_JAVA to 1.3. The FreeBSD JDK 1.4 is
# preferred over all other JDK's.
#
# If the setting is 1.4+, then set it to 1.4 right away. There is no other
# option at the moment.

.		if (${USE_JAVA} == "1.1+")
.			if defined(HAVE_JAVA_FREEBSD_1_4)
USE_JAVA=	1.4
.			elif defined(HAVE_JAVA_DIABLO_FREEBSD_1_3) || \
			   defined(HAVE_JAVA_FREEBSD_1_3) || \
			   defined(HAVE_JAVA_SUN_LINUX_1_3) || \
			   defined(HAVE_JAVA_BLACKDOWN_LINUX_1_3) || \
			   defined(HAVE_JAVA_IBM_LINUX_1_3)
USE_JAVA=	1.3
.			elif defined(HAVE_JAVA_FREEBSD_1_2) || \
			     defined(HAVE_JAVA_BLACKDOWN_LINUX_1_2) || \
			     defined(HAVE_JAVA_SUN_LINUX_1_2)
USE_JAVA=	1.2
.			elif !defined(HAVE_JAVA_SUN_LINUX_1_4) && \
				 !defined(HAVE_JAVA_BLACKDOWN_LINUX_1_4) && \
				 !defined(HAVE_JAVA_IBM_LINUX_1_4)
USE_JAVA=	1.1
.			else
USE_JAVA=	1.4
.			endif

.		elif (${USE_JAVA} == "1.2+")
.			if defined(HAVE_JAVA_FREEBSD_1_4)
USE_JAVA=	1.4
.			elif defined(HAVE_JAVA_DIABLO_FREEBSD_1_3) || \
			   defined(HAVE_JAVA_FREEBSD_1_3) || \
			   defined(HAVE_JAVA_SUN_LINUX_1_3) || \
			   defined(HAVE_JAVA_BLACKDOWN_LINUX_1_3) || \
			   defined(HAVE_JAVA_IBM_LINUX_1_3)
USE_JAVA=	1.3
.			elif !defined(HAVE_JAVA_SUN_LINUX_1_4) && \
				 !defined(HAVE_JAVA_BLACKDOWN_LINUX_1_4) && \
				 !defined(HAVE_JAVA_IBM_LINUX_1_4)
USE_JAVA=	1.2
.			else
USE_JAVA=	1.4
.			endif

.		elif (${USE_JAVA} == "1.3+")
.			if defined(HAVE_JAVA_FREEBSD_1_4)
USE_JAVA=	1.4
.			elif defined(HAVE_JAVA_DIABLO_FREEBSD_1_3) || \
			   defined(HAVE_JAVA_FREEBSD_1_3) || \
			   defined(HAVE_JAVA_SUN_LINUX_1_3) || \
			   defined(HAVE_JAVA_IBM_LINUX_1_3) || \
			   defined(HAVE_JAVA_BLACKDOWN_LINUX_1_3)
USE_JAVA=	1.3
.			elif defined(HAVE_JAVA_SUN_LINUX_1_4) || \
			   defined(HAVE_JAVA_IBM_LINUX_1_4) || \
			   defined(HAVE_JAVA_BLACKDOWN_LINUX_1_4)
USE_JAVA=	1.4
.			else
USE_JAVA=	1.3
.			endif

.		elif (${USE_JAVA} == "1.4+")
USE_JAVA=	1.4
.		endif


#-----------------------------------------------------------------------------
# Stage 5: Decide the exact JDK to use
#

# Apply different settings for different values of USE_JAVA.
#
# If the port needs Java 1.1, then there's only one choice, the JDK 1.1.8 for
# FreeBSD.
.		if (${USE_JAVA} == "1.1")
JAVA_VENDOR=	FreeBSD
JAVA_VER=		1.1.8
JAVA_OS=		FreeBSD
JAVA_HOME=		${_JAVA_HOME_FREEBSD_1_1}
JAVA_PORT=		${_JAVA_PORT_FREEBSD_1_1}

# If the port needs Java 1.2, then there are 3 choices. They are, in order or
# preference:
#
#    (1) JDK 1.2.2 for FreeBSD
#    (2) Blackdown JDK 1.2.2 for Linux
#    (3) Sun JDK 1.2.2 for Linux
#
# If either the Blackdown or Sun JDK 1.2.2 (both for Linux) is installed, but
# the FreeBSD JDK 1.2.2 is *not* installed, then the installed Linux JDK will
# be used as the dependency. Otherwise the FreeBSD JDK 1.2.2 will be used as
# the dependency.
#
# The FreeBSD JDK 1.2 is preferred over the Linux JDK's. Among these, the
# Blackdown JDK is preferred over the Sun JDK.
#
.		elif ${USE_JAVA} == "1.2"
.			if defined(HAVE_JAVA_BLACKDOWN_LINUX_1_2) \
			&& !defined(HAVE_JAVA_FREEBSD_1_2)
JAVA_VENDOR=	Blackdown
JAVA_VER=		1.2.2
JAVA_OS=		Linux
JAVA_HOME=		${_JAVA_HOME_BLACKDOWN_LINUX_1_2}
JAVA_PORT=		${_JAVA_PORT_BLACKDOWN_LINUX_1_2}
.			elif defined(HAVE_JAVA_SUN_LINUX_1_2) \
			&& !defined(HAVE_JAVA_FREEBSD_1_2)
JAVA_VENDOR=	Sun
JAVA_VER=		1.2.2
JAVA_OS=		Linux
JAVA_HOME=		${_JAVA_HOME_SUN_LINUX_1_2}
JAVA_PORT=		${_JAVA_PORT_SUN_LINUX_1_2}
.			else
JAVA_VENDOR=	FreeBSD
JAVA_VER=		1.2.2
JAVA_OS=		FreeBSD
JAVA_HOME=		${_JAVA_HOME_FREEBSD_1_2}
JAVA_PORT=		${_JAVA_PORT_FREEBSD_1_2}
.			endif

# If the port needs Java 1.3, then there are 4 choices. They are, in order or
# preference:
#
#    (1) Diablo JDK 1.3.1 for FreeBSD
#    (2) JDK 1.3.1 for FreeBSD
#    (3) Sun JDK 1.3.1 for Linux
#    (4) IBM JDK 1.3.1 for Linux
#    (5) Blackdown JDK 1.3.1 for Linux
#
# If the FreeBSD JDK 1.3.1 is installed or if none of the 1.3.1 JDK's is
# installed, then the FreeBSD JDK 1.3.1 is used as a dependency for the port.
#
# Otherwise, one of the installed Linux JDKs is chosen, based on their
# preferences.
#
.		elif ${USE_JAVA} == "1.3"
.			if defined(HAVE_JAVA_BLACKDOWN_LINUX_1_3) \
			&& !defined(HAVE_JAVA_IBM_LINUX_1_3) \
			&& !defined(HAVE_JAVA_SUN_LINUX_1_3) \
			&& !defined(HAVE_JAVA_FREEBSD_1_3) \
			&& !defined(HAVE_JAVA_DIABLO_FREEBSD_1_3)
JAVA_VENDOR=	Blackdown
JAVA_VER=		1.3.1
JAVA_OS=		Linux
JAVA_HOME=		${_JAVA_HOME_BLACKDOWN_LINUX_1_3}
JAVA_PORT=		${_JAVA_PORT_BLACKDOWN_LINUX_1_3}
.			elif defined(HAVE_JAVA_IBM_LINUX_1_3) \
			&& !defined(HAVE_JAVA_SUN_LINUX_1_3) \
			&& !defined(HAVE_JAVA_FREEBSD_1_3) \
			&& !defined(HAVE_JAVA_DIABLO_FREEBSD_1_3)
JAVA_VENDOR=	IBM
JAVA_VER=		1.3.1
JAVA_OS=		Linux
JAVA_HOME=		${_JAVA_HOME_IBM_LINUX_1_3}
JAVA_PORT=		${_JAVA_PORT_IBM_LINUX_1_3}
.			elif defined(HAVE_JAVA_SUN_LINUX_1_3) \
			&& !defined(HAVE_JAVA_FREEBSD_1_3) \
			&& !defined(HAVE_JAVA_DIABLO_FREEBSD_1_3)
JAVA_VENDOR=	Sun
JAVA_VER=		1.3.1
JAVA_OS=		Linux
JAVA_HOME=		${_JAVA_HOME_SUN_LINUX_1_3}
JAVA_PORT=		${_JAVA_PORT_SUN_LINUX_1_3}
.			elif defined(HAVE_JAVA_FREEBSD_1_3) \
			&& !defined(HAVE_JAVA_DIABLO_FREEBSD_1_3)
JAVA_VENDOR=	FreeBSD
JAVA_VER=		1.3.1
JAVA_OS=		FreeBSD
JAVA_HOME=		${_JAVA_HOME_FREEBSD_1_3}
JAVA_PORT=		${_JAVA_PORT_FREEBSD_1_3}
.			else
JAVA_VENDOR=	FreeBSD Foundation
JAVA_VER=		1.3.1
JAVA_OS=		FreeBSD
JAVA_HOME=		${_JAVA_HOME_DIABLO_FREEBSD_1_3}
JAVA_PORT=		${_JAVA_PORT_DIABLO_FREEBSD_1_3}
.			endif

# If the port needs Java 1.4, then there are 4 choices. They are, in order or
# preference:
#
#    (1) JDK 1.4.2 for FreeBSD
#    (2) Sun JDK 1.4.2 for Linux
#    (3) IBM JDK 1.4.1 for Linux
#    (4) Blackdown JDK 1.4.1 for Linux
#
# If the FreeBSD JDK 1.4.2 is installed or if none of the 1.4.1 JDK's is
# installed, then the FreeBSD JDK 1.4.2 is used as a dependency for the port.
#
# Otherwise, one of the installed Linux JDKs is chosen, based on their
# preferences.
#
.		elif ${USE_JAVA} == "1.4"
.			if defined(HAVE_JAVA_BLACKDOWN_LINUX_1_4) \
			&& !defined(HAVE_JAVA_IBM_LINUX_1_4) \
			&& !defined(HAVE_JAVA_SUN_LINUX_1_4) \
			&& !defined(HAVE_JAVA_FREEBSD_1_4)
JAVA_VENDOR=	Blackdown
JAVA_VER=		1.4.1
JAVA_OS=		Linux
JAVA_HOME=		${_JAVA_HOME_BLACKDOWN_LINUX_1_4}
JAVA_PORT=		${_JAVA_PORT_BLACKDOWN_LINUX_1_4}
.			elif defined(HAVE_JAVA_IBM_LINUX_1_4) \
			&& !defined(HAVE_JAVA_SUN_LINUX_1_4) \
			&& !defined(HAVE_JAVA_FREEBSD_1_4)
JAVA_VENDOR=	IBM
JAVA_VER=		1.4.1
JAVA_OS=		Linux
JAVA_HOME=		${_JAVA_HOME_IBM_LINUX_1_4}
JAVA_PORT=		${_JAVA_PORT_IBM_LINUX_1_4}
.			elif defined(HAVE_JAVA_SUN_LINUX_1_4) \
			&& !defined(HAVE_JAVA_FREEBSD_1_4)
JAVA_VENDOR=	Sun
JAVA_VER=		1.4.2
JAVA_OS=		Linux
JAVA_HOME=		${_JAVA_HOME_SUN_LINUX_1_4}
JAVA_PORT=		${_JAVA_PORT_SUN_LINUX_1_4}
.			else
JAVA_VENDOR=	FreeBSD
JAVA_VER=		1.4.2
JAVA_OS=		FreeBSD
JAVA_HOME=		${_JAVA_HOME_FREEBSD_1_4}
JAVA_PORT=		${_JAVA_PORT_FREEBSD_1_4}
.			endif

#
# Port wants something that we do not understand.  Stop here.
#
.		else
check-makevers::
	@${ECHO} "${PKGNAME}: Makefile error: \"${USE_JAVA}\" is not a valid value for USE_JAVA. It should be one of: ${_JAVA_VERSIONS} (with an optional \"+\" suffix.)";
	@${FALSE}
.		endif


#-----------------------------------------------------------------------------
# Stage 6: Define all settings for the port to use

# At this stage both JAVA_HOME and JAVA_PORT are definitely given a value.

# Define the location of the Java compiler. If USE_JIKES is set to YES, then
# use Jikes. If USE_JIKES is set to NO, then don't use it. If it is set to a
# different value, then fail with an error message. Otherwise USE_JIKES is not
# set, in which case it is checked if Jikes is already installed. If it is,
# then it will be used, otherwise it will not be used.

# Only define JAVAC if NEED_JAVAC is defined
.		undef JAVAC

# By default a port does not need the Java compiler
.		if !defined(NEED_JAVAC)
NEED_JAVAC=	NO
.		endif

.		if (${NEED_JAVAC} == "YES") || (${NEED_JAVAC} == "yes")
.			if defined(USE_JIKES)
.				if (${USE_JIKES} == "YES") || (${USE_JIKES} == "yes")
JAVAC=		${_JIKES_PATH}
WITH_JIKES=	YES
.				elif !((${USE_JIKES} == "NO") || (${USE_JIKES} == "no"))
check-makevers::
	@${ECHO} "${PKGNAME}: Makefile error: \"${USE_JIKES}\" is not a valid value for USE_JIKES. It should be YES or NO, or it should be undefined.";
	@${FALSE}
.				endif
.			elif exists(${_JIKES_PATH}) && !defined(NO_BUILD)
JAVAC=		${_JIKES_PATH}
WITH_JIKES=	YES
.			endif
.			if !defined(JAVAC)
JAVAC=	${JAVA_HOME}/bin/javac
.			endif
.		endif

# Define the location of some more executables.
APPLETVIEWER=	${JAVA_HOME}/bin/appletviewer
JAR=			${JAVA_HOME}/bin/jar
JAVA=			${JAVA_HOME}/bin/java
JAVADOC=		${JAVA_HOME}/bin/javadoc
JAVAH=			${JAVA_HOME}/bin/javah
JAVAP=			${JAVA_HOME}/bin/javap
JAVA_N2A=		${JAVA_HOME}/bin/native2ascii
JAVA_SERIALVER=	${JAVA_HOME}/bin/serialver
RMIC=			${JAVA_HOME}/bin/rmic
RMIREGISTRY=	${JAVA_HOME}/bin/rmiregistry

# Some executables only exists in JDK 1.2 and up
.		if defined(USE_JAVA) && ${USE_JAVA} != 1.1
JAVA_KEYTOOL=		${JAVA_HOME}/bin/keytool
JAVA_POLICYTOOL=	${JAVA_HOME}/bin/policytool
RMID=				${JAVA_HOME}/bin/rmid
.		endif

# Set the location of the ZIP or JAR file with all standard Java classes.
.		if defined(USE_JAVA) && ${USE_JAVA} == "1.1"
JAVA_CLASSES=	${JAVA_HOME}/lib/classes.zip
.		else
JAVA_CLASSES=	${JAVA_HOME}/jre/lib/rt.jar
.		endif


#-----------------------------------------------------------------------------
# Stage 7: Add any dependencies if necessary

# Possibly add Jikes to the dependencies
.		if defined(JAVAC) && (${JAVAC} == ${_JIKES_PATH})
.			if !defined(NO_BUILD_DEPENDS_JAVA)
BUILD_DEPENDS+=		${_DEPEND_JIKES}
.			endif
.			if !defined(NO_RUN_DEPENDS_JAVA)
RUN_DEPENDS+=		${_DEPEND_JIKES}
.			endif
.		endif

# Add the JDK port to the dependencies
.		if defined(NO_BUILD_DEPENDS_JAVA) && defined(NO_RUN_DEPENDS_JAVA)
check-makevers::
	@${ECHO} "${PKGNAME}: Makefile error: NO_BUILD_DEPENDS_JAVA and NO_RUN_DEPENDS_JAVA cannot be set at the same time.";
	@${FALSE}
.		endif
_DEPEND_JAVA=	${JAVA}:${PORTSDIR}/${JAVA_PORT}
.		if !defined(NO_BUILD_DEPENDS_JAVA)
BUILD_DEPENDS+=		${_DEPEND_JAVA}
.		endif
.		if !defined(NO_RUN_DEPENDS_JAVA)
RUN_DEPENDS+=		${_DEPEND_JAVA}
.		endif
.	endif
.endif
