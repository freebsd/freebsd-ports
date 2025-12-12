# Provide support for Java (java)
# Feature:	java
# Usage:	USES=java or USES=java:args
#
# Defaults to USES=java:build,run if no arguments are provided and NO_BUILD is
# undefined. If NO_BUILD is defined, USES=java:run is used.
#
# Valid ARGS:	ant build extract
#
# ant		-	Should be defined when the port uses Apache Ant. Ant is thus
#			considered to be the sub-make command. When no 'do-build'
#			target is defined by the port, a default one will be set
#			that simply runs Ant according to MAKE_ENV, MAKE_ARGS and
#			ALL_TARGET. Read the documentation in bsd.port.mk for more
#			information.
#
# build		-	Add the JDK port to the build dependencies
#
# extract	-	Add the JDK port to the extract dependencies
#
# run		-	Add the JDK port to the run dependencies
#
# For FreeBSD committers:
# Please send all suggested changes to the maintainer instead of committing
# them yourself.
#
#-------------------------------------------------------------------------------
# Variables that each port can define:
#
# JAVA_VERSION		List of space-separated suitable java versions for the
#			port. An optional "+" allows you to specify a range of
#			versions. (allowed values: 8[+] 11[+] 17[+] 18[+] 19[+]
#			20[+] 21[+] 22[+] 23[+] 24[+] 25[+])
#
# JAVA_OS		List of space-separated suitable JDK port operating systems
#			for the port. (allowed values: native linux)
#
# JAVA_VENDOR		List of space-separated suitable JDK port vendors for the
#			port. (allowed values: openjdk oracle)
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
# MAINTAINER:	java@FreeBSD.org

.if !defined(_INCLUDE_USES_JAVA_MK)

_INCLUDE_USES_JAVA_MK=	yes

_JAVA_VALID_ARGS=	ant build extract run
_JAVA_UNKNOWN_ARGS=
.  for arg in ${java_ARGS}
.    if empty(_JAVA_VALID_ARGS:M${arg})
_JAVA_UNKNOWN_ARGS+=	${arg}
.    endif
.  endfor
.  if !empty(_JAVA_UNKNOWN_ARGS)
IGNORE=	has unknown USES=java arguments: ${_JAVA_UNKNOWN_ARGS}
.  endif
.  if empty(java_ARGS)
.    if defined(NO_BUILD)
java_ARGS=	run
.    else
java_ARGS=	build,run
.    endif
.  endif

.  if !empty(java_ARGS)
.undef _USE_JAVA_ANT
.undef _USE_JAVA_BUILD
.undef _USE_JAVA_EXTRACT
.undef _USE_JAVA_RUN
_JAVA_ARGS=		${java_ARGS:S/,/ /g}
.    if ${_JAVA_ARGS:Mextract}
_USE_JAVA_EXTRACT=	yes
_JAVA_ARGS:=	${_JAVA_ARGS:Nextract}
.    endif
.    if ${_JAVA_ARGS:Mant}
.      if defined(NO_BUILD)
IGNORE=		Makefile error: NO_BUILD and USES=java:ant cannot be set at the same time
.      else
_USE_JAVA_ANT=	yes
_USE_JAVA_BUILD=	yes
_JAVA_ARGS:=	${_JAVA_ARGS:Nant}
.      endif
.    endif
.    if ${_JAVA_ARGS:Mbuild}
.      if defined(NO_BUILD)
IGNORE=		Makefile error: NO_BUILD and USES=java:build cannot be set at the same time
.      else
_USE_JAVA_BUILD=	yes
_JAVA_ARGS:=	${_JAVA_ARGS:Nbuild}
.      endif
.    endif
.    if ${_JAVA_ARGS:Mrun}
_USE_JAVA_RUN=	yes
_JAVA_ARGS:=	${_JAVA_ARGS:Nrun}
.    endif
.  endif # !empty(java_ARGS)

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
.  if defined(JAVA_VERSION)
SUB_LIST+=		JAVA_VERSION="${JAVA_VERSION}"
.  endif
.  if defined(JAVA_VENDOR)
SUB_LIST+=		JAVA_VENDOR="${JAVA_VENDOR}"
.  endif
.  if defined(JAVA_OS)
SUB_LIST+=		JAVA_OS="${JAVA_OS}"
.  endif

# The complete list of Java versions, os and vendors supported.
__JAVA_VERSION_LIST=	8 11 17 18 19 20 21 22 23 24 25
_JAVA_VERSION_LIST=		${__JAVA_VERSION_LIST} ${__JAVA_VERSION_LIST:S/$/+/}
_JAVA_OS_LIST=			native linux
_JAVA_VENDOR_LIST=		openjdk oracle

