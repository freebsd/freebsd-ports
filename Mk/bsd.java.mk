#-*- tab-width: 4; -*-
# ex:ts=4
#
# bsd.java.mk - Support for Java-based ports.
#
# Created by: Ernst de Haan <znerd@FreeBSD.org>
#
# For FreeBSD committers:
# Please send all suggested changes to the maintainer instead of committing
# them to svn yourself.
#
# $FreeBSD$
#

.if !defined(Java_Include)

Java_Include=				bsd.java.mk
Java_Include_MAINTAINER=	java@FreeBSD.org

#-------------------------------------------------------------------------------
# Variables that each port can define:
#
# USE_JAVA			Should be defined to the remaining variables to have any
#					effect
#
# JAVA_VERSION		List of space-separated suitable java versions for the
#					port. An optional "+" allows you to specify a range of
#					versions. (allowed values: 7[+] 8[+] 11[+] 12[+] 13[+])
#
# JAVA_OS			List of space-separated suitable JDK port operating systems
#					for the port. (allowed values: native linux)
#
# JAVA_VENDOR		List of space-separated suitable JDK port vendors for the
#					port. (allowed values: openjdk oracle)
#
# JAVA_BUILD		When set, it means that the selected JDK port should be
#					added to build dependencies for the port.
#
# JAVA_EXTRACT		This variable works exactly the same as JAVA_BUILD but
#					regarding extract dependencies.
#
# JAVA_RUN			This variable works exactly the same as JAVA_BUILD but
#					regarding run dependencies.
#
# USE_ANT			Should be defined when the port uses Apache Ant. Ant is thus
#					considered to be the sub-make command. When no 'do-build'
#					target is defined by the port, a default one will be set
#					that simply runs Ant according to MAKE_ENV, MAKE_ARGS and
#					ALL_TARGET. Read the documentation in bsd.port.mk for more
#					information.
#
#-------------------------------------------------------------------------------
# Variables defined for the port:
#
# JAVA_PORT			The name of the JDK port. (e.g. 'java/openjdk8')
#
# JAVA_PORT_VERSION	The version of the JDK port. (e.g. '8')
#
# JAVA_PORT_OS		The operating system used by the JDK port. (e.g. 'linux')
#
# JAVA_PORT_VENDOR	The vendor of the JDK port. (e.g. 'openjdk')
#
# JAVA_PORT_OS_DESCRIPTION		Description of the operating system used by the
#								JDK port. (e.g. 'Linux')
#
# JAVA_PORT_VENDOR_DESCRIPTION	Description of the vendor of the JDK port.
#								(e.g. 'OpenJDK BSD Porting Team')
#
# JAVA_HOME			Path to the installation directory of the JDK. (e.g.
#					'/usr/local/openjdk8')
#
# JAVAC				Path to the Java compiler to use. (e.g.
#					'/usr/local/openjdk8/bin/javac' or '/usr/local/bin/javac')
#
# JAR				Path to the JAR tool to use. (e.g.
#					'/usr/local/openjdk8/bin/jar' or '/usr/local/bin/fastjar')
#
# APPLETVIEWER		Path to the appletviewer utility. (e.g.
#					'/usr/local/linux-jdk1.8.0/bin/appletviewer')
#
# JAVA				Path to the java executable. Use this for executing Java
#					programs. (e.g. '/usr/local/openjdk8/bin/java')
#
# JAVADOC			Path to the javadoc utility program.
#
# JAVAH				Path to the javah program.
#
# JAVAP				Path to the javap program.
#
# JAVA_KEYTOOL		Path to the keytool utility program.
#
# JAVA_N2A			Path to the native2ascii tool.
#
# JAVA_POLICYTOOL	Path to the policytool program.
#
# JAVA_SERIALVER	Path to the serialver utility program.
#
# RMIC				Path to the RMI stub/skeleton generator, rmic.
#
# RMIREGISTRY		Path to the RMI registry program, rmiregistry.
#
# RMID				Path to the RMI daemon program.
#
# JAVA_CLASSES		Path to the archive that contains the JDK class files. On
#					most JDKs, this is ${JAVA_HOME}/jre/lib/rt.jar.
#
# JAVASHAREDIR		The base directory for all shared Java resources.
#
# JAVAJARDIR		The directory where a port should install JAR files.
#
# JAVALIBDIR		The directory where JAR files installed by other ports
#					are located.
#
#-------------------------------------------------------------------------------
# Porter's hints
#
# To retrieve the Major version number from JAVA_PORT_VERSION (e.g. "1.8"):
#		-> ${JAVA_PORT_VERSION:C/^([0-9])\.([0-9])(.*)$/\1.\2/}
#
#-------------------------------------------------------------------------------
# There are the following stages:
#
# Stage 1: Define constants
# Stage 2: Determine which JDK ports are installed and which JDK ports are
#		   suitable
# Stage 3: Decide the exact JDK to use (or install)
# Stage 4: Add any dependencies if necessary
# Stage 5: Define all settings for the port to use
#

