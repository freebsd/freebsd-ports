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
Java_Include_MAINTAINER=	glewis@FreeBSD.org hq@FreeBSD.org

#-------------------------------------------------------------------------------
# Variables that each port can define:
#
# USE_JAVA			Should be defined to the remaining variables to have any
#					effect
#
# JAVA_VERSION		List of space-separated suitable java versions for the
#					port. An optional "+" allows you to specify a range of
#					versions. (allowed values: 1.1[+] 1.2[+] 1.3[+] 1.4[+])
#
# JAVA_OS			List of space-separated suitable JDK port operating systems
#					for the port. (allowed values: native linux)
#
# JAVA_VENDOR		List of space-separated suitable JDK port vendors for the
#					port. (allowed values: freebsd bsdjava sun ibm blackdown)
#
# JAVA_BUILD		When set, it means that the selected JDK port should be
#					added to build dependencies for the port.
#
# JAVA_RUN			This variable works exactly the same as JAVA_BUILD but
#					regarding run dependencies.
#
# USE_JIKES			Whether the port should or should not use jikes(1) to build.
#					See Stage 6 header for further detail.
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
# JAVA_PORT			The name of the JDK port. (e.g. 'java/jdk14')
#
# JAVA_PORT_VERSION	The version of the JDK port. (e.g. '1.4')
#
# JAVA_PORT_OS		The operating system used by the JDK port. (e.g. 'linux')
#
# JAVA_PORT_VENDOR	The vendor of the JDK port. (e.g. 'sun')
#
# JAVA_PORT_OS_DESCRIPTION		Description of the operating system used by the
#								JDK port. (e.g. 'Linux')
#
# JAVA_PORT_VENDOR_DESCRIPTION	Description of the vendor of the JDK port.
#								(e.g. 'FreeBSD Foundation')
#
# JAVA_HOME			Path to the installation directory of the JDK. (e.g.
#					'/usr/local/jdk1.3.1')
#
# JAVAC				Path to the Java compiler to use. (e.g.
#					'/usr/local/jdk1.1.8/bin/javac' or '/usr/local/bin/jikes')
#
# JAR				Path to the JAR tool to use. (e.g.
#					'/usr/local/jdk1.2.2/bin/jar' or '/usr/local/bin/fastjar')
#
# APPLETVIEWER		Path to the appletviewer utility. (e.g.
#					'/usr/local/linux-jdk1.2.2/bin/appletviewer')
#
# JAVA				Path to the java executable. Use this for executing Java
#					programs. (e.g. '/usr/local/jdk1.3.1/bin/java')
#
# JAVADOC			Path to the javadoc utility program.
#
# JAVAH				Path to the javah program.
#
# JAVAP				Path to the javap program.
#
# JAVA_KEYTOOL		Path to the keytool utility program. This settings is
#					availble only if the JDK is Java 1.2 or higher.
#
# JAVA_N2A			Path to the native2ascii tool.
#
# JAVA_POLICYTOOL	Path to the policytool program. This variable is available
#					only if the JDK is Java 1.2 or higher.
#
# JAVA_SERIALVER	Path to the serialver utility program.
#
# RMIC				Path to the RMI stub/skeleton generator, rmic.
#
# RMIREGISTRY		Path to the RMI registry program, rmiregistry.
#
# RMID				Path to the RMI daemon program. This settings is only
#					available if the JDK is Java 1.2 or higher.
#
# JAVA_CLASSES		Path to the archive that contains the JDK class files. On
#					JDK 1.2 or later, this is ${JAVA_HOME}/jre/lib/rt.jar.
#					Earlier JDK's use ${JAVA_HOME}/lib/classes.zip.
#
# JAVASHAREDIR      The base directory for all shared Java resources.
#
# JAVAJARDIR        The directory where a port should install JAR files.
#
# JAVALIBDIR        The directory where JAR files installed by other ports
#                   are located.
#
# HAVE_JIKES		Defined and set to "yes" whenever the port will effectively
#					use Jikes. See stage 6 header for further detail.
#
#-------------------------------------------------------------------------------
# Porter's hints
#
# To retrieve the Major version number from JAVA_PORT_VERSION (e.g. "1.3"):
#		-> ${JAVA_PORT_VERSION:C/^([0-9])\.([0-9])(.*)$/\1.\2/}
#
#-------------------------------------------------------------------------------
# There are the following stages:
#
# Stage 1: Define constants
# Stage 2: bsd.java.mk 1.0 backward compatibility
# Stage 3: Determine which JDK ports are installed and which JDK ports are
#          suitable
# Stage 4: <REMOVED> (merged in stage 3)
# Stage 5: Decide the exact JDK to use (or install)
# Stage 6: Add any dependencies if necessary
# Stage 7: Define all settings for the port to use
#

