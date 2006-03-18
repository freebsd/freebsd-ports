#
# $FreeBSD$
#
# This file contains some variable definitions that are supposed to
# make your life easier when dealing with ports related to the GNUstep.
#
#
# Options for user to customize in /etc/make.conf:
# ================================================
#
# WITH_GNUSTEP_XLIB=yes
#	use xlib as backend (default)
#
# WITH_GNUSTEP_XDPS=yes
#	use xdps as backend while build instead of xlib.
#
# WITH_GNUSTEP_LIBART=yes
#	use libart as backend while build instead of xlib.
#
# WITH_GNUSTEP_CAIRO=yes
#	use cairo as backend while build instead of xlib.
#
# GNUSTEP_WITH_BASE_GCC=yes
#	use system compiler (does not work on all architectures).
#
# GNUSTEP_WITH_GCC32=yes
#	use gcc 3.2.x with objective C shared libraries.
#
# GNUSTEP_WITH_GCC33=yes
#	use gcc 3.3.x with objective C shared libraries.
#
# GNUSTEP_WITH_GCC34=yes
#	use gcc 3.4.x with objective C shared libraries (default).
#
# GNUSTEP_WITH_GCC40=yes
#	use gcc 4.0.x with objective C shared libraries.
#
# GNUSTEP_WITH_GCC41=yes
#	use gcc 4.1.x with objective C shared libraries.
#
# GNUSTEP_WITH_GCC42=yes
#	use gcc 4.2.x with objective C shared libraries.
#
#
# Options for a port before include this file:
# ============================================
#
# USE_GNUSTEP_BASE=yes
#	your port depends on the gnustep-base port.
#
# USE_GNUSTEP_GUI=yes
#	your port depends on the gnustep-gui port.
#
# USE_GNUSTEP_BACK=yes
#	your port depends on the gnustep-back port.
#
# USE_GNUSTEP_CONFIGURE=yes
#	call configure script with GNUstep.sh sourced in the current shell
#
# USE_GNUSTEP_BUILD=yes
#	call build target with GNUstep.sh sourced in the current shell
#
# USE_GNUSTEP_INSTALL=yes
#	call install target with GNUstep.sh sourced in the current shell
#

# ---------------------------------------------------------------------------
.if !defined(_POSTMKINCLUDED)

GNUstep_Include_MAINTAINER=	dinoex@FreeBSD.org

BUILD_DEPENDS+=	${LOCALBASE}/lib/libcallback.a:${PORTSDIR}/devel/ffcall
.if !defined(GNUSTEP_WITHOUT_LIBOBJC)
.if !defined(GNUSTEP_WITH_BASE_GCC)
BUILD_DEPENDS+=	${TARGLIB}/libobjc.so:${PORTSDIR}/${GNUSTEP_GCC_PORT}
RUN_DEPENDS+=	${TARGLIB}/libobjc.so:${PORTSDIR}/${GNUSTEP_GCC_PORT}
.else
BUILD_DEPENDS+=	${COMBOLIBDIR}/libobjc.so:${PORTSDIR}/${GNUSTEP_OBJC_PORT}
RUN_DEPENDS+=	${COMBOLIBDIR}/libobjc.so:${PORTSDIR}/${GNUSTEP_OBJC_PORT}
.endif
.endif

GNUSTEP_GCC_PORT?=	lang/gcc-objc
GNUSTEP_MAKE_PORT?=	devel/gnustep-make
GNUSTEP_OBJC_PORT?=	lang/gnustep-objc
GNUSTEP_BASE_PORT?=	lang/gnustep-base
GNUSTEP_GUI_PORT?=	x11-toolkits/gnustep-gui
GNUSTEP_BACK_PORT?=	x11-toolkits/gnustep-back
GNUSTEP_XDPS_PORT?=	x11-toolkits/gnustep-xdps
GNUSTEP_ART_PORT?=	x11-toolkits/gnustep-art
GNUSTEP_CAIRO_PORT?=	x11-toolkits/gnustep-cairo

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