# Set all meta-information about JDK ports:
# port location, corresponding JAVA_HOME, JDK version, OS, vendor
_JAVA_PORT_NATIVE_OPENJDK_JDK_8_INFO=		PORT=java/openjdk8			HOME=${LOCALBASE}/openjdk8 \
											VERSION=8	OS=native	VENDOR=openjdk
_JAVA_PORT_NATIVE_OPENJDK_JDK_11_INFO=		PORT=java/openjdk11			HOME=${LOCALBASE}/openjdk11 \
											VERSION=11	OS=native	VENDOR=openjdk
_JAVA_PORT_NATIVE_OPENJDK_JDK_17_INFO=		PORT=java/openjdk17			HOME=${LOCALBASE}/openjdk17 \
											VERSION=17	OS=native	VENDOR=openjdk
_JAVA_PORT_NATIVE_OPENJDK_JDK_18_INFO=		PORT=java/openjdk18			HOME=${LOCALBASE}/openjdk18 \
											VERSION=18	OS=native	VENDOR=openjdk
_JAVA_PORT_NATIVE_OPENJDK_JDK_19_INFO=		PORT=java/openjdk19			HOME=${LOCALBASE}/openjdk19 \
											VERSION=19	OS=native	VENDOR=openjdk
_JAVA_PORT_NATIVE_OPENJDK_JDK_20_INFO=		PORT=java/openjdk20			HOME=${LOCALBASE}/openjdk20 \
											VERSION=20	OS=native	VENDOR=openjdk
_JAVA_PORT_NATIVE_OPENJDK_JDK_21_INFO=		PORT=java/openjdk21			HOME=${LOCALBASE}/openjdk21 \
											VERSION=21	OS=native	VENDOR=openjdk
_JAVA_PORT_NATIVE_OPENJDK_JDK_22_INFO=		PORT=java/openjdk22			HOME=${LOCALBASE}/openjdk22 \
											VERSION=22	OS=native	VENDOR=openjdk
_JAVA_PORT_NATIVE_OPENJDK_JDK_23_INFO=		PORT=java/openjdk23			HOME=${LOCALBASE}/openjdk23 \
											VERSION=23	OS=native	VENDOR=openjdk
_JAVA_PORT_NATIVE_OPENJDK_JDK_24_INFO=		PORT=java/openjdk24			HOME=${LOCALBASE}/openjdk24 \
											VERSION=24	OS=native	VENDOR=openjdk
_JAVA_PORT_NATIVE_OPENJDK_JDK_25_INFO=		PORT=java/openjdk25			HOME=${LOCALBASE}/openjdk25 \
											VERSION=25	OS=native	VENDOR=openjdk
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
					JAVA_PORT_NATIVE_OPENJDK_JDK_17 \
					JAVA_PORT_NATIVE_OPENJDK_JDK_18 \
					JAVA_PORT_NATIVE_OPENJDK_JDK_19 \
					JAVA_PORT_NATIVE_OPENJDK_JDK_20 \
					JAVA_PORT_NATIVE_OPENJDK_JDK_21 \
					JAVA_PORT_NATIVE_OPENJDK_JDK_22 \
					JAVA_PORT_NATIVE_OPENJDK_JDK_23 \
					JAVA_PORT_NATIVE_OPENJDK_JDK_24 \
					JAVA_PORT_NATIVE_OPENJDK_JDK_25 \
					JAVA_PORT_LINUX_ORACLE_JDK_8
_JAVA_PORTS_ALL=	${JAVA_PREFERRED_PORTS} \
			JAVA_PORT_NATIVE_OPENJDK_JDK_${JAVA_DEFAULT} \
					${__JAVA_PORTS_ALL}

# Set the name of the file that indicates that a JDK is indeed installed, as a
# relative path within the JAVA_HOME directory.
_JDK_FILE=bin/javac

#-------------------------------------------------------------------------------
# Stage 2: Determine which JDK ports are suitable and which JDK ports are
# suitable
#


# Error checking: defined JAVA_{HOME,PORT,PORT_VERSION,PORT_VENDOR,PORT_OS}
.  for variable in JAVA_HOME JAVA_PORT JAVA_PORT_VERSION JAVA_PORT_VENDOR JAVA_PORT_OS
.    if defined(${variable})
check-makevars::
	@${ECHO_CMD} "${PKGNAME}: Environment error: \"${variable}\" should not be defined -- clearing."
.undef				${variable}
.    endif
.  endfor