.	if defined(USE_JAVA)


#-------------------------------------------------------------------------------
# Stage 1: Define constants
#

# System-global directories
# NB: If the value of JAVALIBDIR is altered here it must also be altered
#     in java/javavmwrapper/Makefile.
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
__JAVA_VERSION_LIST=	1.1 1.2 1.3 1.4 1.5
_JAVA_VERSION_LIST=		${__JAVA_VERSION_LIST} ${__JAVA_VERSION_LIST:S/$/+/}
_JAVA_OS_LIST=			native linux
_JAVA_VENDOR_LIST=		freebsd bsdjava sun blackdown ibm

# Set all meta-information about JDK ports:
# port location, corresponding JAVA_HOME, JDK version, OS, vendor
_JAVA_PORT_NATIVE_FREEBSD_JDK_1_3_INFO=		PORT=java/diablo-jdk13			HOME=${LOCALBASE}/diablo-jdk1.3.1 \
											VERSION=1.3.1	OS=native	VENDOR=freebsd
_JAVA_PORT_NATIVE_BSDJAVA_JDK_1_1_INFO=		PORT=java/jdk11					HOME=${LOCALBASE}/jdk1.1.8 \
											VERSION=1.1.8	OS=native	VENDOR=bsdjava
_JAVA_PORT_NATIVE_BSDJAVA_JDK_1_2_INFO=		PORT=java/jdk12					HOME=${LOCALBASE}/jdk1.2.2 \
											VERSION=1.2.2	OS=native	VENDOR=bsdjava
_JAVA_PORT_NATIVE_BSDJAVA_JDK_1_3_INFO=		PORT=java/jdk13					HOME=${LOCALBASE}/jdk1.3.1 \
											VERSION=1.3.1	OS=native	VENDOR=bsdjava
_JAVA_PORT_NATIVE_BSDJAVA_JDK_1_4_INFO=		PORT=java/jdk14					HOME=${LOCALBASE}/jdk1.4.2 \
											VERSION=1.4.2	OS=native	VENDOR=bsdjava
_JAVA_PORT_NATIVE_BSDJAVA_JDK_1_5_INFO=		PORT=java/jdk15					HOME=${LOCALBASE}/jdk1.5.0 \
											VERSION=1.5.0	OS=native	VENDOR=bsdjava
_JAVA_PORT_LINUX_BLACKDOWN_JDK_1_2_INFO=	PORT=java/linux-blackdown-jdk12	HOME=${LOCALBASE}/linux-blackdown-jdk1.2.2 \
											VERSION=1.2.2	OS=linux	VENDOR=blackdown
_JAVA_PORT_LINUX_BLACKDOWN_JDK_1_3_INFO=	PORT=java/linux-blackdown-jdk13	HOME=${LOCALBASE}/linux-blackdown-jdk1.3.1 \
											VERSION=1.3.1	OS=linux	VENDOR=blackdown
_JAVA_PORT_LINUX_BLACKDOWN_JDK_1_4_INFO=	PORT=java/linux-blackdown-jdk14	HOME=${LOCALBASE}/linux-blackdown-jdk1.4.2 \
											VERSION=1.4.2	OS=linux	VENDOR=blackdown
_JAVA_PORT_LINUX_IBM_JDK_1_3_INFO=			PORT=java/linux-ibm-jdk13		HOME=${LOCALBASE}/linux-ibm-jdk1.3.1 \
											VERSION=1.3.1	OS=linux	VENDOR=ibm
_JAVA_PORT_LINUX_IBM_JDK_1_4_INFO=			PORT=java/linux-ibm-jdk14		HOME=${LOCALBASE}/linux-ibm-jdk1.4.2 \
											VERSION=1.4.1	OS=linux	VENDOR=ibm