GNUSTEP_PREFIX?=	${LOCALBASE}/GNUstep
.if defined(USE_GNUSTEP_PREFIX)
PREFIX=		${GNUSTEP_PREFIX}
NO_MTREE=	yes
.endif
SYSTEMDIR=	${GNUSTEP_PREFIX}/System
SYSMAKEDIR=	${SYSTEMDIR}/Library/Makefiles
BUNDLEDIR=	${SYSTEMDIR}/Library/Bundles
SYSLIBDIR=	${SYSTEMDIR}/Library/Libraries
COMBOLIBDIR=	${SYSTEMDIR}/Library/Libraries
LOCALLIBDIR=	${GNUSTEP_PREFIX}/Local/Library/Libraries
.if defined(WITH_GNUSTEP_DEVEL)
PKGNAMESUFFIX?=	-devel${PKGNAMESUFFIX2}
PLIST_SUB+=	GNUSTEP_DEVEL=""
PLIST_SUB+=	GNUSTEP_STABLE="@comment "
DEFAULT_LIBVERSION?=	0.0.1
.else
PLIST_SUB+=	GNUSTEP_DEVEL="@comment "
PLIST_SUB+=	GNUSTEP_STABLE=""
DEFAULT_LIBVERSION?=	0.0.1
.endif

PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} VERSION=${PORTVERSION}
PLIST_SUB+=	MAJORVERSION=${PORTVERSION:C/([0-9]).*/\1/1}
PLIST_SUB+=	LIBVERSION=${DEFAULT_LIBVERSION}
PLIST_SUB+=	MAJORLIBVERSION=${DEFAULT_LIBVERSION:C/([0-9]).*/\1/1}

.if !defined(GNUSTEP_WITH_BASE_GCC)
.if !defined(GNUSTEP_WITH_GCC32) && !defined(GNUSTEP_WITH_GCC33) && !defined(GNUSTEP_WITH_GCC34)
.if !defined(GNUSTEP_WITH_GCC40) && !defined(GNUSTEP_WITH_GCC41) && !defined(GNUSTEP_WITH_GCC42)
GNUSTEP_WITH_GCC34=	yes
.endif
.endif
.if defined(GNUSTEP_WITH_GCC32)
CC=		gcc32
CXX=		g++32
.endif
.if defined(GNUSTEP_WITH_GCC33)
CC=		gcc33
CXX=		g++33
.endif
.if defined(GNUSTEP_WITH_GCC34)
CC=		gcc34
CXX=		g++34
.endif
.if defined(GNUSTEP_WITH_GCC40)
CC=		gcc40
CXX=		g++40
.endif
.if defined(GNUSTEP_WITH_GCC41)
CC=		gcc41
CXX=		g++41
.endif
.if defined(GNUSTEP_WITH_GCC42)
CC=		gcc42
CXX=		g++42
.endif
.endif