.	if defined(USE_JAVA)

.		if !defined(JAVA_VERSION) && empty(USE_JAVA:C/[0-9]*[\.]*[0-9]*[+]*//)
JAVA_VERSION=${USE_JAVA}
.		endif

#-------------------------------------------------------------------------------
# Stage 1: Define constants
#

# System-global directories
# NB: If the value of JAVALIBDIR is altered here it must also be altered
#	  in java/javavmwrapper/Makefile.
JAVASHAREDIR?=	${PREFIX}/share/java
JAVAJARDIR?=	${JAVASHAREDIR}/classes
JAVALIBDIR?=	${LOCALBASE}/share/java/classes

# Add appropriate substitutions to PLIST_SUB and LIST_SUB
PLIST_SUB+=		JAVASHAREDIR="${JAVASHAREDIR:S,^${PREFIX}/,,}" \
				JAVAJARDIR="${JAVAJARDIR:S,^${PREFIX}/,,}"
SUB_LIST+=		JAVASHAREDIR="${JAVASHAREDIR}" \
				JAVAJARDIR="${JAVAJARDIR}" \
				JAVALIBDIR="${JAVALIBDIR}"
.		if defined(JAVA_VERSION)
SUB_LIST+=		JAVA_VERSION="${JAVA_VERSION}"
.		endif
.		if defined(JAVA_VENDOR)
SUB_LIST+=		JAVA_VENDOR="${JAVA_VENDOR}"
.		endif
.		if defined(JAVA_OS)
SUB_LIST+=		JAVA_OS="${JAVA_OS}"
.		endif

# The complete list of Java versions, os and vendors supported.
__JAVA_VERSION_LIST=	7 8 11 12 13
_JAVA_VERSION_LIST=		${__JAVA_VERSION_LIST} ${__JAVA_VERSION_LIST:S/$/+/}
_JAVA_OS_LIST=			native linux
_JAVA_VENDOR_LIST=		openjdk oracle

# Set all meta-information about JDK ports:
# port location, corresponding JAVA_HOME, JDK version, OS, vendor
_JAVA_PORT_NATIVE_OPENJDK_JDK_7_INFO=		PORT=java/openjdk7			HOME=${LOCALBASE}/openjdk7 \
											VERSION=7	OS=native	VENDOR=openjdk
_JAVA_PORT_NATIVE_OPENJDK_JDK_8_INFO=		PORT=java/openjdk8			HOME=${LOCALBASE}/openjdk8 \
											VERSION=8	OS=native	VENDOR=openjdk
_JAVA_PORT_NATIVE_OPENJDK_JDK_11_INFO=		PORT=java/openjdk11			HOME=${LOCALBASE}/openjdk11 \
											VERSION=11	OS=native	VENDOR=openjdk
_JAVA_PORT_NATIVE_OPENJDK_JDK_12_INFO=		PORT=java/openjdk12			HOME=${LOCALBASE}/openjdk12 \
											VERSION=12	OS=native	VENDOR=openjdk
_JAVA_PORT_NATIVE_OPENJDK_JDK_13_INFO=		PORT=java/openjdk13			HOME=${LOCALBASE}/openjdk13 \
											VERSION=13	OS=native	VENDOR=openjdk
_JAVA_PORT_LINUX_ORACLE_JDK_8_INFO=		PORT=java/linux-oracle-jdk18	HOME=${LOCALBASE}/linux-oracle-jdk1.8.0 \
											VERSION=8	OS=linux	VENDOR=oracle

# Verbose description for each VENDOR
_JAVA_VENDOR_openjdk=		"OpenJDK BSD Porting Team"
_JAVA_VENDOR_oracle=		Oracle

# Verbose description for each OS
_JAVA_OS_native=	Native
_JAVA_OS_linux=		Linux

# List all JDK ports in order of preference
__JAVA_PORTS_ALL=	\
					JAVA_PORT_NATIVE_OPENJDK_JDK_8  \
					JAVA_PORT_NATIVE_OPENJDK_JDK_11 \
					JAVA_PORT_NATIVE_OPENJDK_JDK_12 \
					JAVA_PORT_NATIVE_OPENJDK_JDK_13 \
					JAVA_PORT_NATIVE_OPENJDK_JDK_7  \
					JAVA_PORT_LINUX_ORACLE_JDK_8
_JAVA_PORTS_ALL=	${JAVA_PREFERRED_PORTS} \
					${__JAVA_PORTS_ALL}

# Set the name of the file that indicates that a JDK is indeed installed, as a
# relative path within the JAVA_HOME directory.
_JDK_FILE=bin/javac

#-------------------------------------------------------------------------------
# Stage 2: Determine which JDK ports are suitable and which JDK ports are
# suitable
#

# From here, the port is using bsd.java.mk v2.0

# Error checking: defined JAVA_{HOME,PORT,PORT_VERSION,PORT_VENDOR,PORT_OS}
.		for variable in JAVA_HOME JAVA_PORT JAVA_PORT_VERSION JAVA_PORT_VENDOR JAVA_PORT_OS
.			if defined(${variable})
check-makevars::
	@${ECHO_CMD} "${PKGNAME}: Environment error: \"${variable}\" should not be defined -- clearing."
.undef				${variable}
.			endif
.		endfor

# Error checking: JAVA_VERSION
.if defined(JAVA_VERSION)
.if !defined(_JAVA_VERSION_LIST_REGEXP)
_JAVA_VERSION_LIST_REGEXP=	${_JAVA_VERSION_LIST:C/\+/\\+/:ts|}
.endif

check-makevars::
	@( test ! -z "${JAVA_VERSION}" && ( ${ECHO_CMD} "${JAVA_VERSION}" | ${TR} " " "\n" | ${GREP} -Eq "${_JAVA_VERSION_LIST_REGEXP}")) || \
	(${ECHO_CMD} "${PKGNAME}: Makefile error: \"${JAVA_VERSION}\" is not a valid value for JAVA_VERSION. It should be one or more of: ${__JAVA_VERSION_LIST} (with an optional \"+\" suffix.)"; ${FALSE})
.endif

# Error checking: JAVA_VENDOR
.if defined(JAVA_VENDOR)
.if !defined(_JAVA_VENDOR_LIST_REGEXP)
_JAVA_VENDOR_LIST_REGEXP=	${_JAVA_VENDOR_LIST:ts|}
.endif

check-makevars::
	@( test ! -z "${JAVA_VENDOR}" && ( ${ECHO_CMD} "${JAVA_VENDOR}" | ${TR} " " "\n" | ${GREP} -Eq "${_JAVA_VENDOR_LIST_REGEXP}" )) || \
	(${ECHO_CMD} "${PKGNAME}: Makefile error: \"${JAVA_VENDOR}\" is not a valid value for JAVA_VENDOR. It should be one or more of: ${_JAVA_VENDOR_LIST}"; \
	${FALSE})
.endif

# Error checking: JAVA_OS
.if defined(JAVA_OS)
.if !defined(_JAVA_OS_LIST_REGEXP)
_JAVA_OS_LIST_REGEXP=	${_JAVA_OS_LIST:ts|}
.endif

check-makevars::
	@( test ! -z "${JAVA_OS}" && ( ${ECHO_CMD} "${JAVA_OS}" | ${TR} " " "\n" | ${GREP} -Eq "${_JAVA_OS_LIST_REGEXP}")) || \
	(${ECHO_CMD} "${PKGNAME}: Makefile error: \"${JAVA_OS}\" is not a valid value for JAVA_OS. It should be one or more of: ${_JAVA_OS_LIST}"; \
	${FALSE})
.endif

# Set default values for JAVA_BUILD and JAVA_RUN
# When nothing is set, assume JAVA_BUILD=jdk and JAVA_RUN=jre
# (unless NO_BUILD is set)
.		if !defined(JAVA_EXTRACT) && !defined(JAVA_BUILD) && !defined(JAVA_RUN)
.			if !defined(NO_BUILD)
JAVA_BUILD=	jdk
.			endif
JAVA_RUN=	jre
.		endif

# JDK dependency setting
.		undef _JAVA_PORTS_INSTALLED
.		undef _JAVA_PORTS_POSSIBLE
.		if defined(JAVA_VERSION)
_JAVA_VERSION=	${JAVA_VERSION:S/1.7+/1.7 1.8+/:S/1.8+/1.8 11+/:S/1.7/7/:S/1.8/8/:S/7+/7 8+/:S/8+/8 11+/:S/11+/11 12+/:S/12+/12 13+/:S/13+/13/}
.		else
_JAVA_VERSION=	${__JAVA_VERSION_LIST}
.		endif
.		if defined(JAVA_OS)
_JAVA_OS=	${JAVA_OS}
.		else
_JAVA_OS=	${_JAVA_OS_LIST}
.		endif
.		if defined(JAVA_VENDOR)
_JAVA_VENDOR=	${JAVA_VENDOR}
.		else
_JAVA_VENDOR=	${_JAVA_VENDOR_LIST}
.		endif

.		for A_JAVA_PORT in ${_JAVA_PORTS_ALL}
A_JAVA_PORT_INFO:=			${A_JAVA_PORT:S/^/\${_/:S/$/_INFO}/}
A_JAVA_PORT_HOME=			${A_JAVA_PORT_INFO:MHOME=*:S,HOME=,,}
A_JAVA_PORT_VERSION=		${A_JAVA_PORT_INFO:MVERSION=*:S,VERSION=,,}
A_JAVA_PORT_OS=				${A_JAVA_PORT_INFO:MOS=*:S,OS=,,}
A_JAVA_PORT_VENDOR=			${A_JAVA_PORT_INFO:MVENDOR=*:S,VENDOR=,,}
.if !defined(_JAVA_PORTS_INSTALLED) && exists(${A_JAVA_PORT_HOME}/${_JDK_FILE})
__JAVA_PORTS_INSTALLED+=	${A_JAVA_PORT}
.endif

# Because variables inside for loops are special (directly replaced as strings),
# we are allowed to use them inside modifiers, where normally ${FOO:M${BAR}} is
# not allowed.
#
.for ver in ${A_JAVA_PORT_VERSION}
.for os in ${A_JAVA_PORT_OS}
.for vendor in ${A_JAVA_PORT_VENDOR}
.if ${_JAVA_VERSION:M${ver}} && ${_JAVA_OS:M${os}} && ${_JAVA_VENDOR:M${vendor}}
__JAVA_PORTS_POSSIBLE+=		${A_JAVA_PORT}
.endif
.endfor
.endfor
.endfor

.		endfor
.if !defined(_JAVA_PORTS_INSTALLED)
_JAVA_PORTS_INSTALLED=		${__JAVA_PORTS_INSTALLED:C/ [ ]+/ /g}
.endif
_JAVA_PORTS_POSSIBLE=		${__JAVA_PORTS_POSSIBLE:C/ [ ]+/ /g}


#-------------------------------------------------------------------------------
# Stage 3: Decide the exact JDK to use (or install)
#

# Find an installed JDK port that matches the requirements of the port

.		undef _JAVA_PORTS_INSTALLED_POSSIBLE

.		for A_JAVA_PORT in ${_JAVA_PORTS_POSSIBLE}
__JAVA_PORTS_INSTALLED_POSSIBLE+=	${_JAVA_PORTS_INSTALLED:M${A_JAVA_PORT}}
.		endfor
_JAVA_PORTS_INSTALLED_POSSIBLE=		${__JAVA_PORTS_INSTALLED_POSSIBLE:C/[ ]+//g}

.		if ${_JAVA_PORTS_INSTALLED_POSSIBLE} != ""
.                 for i in ${_JAVA_PORTS_INSTALLED_POSSIBLE}
.                   if !defined(_JAVA_PORTS_INSTALLED_POSSIBLE_shortcircuit)
_JAVA_PORT=	$i
_JAVA_PORTS_INSTALLED_POSSIBLE_shortcircuit=	1
.                   endif
.                 endfor
# If no installed JDK port fits, then pick one from the list of possible ones
.		else
.                 for i in ${_JAVA_PORTS_POSSIBLE}
.                   if !defined(_JAVA_PORTS_POSSIBLE_shortcircuit)
_JAVA_PORT=	$i
_JAVA_PORTS_POSSIBLE_shortcircuit=	1
.                   endif
.                 endfor
.		endif

_JAVA_PORT_INFO:=		${_JAVA_PORT:S/^/\${_/:S/$/_INFO}/}
JAVA_PORT=				${_JAVA_PORT_INFO:MPORT=*:S,PORT=,,}
JAVA_HOME=				${_JAVA_PORT_INFO:MHOME=*:S,HOME=,,}
JAVA_PORT_VERSION=		${_JAVA_PORT_INFO:MVERSION=*:S,VERSION=,,}
JAVA_PORT_OS=			${_JAVA_PORT_INFO:MOS=*:S,OS=,,}
JAVA_PORT_VENDOR=		${_JAVA_PORT_INFO:MVENDOR=*:S,VENDOR=,,}

JAVA_PORT_VENDOR_DESCRIPTION:=	${JAVA_PORT_VENDOR:S/^/\${_JAVA_VENDOR_/:S/$/}/}
JAVA_PORT_OS_DESCRIPTION:=		${JAVA_PORT_OS:S/^/\${_JAVA_OS_/:S/$/}/}

#-------------------------------------------------------------------------------
# Stage 4: Add any dependencies if necessary
#

# Ant Support: USE_ANT --> JAVA_BUILD=jdk
.		if defined(USE_ANT)
JAVA_BUILD=		jdk
.		endif

# Add the JDK port to the dependencies
DEPEND_JAVA=	${JAVA}:${JAVA_PORT}
.		if defined(JAVA_EXTRACT)
EXTRACT_DEPENDS+=	${DEPEND_JAVA}
.		endif
.		if defined(JAVA_BUILD)
.			if defined(NO_BUILD)
check-makevars::
	@${ECHO_CMD} "${PKGNAME}: Makefile error: JAVA_BUILD and NO_BUILD cannot be set at the same time.";
	@${FALSE}
.			endif
BUILD_DEPENDS+=		${DEPEND_JAVA}
.		endif
.		if defined(JAVA_RUN)
RUN_DEPENDS+=		${DEPEND_JAVA}
.		endif

# Ant support: default do-build target
.		if defined(USE_ANT)
DESTDIRNAME?=		-Dfreebsd.ports.destdir
ANT?=				${LOCALBASE}/bin/ant
MAKE_ENV+=			JAVA_HOME=${JAVA_HOME}
BUILD_DEPENDS+=		${ANT}:devel/apache-ant
ALL_TARGET?=
.			if !target(do-build)
do-build:
					@(cd ${BUILD_WRKSRC}; \
						${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} ${ALL_TARGET})
.			endif
.			if !target(do-test) && defined(TEST_TARGET)
TEST_DEPENDS+=		${DEPEND_JAVA}
TEST_DEPENDS+=		${ANT}:devel/apache-ant
do-test:
					@(cd ${TEST_WRKSRC}; \
						${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} ${TEST_TARGET})
.			endif
.		endif

#-----------------------------------------------------------------------------
# Stage 5: Define all settings for the port to use
#
# At this stage both JAVA_HOME and JAVA_PORT are definitely given a value.
#
# Define the location of the Java compiler.

# Only define JAVAC if a JDK is needed
.		undef JAVAC

# Then test if a JAVAC has to be set (JAVA_BUILD==jdk)
.		if defined(JAVA_BUILD)
.			if (${JAVA_BUILD:tu} == "JDK") && !defined(JAVAC)
JAVAC?=			${JAVA_HOME}/bin/javac
.			endif
.		endif

# Define the location of some more executables.
APPLETVIEWER?=	${JAVA_HOME}/bin/appletviewer
JAR?=			${JAVA_HOME}/bin/jar
JAVA?=			${JAVA_HOME}/bin/java
JAVADOC?=		${JAVA_HOME}/bin/javadoc
JAVAH?=			${JAVA_HOME}/bin/javah
JAVAP?=			${JAVA_HOME}/bin/javap
JAVA_N2A?=		${JAVA_HOME}/bin/native2ascii
JAVA_SERIALVER?=${JAVA_HOME}/bin/serialver
RMIC?=			${JAVA_HOME}/bin/rmic
RMIREGISTRY?=	${JAVA_HOME}/bin/rmiregistry
JAVA_KEYTOOL?=		${JAVA_HOME}/bin/keytool
JAVA_POLICYTOOL?=	${JAVA_HOME}/bin/policytool
RMID?=				${JAVA_HOME}/bin/rmid

# Set the location of the ZIP or JAR file with all standard Java classes.
JAVA_CLASSES=	${JAVA_HOME}/jre/lib/rt.jar


#-------------------------------------------------------------------------------
# Additional Java support

# Debug target
# Use it to check Java dependency while porting
java-debug:
	@${ECHO_CMD} "# User specified parameters:"
	@${ECHO_CMD} "JAVA_VERSION=                   ${JAVA_VERSION}	(${_JAVA_VERSION})"
	@${ECHO_CMD} "JAVA_OS=                        ${JAVA_OS}	(${_JAVA_OS})"
	@${ECHO_CMD} "JAVA_VENDOR=                    ${JAVA_VENDOR}	(${_JAVA_VENDOR})"
	@${ECHO_CMD} "JAVA_BUILD=                     ${JAVA_BUILD}"
	@${ECHO_CMD} "JAVA_RUN=                       ${JAVA_RUN}"
	@${ECHO_CMD} "JAVA_EXTRACT=                   ${JAVA_EXTRACT}"
	@${ECHO_CMD}
	@${ECHO_CMD} "# JDK port dependency selection process:"
	@${ECHO_CMD} "_JAVA_PORTS_POSSIBLE=           ${_JAVA_PORTS_POSSIBLE}"
	@${ECHO_CMD} "_JAVA_PORTS_INSTALLED=          ${_JAVA_PORTS_INSTALLED}"
	@${ECHO_CMD} "_JAVA_PORTS_INSTALLED_POSSIBLE= ${_JAVA_PORTS_INSTALLED_POSSIBLE}"
	@${ECHO_CMD} "_JAVA_PORT=                     ${_JAVA_PORT}"
	@${ECHO_CMD} "_JAVA_PORT_INFO=                ${_JAVA_PORT_INFO:S/\t/ /}"
	@${ECHO_CMD}
	@${ECHO_CMD} "# Selected JDK port:"
	@${ECHO_CMD} "JAVA_PORT=                      ${JAVA_PORT}"
	@${ECHO_CMD} "JAVA_HOME=                      ${JAVA_HOME}"
	@${ECHO_CMD} "JAVA_PORT_VERSION=              ${JAVA_PORT_VERSION}"
	@${ECHO_CMD} "JAVA_PORT_OS=                   ${JAVA_PORT_OS}	(${JAVA_PORT_OS_DESCRIPTION})"
	@${ECHO_CMD} "JAVA_PORT_VENDOR=               ${JAVA_PORT_VENDOR}	(${JAVA_PORT_VENDOR_DESCRIPTION})"
	@${ECHO_CMD}
	@${ECHO_CMD} "# Additional variables:"
	@${ECHO_CMD} "JAVAC=                          ${JAVAC}"
	@${ECHO_CMD} "JAVA_CLASSES=                   ${JAVA_CLASSES}"

.	endif
.endif