_JAVA_PORT_LINUX_SUN_JDK_1_2_INFO=			PORT=java/linux-sun-jdk12		HOME=${LOCALBASE}/linux-sun-jdk1.2.2 \
											VERSION=1.2.2	OS=linux	VENDOR=sun
_JAVA_PORT_LINUX_SUN_JDK_1_3_INFO=			PORT=java/linux-sun-jdk13		HOME=${LOCALBASE}/linux-sun-jdk1.3.1 \
											VERSION=1.3.1	OS=linux	VENDOR=sun
_JAVA_PORT_LINUX_SUN_JDK_1_4_INFO=			PORT=java/linux-sun-jdk14		HOME=${LOCALBASE}/linux-sun-jdk1.4.2 \
											VERSION=1.4.2	OS=linux	VENDOR=sun

# Verbose description for each VENDOR
_JAVA_VENDOR_freebsd=		"FreeBSD Foundation"
_JAVA_VENDOR_bsdjava=		"BSD Java Porting Team"
_JAVA_VENDOR_blackdown=		Blackdown
_JAVA_VENDOR_ibm=			IBM
_JAVA_VENDOR_sun=			Sun

# Verbose description for each OS
_JAVA_OS_native=	Native
_JAVA_OS_linux=		Linux

# Enforce preferred Java ports according to OS
.		if ${OSVERSION} >= 400000
_JAVA_PREFERRED_PORTS+=	JAVA_PORT_NATIVE_BSDJAVA_JDK_1_4
.		else
_JAVA_PREFERRED_PORTS+=	JAVA_PORT_NATIVE_BSDJAVA_JDK_1_1
.		endif


# List all JDK ports
__JAVA_PORTS_ALL=	JAVA_PORT_NATIVE_BSDJAVA_JDK_1_5 \
					JAVA_PORT_NATIVE_BSDJAVA_JDK_1_4 \
					JAVA_PORT_NATIVE_BSDJAVA_JDK_1_3 \
					JAVA_PORT_NATIVE_FREEBSD_JDK_1_3 \
					JAVA_PORT_NATIVE_BSDJAVA_JDK_1_2 \
					JAVA_PORT_NATIVE_BSDJAVA_JDK_1_1 \
					JAVA_PORT_LINUX_SUN_JDK_1_4	\
					JAVA_PORT_LINUX_SUN_JDK_1_3 \
					JAVA_PORT_LINUX_SUN_JDK_1_2 \
					JAVA_PORT_LINUX_BLACKDOWN_JDK_1_4 \
					JAVA_PORT_LINUX_BLACKDOWN_JDK_1_3 \
					JAVA_PORT_LINUX_BLACKDOWN_JDK_1_2 \
					JAVA_PORT_LINUX_IBM_JDK_1_4 \
					JAVA_PORT_LINUX_IBM_JDK_1_3
_JAVA_PORTS_ALL=	${JAVA_PREFERRED_PORTS} \
					${_JAVA_PREFERRED_PORTS} \
					${__JAVA_PORTS_ALL}

# Set the name of the file that indicates that a JDK is indeed installed, as a
# relative path within the JAVA_HOME directory.
_JDK_FILE=bin/javac

# Set the path to Jikes and define the Jikes dependency
_JIKES_PATH=	${LOCALBASE}/bin/jikes
DEPEND_JIKES=	${_JIKES_PATH}:${PORTSDIR}/java/jikes


#-------------------------------------------------------------------------------
# Stage 2: bsd.java.mk 1.0 backward compatibility
#

# First detect if we are using bsd.java.mk v1.0
_USE_BSD_JAVA_MK_1_0!=	${ECHO_CMD} "${_JAVA_VERSION_LIST}" \
						| ${TR} " " "\n" \
						| ${GREP} -q "^${USE_JAVA}$$" && ${ECHO_CMD} "yes" || ${ECHO_CMD} "no"
.		if (${_USE_BSD_JAVA_MK_1_0} == "yes")
# Then affect the variables so that we may use v2.0
# USE_JAVA --> JAVA_VERSION
.			if !defined(JAVA_VERSION)
JAVA_VERSION=	${USE_JAVA}
.			else
check-makevars::
	@${ECHO_CMD} "${PKGNAME}: Makefile error: The port is using bsd.java.mk 1.0 but sets a value for JAVA_VERSION. This may cause problems."
	@${FALSE}