# ---------------------------------------------------------------------------
# using base
#
.if defined(USE_GNUSTEP_BASE)
BUILD_DEPENDS+=	${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/${GNUSTEP_BASE_PORT}
RUN_DEPENDS+=	${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/${GNUSTEP_BASE_PORT}
.endif

# ---------------------------------------------------------------------------
# using gui
#
.if defined(USE_GNUSTEP_GUI)
BUILD_DEPENDS+=	${COMBOLIBDIR}/libgnustep-gui.so:${PORTSDIR}/${GNUSTEP_GUI_PORT}
RUN_DEPENDS+=	${COMBOLIBDIR}/libgnustep-gui.so:${PORTSDIR}/${GNUSTEP_GUI_PORT}
.endif

# ---------------------------------------------------------------------------
# using any backend
#
.if defined(USE_GNUSTEP_BACK)
BACKSUFFIX?=	-010
.if defined(WITH_GNUSTEP_XDPS)
GNUSTEP_WITH_XDPS=yes
.elif defined(WITH_GNUSTEP_LIBART)
USE_GNUSTEP_LIBART=yes
.elif defined(WITH_GNUSTEP_CAIRO)
USE_GNUSTEP_CAIRO=yes
.elif defined(WITH_GNUSTEP_XLIB)
USE_GNUSTEP_XLIB=yes
.else
# default:
USE_GNUSTEP_XLIB=yes
.endif
.endif

# ---------------------------------------------------------------------------
# Backend using xlib
#
.if defined(USE_GNUSTEP_XLIB)
BUILD_DEPENDS+=	${BUNDLEDIR}/${BACKXLIB}.bundle/${BACKXLIB}:${PORTSDIR}/${GNUSTEP_BACK_PORT}
RUN_DEPENDS+=	${BUNDLEDIR}/${BACKXLIB}.bundle/${BACKXLIB}:${PORTSDIR}/${GNUSTEP_BACK_PORT}

BACKXLIB=	libgnustep-back${BACKSUFFIX}
MAKE_FLAGS+=	GUI_BACKEND_LIB=back
.endif

# ---------------------------------------------------------------------------
# Backend using xdps
#
.if defined(USE_GNUSTEP_XDPS)
BUILD_DEPENDS+=	${BUNDLEDIR}/${BACKXDPS}.bundle/${BACKXDPS}:${PORTSDIR}/${GNUSTEP_XDPS_PORT}
RUN_DEPENDS+=	${BUNDLEDIR}/${BACKXDPS}.bundle/${BACKXDPS}:${PORTSDIR}/${GNUSTEP_XDPS_PORT}

BACKXDPS=	libgnustep-xdps${BACKSUFFIX}
MAKE_FLAGS+=	GUI_BACKEND_LIB=xdps
.endif

# ---------------------------------------------------------------------------
# Backend using libart
#
.if defined(USE_GNUSTEP_LIBART)
BUILD_DEPENDS+=	${BUNDLEDIR}/${BACKART}.bundle/${BACKART}:${PORTSDIR}/${GNUSTEP_ART_PORT}
RUN_DEPENDS+=	${BUNDLEDIR}/${BACKART}.bundle/${BACKART}:${PORTSDIR}/${GNUSTEP_ART_PORT}

BACKART=	libgnustep-art${BACKSUFFIX}
MAKE_FLAGS+=	GUI_BACKEND_LIB=art
.endif

# ---------------------------------------------------------------------------
# Backend using cairo
#
.if defined(USE_GNUSTEP_CAIRO)
BUILD_DEPENDS+=	${BUNDLEDIR}/${BACKCAIRO}.bundle/${BACKCAIRO}:${PORTSDIR}/${GNUSTEP_CAIRO_PORT}
RUN_DEPENDS+=	${BUNDLEDIR}/${BACKCAIRO}.bundle/${BACKCAIRO}:${PORTSDIR}/${GNUSTEP_CAIRO_PORT}

BACKCAIRO=	libgnustep-cairo${BACKSUFFIX}
MAKE_FLAGS+=	GUI_BACKEND_LIB=cairo
.endif

# ---------------------------------------------------------------------------
# source GNUstep.sh
#
.if defined(USE_GNUSTEP_CONFIGURE)
run-autotools::
	@${DO_NADA}

do-configure:
	@(cd ${CONFIGURE_WRKSRC}; . ${SYSMAKEDIR}/GNUstep.sh; \
	    if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
		INSTALL_DATA="${INSTALL} -c" \
		INSTALL_PROGRAM="${INSTALL} -c" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; then \
		    ${ECHO} "===>  Script \"${CONFIGURE_SCRIPT}\" failed: here are the contents of \"${CONFIGURE_LOG}\""; \
		    ${CAT} ${CONFIGURE_LOG}; \
		    ${ECHO} "(end of \"${CONFIGURE_LOG}\")"; \
		    ${FALSE}; \
	    fi)
.endif

# ---------------------------------------------------------------------------
# source GNUstep.sh
#
.if defined(USE_GNUSTEP_BUILD)
BUILD_DEPENDS+=	${SYSMAKEDIR}/GNUstep.sh:${PORTSDIR}/${GNUSTEP_MAKE_PORT}

do-build:
	@(cd ${WRKSRC}; . ${SYSMAKEDIR}/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

.endif

# ---------------------------------------------------------------------------
# source GNUstep.sh
#
.if defined(USE_GNUSTEP_INSTALL)
RUN_DEPENDS+=	${SYSMAKEDIR}/GNUstep.sh:${PORTSDIR}/${GNUSTEP_MAKE_PORT}

do-install:
	@(cd ${WRKSRC}; . ${SYSMAKEDIR}/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
.if defined(PARALLEL_PACKAGE_BUILD) || defined(BATCH) || defined(CLEAN_ROOT)
	rm -rf /root/GNUstep
.endif

.endif

.if !defined(GNUSTEP_WITH_BASE_GCC)
TARGLIB!=	(cd ${PORTSDIR}/${GNUSTEP_GCC_PORT} && make -V TARGLIB)
.endif

.endif

# eof