# Error checking: JAVA_VERSION
.  if defined(JAVA_VERSION)
.    if !defined(_JAVA_VERSION_LIST_REGEXP)
_JAVA_VERSION_LIST_REGEXP=	${_JAVA_VERSION_LIST:C/\+/\\+/:ts|}
.    endif

check-makevars::
	@( test ! -z "${JAVA_VERSION}" && ( ${ECHO_CMD} "${JAVA_VERSION}" | ${TR} " " "\n" | ${GREP} -Eq "${_JAVA_VERSION_LIST_REGEXP}")) || \
	(${ECHO_CMD} "${PKGNAME}: Makefile error: \"${JAVA_VERSION}\" is not a valid value for JAVA_VERSION. It should be one or more of: ${__JAVA_VERSION_LIST} (with an optional \"+\" suffix.)"; ${FALSE})
.  endif

# Error checking: JAVA_VENDOR
.  if defined(JAVA_VENDOR)
.    if !defined(_JAVA_VENDOR_LIST_REGEXP)
_JAVA_VENDOR_LIST_REGEXP=	${_JAVA_VENDOR_LIST:ts|}
.    endif

check-makevars::
	@( test ! -z "${JAVA_VENDOR}" && ( ${ECHO_CMD} "${JAVA_VENDOR}" | ${TR} " " "\n" | ${GREP} -Eq "${_JAVA_VENDOR_LIST_REGEXP}" )) || \
	(${ECHO_CMD} "${PKGNAME}: Makefile error: \"${JAVA_VENDOR}\" is not a valid value for JAVA_VENDOR. It should be one or more of: ${_JAVA_VENDOR_LIST}"; \
	${FALSE})
.  endif

# Error checking: JAVA_OS
.  if defined(JAVA_OS)
.    if !defined(_JAVA_OS_LIST_REGEXP)
_JAVA_OS_LIST_REGEXP=	${_JAVA_OS_LIST:ts|}
.    endif

check-makevars::
	@( test ! -z "${JAVA_OS}" && ( ${ECHO_CMD} "${JAVA_OS}" | ${TR} " " "\n" | ${GREP} -Eq "${_JAVA_OS_LIST_REGEXP}")) || \
	(${ECHO_CMD} "${PKGNAME}: Makefile error: \"${JAVA_OS}\" is not a valid value for JAVA_OS. It should be one or more of: ${_JAVA_OS_LIST}"; \
	${FALSE})
.  endif

# JDK dependency setting
.		undef _JAVA_PORTS_INSTALLED
.		undef _JAVA_PORTS_POSSIBLE
.  if defined(JAVA_VERSION)
_JAVA_VERSION=	${JAVA_VERSION:S/^8+/8 11+/:S/^11+/11 17+/:S/^17+/17 18+/:S/^18+/18 19+/:S/^19+/19 20+/:S/^20+/20 21+/:S/^21+/21 22+/:S/^22+/22 23+/:S/^23+/23 24+/:S/^24+/24 25+/:S/^25+/25/}
.  else
_JAVA_VERSION=	${__JAVA_VERSION_LIST}
.  endif
.  if defined(JAVA_OS)
_JAVA_OS=	${JAVA_OS}
.  else
_JAVA_OS=	${_JAVA_OS_LIST}
.  endif
.  if defined(JAVA_VENDOR)
_JAVA_VENDOR=	${JAVA_VENDOR}
.  else
_JAVA_VENDOR=	${_JAVA_VENDOR_LIST}
.  endif

.  for A_JAVA_PORT in ${_JAVA_PORTS_ALL}
A_JAVA_PORT_INFO:=			${A_JAVA_PORT:S/^/\${_/:S/$/_INFO}/}
A_JAVA_PORT_HOME=			${A_JAVA_PORT_INFO:MHOME=*:S,HOME=,,}
A_JAVA_PORT_VERSION=		${A_JAVA_PORT_INFO:MVERSION=*:S,VERSION=,,}
A_JAVA_PORT_OS=				${A_JAVA_PORT_INFO:MOS=*:S,OS=,,}
A_JAVA_PORT_VENDOR=			${A_JAVA_PORT_INFO:MVENDOR=*:S,VENDOR=,,}
.    if !defined(_JAVA_PORTS_INSTALLED) && exists(${A_JAVA_PORT_HOME}/${_JDK_FILE})
__JAVA_PORTS_INSTALLED+=	${A_JAVA_PORT}
.    endif