.			endif
# NO_{BUILD|RUN}_DEPENDS_JAVA --> JAVA_{BUILD|RUN}
.			if defined(NO_BUILD_DEPENDS_JAVA) && defined(NO_RUN_DEPENDS_JAVA)
check-makevars::
	@${ECHO_CMD} "${PKGNAME}: Makefile error: NO_BUILD_DEPENDS_JAVA and NO_RUN_DEPENDS_JAVA cannot be set at the same time.";
	@${FALSE}
.			else
.				if !defined(NO_BUILD_DEPENDS_JAVA) && !defined(NO_BUILD)
JAVA_BUILD=		jdk
.				endif
.				if !defined(NO_RUN_DEPENDS_JAVA)
JAVA_RUN=		jdk
.				endif
.			endif
# NEED_JAVAC --> JAVA_{BUILD|RUN}={jdk|jre}
.			if defined(NEED_JAVAC)
.				if (${NEED_JAVAC:U} == "YES")
JAVA_BUILD=		jdk
.				elif (${NEED_JAVAC:U} == "NO")
JAVA_BUILD=		jre
.				else
check-makevars::
	@${ECHO_CMD} "${PKGNAME}: Makefile error: \"${NEED_JAVAC}\" is not a valid value for NEED_JAVAC. It should be YES or NO, or it should be undefined.";
	@${FALSE}
.				endif
.			endif
.		endif


#-------------------------------------------------------------------------------
# Stage 3: Determine which JDK ports are suitable and which JDK ports are
# suitable
#

# From here, the port is using bsd.java.mk v2.0

# Error checking: defined JAVA_{HOME,PORT,PORT_VERSION,PORT_VENDOR,PORT_OS}
.		for variable in JAVA_HOME JAVA_PORT JAVA_PORT_VERSION JAVA_PORT_VENDOR JAVA_PORT_OS
.			if defined(${variable})
check-makevars::
	@${ECHO_CMD} "${PKGNAME}: Environment error: \"${variable}\" should not be defined."
	@${FALSE}
.			endif
.		endfor

# Error checking: JAVA_VERSION
_JAVA_VERSION_LIST_REGEXP!=		${ECHO_CMD} "${_JAVA_VERSION_LIST}" | ${SED} "s/ /\\\|/g"
_ERROR_CHECKING_JAVA_VERSION!=	${ECHO_CMD} "${JAVA_VERSION}" | ${TR} " " "\n" \
								| ${GREP} -v "${_JAVA_VERSION_LIST_REGEXP}" || true
.		if (${_ERROR_CHECKING_JAVA_VERSION} != "")
check-makevars::
	@${ECHO_CMD} "${PKGNAME}: Makefile error: \"${JAVA_VERSION}\" is not a valid value for JAVA_VERSION. It should be one or more of: ${__JAVA_VERSION_LIST} (with an optional \"+\" suffix.)";
	@${FALSE}
.		endif

# Error checking: JAVA_VENDOR
_JAVA_VENDOR_LIST_REGEXP!=		${ECHO_CMD} "${_JAVA_VENDOR_LIST}" | ${SED} "s/ /\\\|/g"
_ERROR_CHECKING_JAVA_VENDOR!=	${ECHO_CMD} "${JAVA_VENDOR}" | ${TR} " " "\n" \
								| ${GREP} -v "${_JAVA_VENDOR_LIST_REGEXP}" || true
.		if (${_ERROR_CHECKING_JAVA_VENDOR} != "")
check-makevars::
	@${ECHO_CMD} "${PKGNAME}: Makefile error: \"${JAVA_VENDOR}\" is not a valid value for JAVA_VENDOR. It should be one or more of: ${_JAVA_VENDOR_LIST}";
	@${FALSE}
.		endif

# Error checking: JAVA_OS
_JAVA_OS_LIST_REGEXP!=		${ECHO_CMD} "${_JAVA_OS_LIST}" | ${SED} "s/ /\\\|/g"
_ERROR_CHECKING_JAVA_OS!=	${ECHO_CMD} "${JAVA_OS}" | ${TR} " " "\n" \
							| ${GREP} -v "${_JAVA_OS_LIST_REGEXP}" || true
.		if (${_ERROR_CHECKING_JAVA_OS} != "")
check-makevars::
	@${ECHO_CMD} "${PKGNAME}: Makefile error: \"${JAVA_OS}\" is not a valid value for JAVA_OS. It should be one or more of: ${_JAVA_OS_LIST}";
	@${FALSE}
.		endif

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
_JAVA_VERSION=	${JAVA_VERSION:S/1.1+/1.1 1.2 1.3 1.4 1.5/:S/1.2+/1.2 1.3 1.4 1.5/:S/1.3+/1.3 1.4 1.5/:S/1.4+/1.4 1.5/:S/1.5+/1.5/}
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
A_JAVA_PORT_VERSION=		${A_JAVA_PORT_INFO:MVERSION=*:C/VERSION=([0-9])\.([0-9])(.*)/\1.\2/}
A_JAVA_PORT_OS=				${A_JAVA_PORT_INFO:MOS=*:S,OS=,,}
A_JAVA_PORT_VENDOR=			${A_JAVA_PORT_INFO:MVENDOR=*:S,VENDOR=,,}
A_JAVA_PORT_INSTALLED!=		${TEST} -x "${A_JAVA_PORT_HOME}/${_JDK_FILE}" \
							&& ${ECHO_CMD} "${A_JAVA_PORT}" \
							|| ${TRUE}
__JAVA_PORTS_INSTALLED!=	${ECHO_CMD} "${__JAVA_PORTS_INSTALLED} ${A_JAVA_PORT_INSTALLED}"
A_JAVA_PORT_POSSIBLE!=		${ECHO_CMD} "${_JAVA_VERSION}" | ${GREP} -q "${A_JAVA_PORT_VERSION}" \
							&& ${ECHO_CMD} "${_JAVA_OS}" | ${GREP} -q "${A_JAVA_PORT_OS}" \
							&& ${ECHO_CMD} "${_JAVA_VENDOR}" | ${GREP} -q "${A_JAVA_PORT_VENDOR}" \
							&& ${ECHO_CMD} "${A_JAVA_PORT}" \
							|| ${TRUE}
__JAVA_PORTS_POSSIBLE!=		${ECHO_CMD} "${__JAVA_PORTS_POSSIBLE} ${A_JAVA_PORT_POSSIBLE}"
.		endfor
_JAVA_PORTS_INSTALLED=		${__JAVA_PORTS_INSTALLED:C/ [ ]+/ /g}
_JAVA_PORTS_POSSIBLE=		${__JAVA_PORTS_POSSIBLE:C/ [ ]+/ /g}


#-------------------------------------------------------------------------------
# Stage 5: Decide the exact JDK to use (or install)
#

# Find an installed JDK port that matches the requirements of the port

.		undef _JAVA_PORTS_INSTALLED_POSSIBLE

.		for A_JAVA_PORT in ${_JAVA_PORTS_POSSIBLE}
A_JAVA_PORT_INSTALLED_POSSIBLE!=	${ECHO_CMD} "${_JAVA_PORTS_INSTALLED}" | ${GREP} -q "${A_JAVA_PORT}" \
									&& ${ECHO_CMD} "${A_JAVA_PORT}" || ${TRUE}
__JAVA_PORTS_INSTALLED_POSSIBLE!=	${ECHO_CMD} "${__JAVA_PORTS_INSTALLED_POSSIBLE} ${A_JAVA_PORT_INSTALLED_POSSIBLE}"
.		endfor
_JAVA_PORTS_INSTALLED_POSSIBLE=		${__JAVA_PORTS_INSTALLED_POSSIBLE:C/ [ ]+/ /g}

.		if ${_JAVA_PORTS_INSTALLED_POSSIBLE} != ""
_JAVA_PORT!=	${ECHO_CMD} "${_JAVA_PORTS_INSTALLED_POSSIBLE}" \
				| ${AWK} '{ print $$1 }'

# If no installed JDK port fits, then pick one from the list of possible ones
.		else
_JAVA_PORT!=	${ECHO_CMD} "${_JAVA_PORTS_POSSIBLE}" \
				| ${AWK} '{ print $$1 }'
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
# Stage 6: Add any dependencies if necessary
#