# Because variables inside for loops are special (directly replaced as strings),
# we are allowed to use them inside modifiers, where normally ${FOO:M${BAR}} is
# not allowed.
#
.    for ver in ${A_JAVA_PORT_VERSION}
.      for os in ${A_JAVA_PORT_OS}
.        for vendor in ${A_JAVA_PORT_VENDOR}
.          if ${_JAVA_VERSION:M${ver}} && ${_JAVA_OS:M${os}} && ${_JAVA_VENDOR:M${vendor}}
__JAVA_PORTS_POSSIBLE+=		${A_JAVA_PORT}
.          endif
.        endfor
.      endfor
.    endfor

.  endfor
.  if !defined(_JAVA_PORTS_INSTALLED)
_JAVA_PORTS_INSTALLED=		${__JAVA_PORTS_INSTALLED:C/ [ ]+/ /g}
.  endif
_JAVA_PORTS_POSSIBLE=		${__JAVA_PORTS_POSSIBLE:C/ [ ]+/ /g}


#-------------------------------------------------------------------------------
# Stage 3: Decide the exact JDK to use (or install)
#

# Find an installed JDK port that matches the requirements of the port

.		undef _JAVA_PORTS_INSTALLED_POSSIBLE

.  for A_JAVA_PORT in ${_JAVA_PORTS_POSSIBLE}
__JAVA_PORTS_INSTALLED_POSSIBLE+=	${_JAVA_PORTS_INSTALLED:M${A_JAVA_PORT}}
.  endfor
_JAVA_PORTS_INSTALLED_POSSIBLE=		${__JAVA_PORTS_INSTALLED_POSSIBLE:C/[ ]+//g}

.  if ${_JAVA_PORTS_INSTALLED_POSSIBLE} != ""
.    for i in ${_JAVA_PORTS_INSTALLED_POSSIBLE}
.      if !defined(_JAVA_PORTS_INSTALLED_POSSIBLE_shortcircuit)
_JAVA_PORT=	$i
_JAVA_PORTS_INSTALLED_POSSIBLE_shortcircuit=	1
.      endif
.    endfor
# If no installed JDK port fits, then pick one from the list of possible ones
.  else
.    for i in ${_JAVA_PORTS_POSSIBLE}
.      if !defined(_JAVA_PORTS_POSSIBLE_shortcircuit)
_JAVA_PORT=	$i
_JAVA_PORTS_POSSIBLE_shortcircuit=	1
.      endif
.    endfor
.  endif

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

# Add the JDK port to the dependencies
DEPEND_JAVA=	${JAVA}:${JAVA_PORT}
.  if defined(_USE_JAVA_EXTRACT)
EXTRACT_DEPENDS+=	${DEPEND_JAVA}
.  endif
.  if defined(_USE_JAVA_BUILD)
BUILD_DEPENDS+=		${DEPEND_JAVA}
.  endif
.  if defined(_USE_JAVA_RUN)
RUN_DEPENDS+=		${DEPEND_JAVA}
.  endif

# Ant support: default do-build target
.  if defined(_USE_JAVA_ANT)
DESTDIRNAME=		-Dfreebsd.ports.destdir
ANT?=				${LOCALBASE}/bin/ant
MAKE_ENV+=			JAVA_HOME=${JAVA_HOME}
BUILD_DEPENDS+=		${ANT}:devel/apache-ant
ALL_TARGET?=
.    if !target(do-build)
do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		${ANT} ${MAKE_ARGS} ${ALL_TARGET})
.    endif
.    if !target(do-test) && defined(TEST_TARGET)
TEST_DEPENDS+=		${DEPEND_JAVA}
TEST_DEPENDS+=		${ANT}:devel/apache-ant
do-test:
	@(cd ${TEST_WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		${ANT} ${MAKE_ARGS} ${TEST_TARGET})
.    endif
.  endif

#-----------------------------------------------------------------------------
# Stage 5: Define all settings for the port to use
#
# At this stage both JAVA_HOME and JAVA_PORT are definitely given a value.
#
# Define the location of the Java compiler.

# Only define JAVAC if a JDK is needed
#.		undef JAVAC

# Then test if a JAVAC has to be set (JAVA_BUILD==jdk)
.  if defined(_USE_JAVA_BUILD) && !defined(JAVAC)
JAVAC?=			${JAVA_HOME}/bin/javac
.  endif

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
	@${ECHO_CMD} "JAVA_BUILD=                     ${_USE_JAVA_BUILD}"
	@${ECHO_CMD} "JAVA_RUN=                       ${_USE_JAVA_RUN}"
	@${ECHO_CMD} "JAVA_EXTRACT=                   ${_USE_JAVA_EXTRACT}"
	@${ECHO_CMD} "JAVA_DEFAULT=                   ${JAVA_DEFAULT}"
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

.endif