# Jikes support: If USE_JIKES is set to YES, then use Jikes. If USE_JIKES is
# set to NO, then don't use it. If it is set to a different value, then fail
# with an error message. Otherwise USE_JIKES is not set, in which case it is
# checked if Jikes is already installed. If it is, then it will be used,
# otherwise it will not be used.
#
# As a result, HAVE_JIKES is defined and set to "yes" when Jikes is used by the
# port according to the above policy.

.		undef HAVE_JIKES

# First test if USE_JIKES has a valid value
.		if defined(USE_JIKES) && !(${USE_JIKES:U} == "YES") && !(${USE_JIKES:U} == "NO")
check-makevars::
	@${ECHO_CMD} "${PKGNAME}: Makefile error: \"${USE_JIKES}\" is not a valid value for USE_JIKES. It should be YES or NO, or it should be undefined.";
	@${FALSE}
.		endif
# Then test if jikes is needed or available: -> HAVE_JIKES=yes
.		if (exists(${_JIKES_PATH}) && (!defined(USE_JIKES) || (${USE_JIKES:U} == "YES"))) \
			|| (defined(USE_JIKES) && (${USE_JIKES:U} == "YES"))
HAVE_JIKES=		yes
.		endif

# Add jikes port to the dependencies if needed
.		if !defined(NO_BUILD) && defined(HAVE_JIKES)
BUILD_DEPENDS+=	${DEPEND_JIKES}
.		endif

# Ant Support: USE_ANT --> JAVA_BUILD=jdk
.		if defined(USE_ANT)
JAVA_BUILD=		jdk
.		endif

# Add the JDK port to the dependencies
DEPEND_JAVA=	${JAVA}:${PORTSDIR}/${JAVA_PORT}
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
ANT?=				${LOCALBASE}/bin/ant
MAKE_ENV+=			JAVA_HOME=${JAVA_HOME}
.			if defined(HAVE_JIKES)
MAKE_ARGS+=			-Dbuild.compiler=jikes
.			endif
BUILD_DEPENDS+=		${ANT}:${PORTSDIR}/devel/apache-ant
ALL_TARGET?=
.			if !target(do-build)
do-build:
					@(cd ${BUILD_WRKSRC}; \
						${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} ${ALL_TARGET})
.			endif
.		endif

#-----------------------------------------------------------------------------
# Stage 7: Define all settings for the port to use
#
# At this stage both JAVA_HOME and JAVA_PORT are definitely given a value.
#
# Define the location of the Java compiler. If HAVE_JIKES is defined, then
# use Jikes.

# Only define JAVAC if a JDK is needed or USE_JIKES=yes
.		undef JAVAC

# Then test if a JAVAC has to be set (JAVA_BUILD==jdk)
.		if defined(JAVA_BUILD)
.			if (${JAVA_BUILD:U} == "JDK") && !defined(JAVAC)
# Use jikes if available and not explicitly forbidden (see Stage 6)
.				if defined(HAVE_JIKES)
JAVAC?=			${_JIKES_PATH} -bootclasspath ${JAVA_CLASSES}
# Otherwise use 'javac'
.				else
JAVAC?=			${JAVA_HOME}/bin/javac
.				endif
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

# Some executables only exists in JDK 1.2 and up
.		if ${_JAVA_PORT} != "JAVA_PORT_NATIVE_BSDJAVA_JDK_1_1"
JAVA_KEYTOOL?=		${JAVA_HOME}/bin/keytool
JAVA_POLICYTOOL?=	${JAVA_HOME}/bin/policytool
RMID?=				${JAVA_HOME}/bin/rmid
.		endif

# Set the location of the ZIP or JAR file with all standard Java classes.
.		if ${_JAVA_PORT} == "JAVA_PORT_NATIVE_BSDJAVA_JDK_1_1"
JAVA_CLASSES=	${JAVA_HOME}/lib/classes.zip
.		else
JAVA_CLASSES=	${JAVA_HOME}/jre/lib/rt.jar
.		endif


#-------------------------------------------------------------------------------
# Additional Java support

# Debug target
# Use it to check Java dependency while porting
java-debug:
	@${ECHO_CMD} "_USE_BSD_JAVA_MK_1_0=           ${_USE_BSD_JAVA_MK_1_0}"
	@${ECHO_CMD}
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
