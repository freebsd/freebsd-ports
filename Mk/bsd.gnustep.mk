#
# $FreeBSD$
#
# This file contains some variable definitions that are supposed to
# make your life easier when dealing with ports related to the GNUstep.
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
# USE_GNUSTEP_MAKE_DIRS=	App Tools
#	call build and install target in each of the given dirs.
#
# USE_GNUSTEP_MAKE=yes
#	require GNUstep.sh for build and install
#
# USE_GNUSTEP_SYSTEM_LIBS+=	Renaissance:x11-toolkits/renaissance
#	depends on a shared lib in System directory
#
# USE_GNUSTEP_SYSTEM_BUNDLES+=	EtoileMenus:x11-themes/etoile-etoilemenus
#	depends on Bundles installed in System directory
#
# USE_GNUSTEP_SYSTEM_THEMES+=	Camaelon:x11-themes/etoile-camaelon
#	depends on Themes installed in System directory
#
# USE_GNUSTEP_LOCAL_LIBS+=	pantomime:mail/pantomime
#	depends on a shared lib in Local directory
#
# USE_GNUSTEP_LOCAL_BUNDLES+=	Cddb:audio/cddb-bundle
#	depends on Bundles installed in Local directory
#
# USE_GNUSTEP_LOCAL_THEMES+=	WildMenus:x11-themes/etoile-wildmenus
#	depends on Themes installed in Local directory
#
# USE_GNUSTEP_LOCAL_MENULETS+=	PowerMenulet:sysutils/etoile-powermenulet
#	depends on Menulets installed in Local directory
#
# USE_GNUSTEP_LOCAL_ASTS+=	CommentToLog:lang/etoile-lkplugins
#	depends on Ast Bundles installed in Local directory
#
# USE_GNUSTEP_LOCAL_BURNS+=	MP3ToWav:audio/mp3towav-bundle
#	depends on Burn Bundles installed in Local directory
#
# USE_GNUSTEP_SYSTEM_APPS+=	ProjectCenter:devel/projectcenter.app
#	depends on Application installed in System directory
#
# USE_GNUSTEP_LOCAL_APPS+=	Ink:misc/gnustep-examples
#	depends on Application installed in Local directory
#
# USE_GNUSTEP_SYSTEM_TOOLS+=	resizer:deskutils/gworkspace
#	depends on Tool installed in System directory
#
# USE_GNUSTEP_LOCAL_TOOLS+=	zillion:net/zillion
#	depends on Tool installed in Local directory
#
# USE_GNUSTEP_SYSTEM_SERVICES+=	thumbnailer:deskutils/gworkspace
#	depends on Services installed in System directory
#
# USE_GNUSTEP_LOCAL_SERVICES+=	LaTeX:textproc/latex-service
#	depends on Services installed in Local directory
#
# ---------------------------------------------------------------------------
.if !defined(_POSTMKINCLUDED)

GNUstep_Include_MAINTAINER=	ports@FreeBSD.org

.if defined(USE_GNUSTEP_BUILD) || defined(USE_GNUSTEP_MAKE)
BUILD_DEPENDS+=	${GNUSTEP_MAKEFILES}/GNUstep.sh:${PORTSDIR}/${GNUSTEP_MAKE_PORT}
.endif
.if defined(USE_GNUSTEP_INSTALL) || defined(USE_GNUSTEP_MAKE)
RUN_DEPENDS+=	${GNUSTEP_MAKEFILES}/GNUstep.sh:${PORTSDIR}/${GNUSTEP_MAKE_PORT}
.endif

GNUSTEP_MAKE_PORT?=	devel/gnustep-make
GNUSTEP_BASE_PORT?=	lang/gnustep-base
GNUSTEP_GUI_PORT?=	x11-toolkits/gnustep-gui
GNUSTEP_BACK_PORT?=	x11-toolkits/gnustep-back
# Note: back-cairo will be deprecated in favour of Opal soon...

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

.if !defined(USE_MAKEFILE)
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
.endif

.if defined(ADDITIONAL_FLAGS)
MAKE_ENV+=	ADDITIONAL_FLAGS="${ADDITIONAL_FLAGS}"
.endif
.if defined(ADDITIONAL_CFLAGS)
MAKE_ENV+=	ADDITIONAL_CFLAGS="${ADDITIONAL_CFLAGS}"
.endif
.if defined(ADDITIONAL_CPPFLAGS)
MAKE_ENV+=	ADDITIONAL_CPPFLAGS="${ADDITIONAL_CPPFLAGS}"
.endif
.if defined(ADDITIONAL_OBJCFLAGS)
MAKE_ENV+=	ADDITIONAL_OBJCFLAGS="${ADDITIONAL_OBJCFLAGS}"
.endif
.if defined(ADDITIONAL_INCLUDE_DIRS)
MAKE_ENV+=	ADDITIONAL_INCLUDE_DIRS="${ADDITIONAL_INCLUDE_DIRS}"
.endif
.if defined(ADDITIONAL_LDFLAGS)
MAKE_ENV+=	ADDITIONAL_LDFLAGS="${ADDITIONAL_LDFLAGS}"
.endif
.if defined(ADDITIONAL_LIB_DIRS)
MAKE_ENV+=	ADDITIONAL_LIB_DIRS="${ADDITIONAL_LIB_DIRS}"
.endif

GNUSTEP_PREFIX?=	${LOCALBASE}/GNUstep
DEFAULT_LIBVERSION?=	0.0.1

.if defined(USE_GNUSTEP_PREFIX)
PREFIX=		${GNUSTEP_PREFIX}
NO_MTREE=	yes
.endif

GNUSTEP_SYSTEM_ROOT=	${GNUSTEP_PREFIX}/System
GNUSTEP_MAKEFILES=		${GNUSTEP_SYSTEM_ROOT}/Library/Makefiles
GNUSTEP_SYSTEM_BUNDLES=		${GNUSTEP_SYSTEM_ROOT}/Library/Bundles
GNUSTEP_SYSTEM_LIBRARIES=	${GNUSTEP_SYSTEM_ROOT}/Library/Libraries
GNUSTEP_SYSTEM_APPS=		${GNUSTEP_SYSTEM_ROOT}/Applications
GNUSTEP_SYSTEM_TOOLS=		${GNUSTEP_SYSTEM_ROOT}/Tools
GNUSTEP_SYSTEM_SERVICES=	${GNUSTEP_SYSTEM_ROOT}/Library/Services

GNUSTEP_LOCAL_ROOT=	${GNUSTEP_PREFIX}/Local
GNUSTEP_LOCAL_BUNDLES=		${GNUSTEP_LOCAL_ROOT}/Library/Bundles
GNUSTEP_LOCAL_LIBRARIES=	${GNUSTEP_LOCAL_ROOT}/Library/Libraries
GNUSTEP_LOCAL_APPS=		${GNUSTEP_LOCAL_ROOT}/Applications
GNUSTEP_LOCAL_TOOLS=		${GNUSTEP_LOCAL_ROOT}/Tools
GNUSTEP_LOCAL_SERVICES=		${GNUSTEP_LOCAL_ROOT}/Library/Services

.if defined(WITH_GNUSTEP_DEVEL)
PKGNAMESUFFIX?=	-devel${PKGNAMESUFFIX2}
PLIST_SUB+=	GNUSTEP_DEVEL=""
PLIST_SUB+=	GNUSTEP_STABLE="@comment "
.else
PLIST_SUB+=	GNUSTEP_DEVEL="@comment "
PLIST_SUB+=	GNUSTEP_STABLE=""
.endif

PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} VERSION=${PORTVERSION}
PLIST_SUB+=	MAJORVERSION=${PORTVERSION:C/([0-9]).*/\1/1}
PLIST_SUB+=	LIBVERSION=${DEFAULT_LIBVERSION}
PLIST_SUB+=	MAJORLIBVERSION=${DEFAULT_LIBVERSION:C/([0-9]).*/\1/1}

.if !exists(${DESTDIR}/usr/bin/clang)
_CLANG!=	${DESTDIR}/usr/bin/clang --version | head -1 | \
		${SED} -e 's/.*clang version \([0-9]\)\.\([0-9]\).*/\1\2/' 
.else
_CLANG=	0
.endif

.if ${_CLANG} < 33
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang33:${PORTSDIR}/lang/clang33
CPP=	${LOCALBASE}/bin/clang-cpp33
CC=	${LOCALBASE}/bin/clang33
CXX=	${LOCALBASE}/bin/clang++33
.else
CPP=	/usr/bin/clang-cpp33
CC=	/usr/bin/clang
CXX=	/usr/bin/clang++
.endif

MAKE_ENV+=	"CC=${CC} CXX=${CXX}"



# ---------------------------------------------------------------------------
# using base
#
.if defined(USE_GNUSTEP_BASE)
BUILD_DEPENDS+=	${GNUSTEP_SYSTEM_LIBRARIES}/libgnustep-base.so:${PORTSDIR}/${GNUSTEP_BASE_PORT}
LIB_DEPENDS+=	objc.4:${PORTSDIR}/lang/libobjc2
RUN_DEPENDS+=	${GNUSTEP_SYSTEM_LIBRARIES}/libgnustep-base.so:${PORTSDIR}/${GNUSTEP_BASE_PORT}
.endif

# ---------------------------------------------------------------------------
# using gui
#
.if defined(USE_GNUSTEP_GUI)
BUILD_DEPENDS+=	${GNUSTEP_SYSTEM_LIBRARIES}/libgnustep-gui.so:${PORTSDIR}/${GNUSTEP_GUI_PORT}
RUN_DEPENDS+=	${GNUSTEP_SYSTEM_LIBRARIES}/libgnustep-gui.so:${PORTSDIR}/${GNUSTEP_GUI_PORT}
.endif

# ---------------------------------------------------------------------------
# using any backend
#
.if defined(USE_GNUSTEP_BACK)
BACKSUFFIX?=	-023
BACKCAIRO=     libgnustep-cairo${BACKSUFFIX}

BUILD_DEPENDS+=	${GNUSTEP_SYSTEM_BUNDLES}/${BACKCAIRO}.bundle/${BACKCAIRO}:${PORTSDIR}/${GNUSTEP_BACK_PORT}
RUN_DEPENDS+=	${GNUSTEP_SYSTEM_BUNDLES}/${BACKCAIRO}.bundle/${BACKCAIRO}:${PORTSDIR}/${GNUSTEP_BACK_PORT}

MAKE_FLAGS+=	GUI_BACKEND_LIB=cairo
.endif

# ---------------------------------------------------------------------------
# source system libs
#
.if defined(USE_GNUSTEP_SYSTEM_LIBS)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_SYSTEM_LIBS}
BUILD_DEPENDS+=	${GNUSTEP_SYSTEM_LIBRARIES}/lib${_GNUSTEP_DEP:C/:.*//}.so:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_SYSTEM_LIBRARIES}/lib${_GNUSTEP_DEP:C/:.*//}.so:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source system bundles
#
.if defined(USE_GNUSTEP_SYSTEM_BUNDLES)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_SYSTEM_BUNDLES}
BUILD_DEPENDS+=	${GNUSTEP_SYSTEM_BUNDLES}/${_GNUSTEP_DEP:C/:.*//}.bundle/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_SYSTEM_BUNDLES}/${_GNUSTEP_DEP:C/:.*//}.bundle/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source system themes
#
.if defined(USE_GNUSTEP_SYSTEM_THEMES)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_SYSTEM_THEMES}
BUILD_DEPENDS+=	${GNUSTEP_SYSTEM_BUNDLES}/${_GNUSTEP_DEP:C/:.*//}.themeEngine/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_SYSTEM_BUNDLES}/${_GNUSTEP_DEP:C/:.*//}.themeEngine/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source local libs
#
.if defined(USE_GNUSTEP_LOCAL_LIBS)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_LOCAL_LIBS}
BUILD_DEPENDS+=	${GNUSTEP_LOCAL_LIBRARIES}/lib${_GNUSTEP_DEP:C/:.*//}.so:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_LOCAL_LIBRARIES}/lib${_GNUSTEP_DEP:C/:.*//}.so:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source local bundles
#
.if defined(USE_GNUSTEP_LOCAL_BUNDLES)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_LOCAL_BUNDLES}
BUILD_DEPENDS+=	${GNUSTEP_LOCAL_BUNDLES}/${_GNUSTEP_DEP:C/:.*//}.bundle/${_GNUSTEP_DEP:C/:.*//:C;.*/;;}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_LOCAL_BUNDLES}/${_GNUSTEP_DEP:C/:.*//}.bundle/${_GNUSTEP_DEP:C/:.*//:C;.*/;;}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source local themes
#
.if defined(USE_GNUSTEP_LOCAL_THEMES)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_LOCAL_THEMES}
BUILD_DEPENDS+=	${GNUSTEP_LOCAL_BUNDLES}/${_GNUSTEP_DEP:C/:.*//}.themeEngine/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_LOCAL_BUNDLES}/${_GNUSTEP_DEP:C/:.*//}.themeEngine/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source local menulets
#
.if defined(USE_GNUSTEP_LOCAL_MENULETS)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_LOCAL_MENULETS}
BUILD_DEPENDS+=	${GNUSTEP_LOCAL_BUNDLES}/${_GNUSTEP_DEP:C/:.*//}.menulet/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_LOCAL_BUNDLES}/${_GNUSTEP_DEP:C/:.*//}.menulet/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source local asts
#
.if defined(USE_GNUSTEP_LOCAL_ASTS)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_LOCAL_ASTS}
BUILD_DEPENDS+=	${GNUSTEP_LOCAL_BUNDLES}/LanguageKit/${_GNUSTEP_DEP:C/:.*//}.ast/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_LOCAL_BUNDLES}/LanguageKit/${_GNUSTEP_DEP:C/:.*//}.ast/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source local burns
#
.if defined(USE_GNUSTEP_LOCAL_BURNS)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_LOCAL_BURNS}
BUILD_DEPENDS+=	${GNUSTEP_LOCAL_ROOT}/Library/Burn/${_GNUSTEP_DEP:C/:.*//}.bundle/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_LOCAL_ROOT}/Library/Burn/${_GNUSTEP_DEP:C/:.*//}.bundle/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source system apps
#
.if defined(USE_GNUSTEP_SYSTEM_APPS)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_SYSTEM_APPS}
BUILD_DEPENDS+=	${GNUSTEP_SYSTEM_APPS}/${_GNUSTEP_DEP:C/:.*//}.app/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_SYSTEM_APPS}/${_GNUSTEP_DEP:C/:.*//}.app/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source local apps
#
.if defined(USE_GNUSTEP_LOCAL_APPS)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_LOCAL_APPS}
BUILD_DEPENDS+=	${GNUSTEP_LOCAL_APPS}/${_GNUSTEP_DEP:C/:.*//}.app/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_LOCAL_APPS}/${_GNUSTEP_DEP:C/:.*//}.app/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source system tools
#
.if defined(USE_GNUSTEP_SYSTEM_TOOLS)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_SYSTEM_TOOLS}
BUILD_DEPENDS+=	${GNUSTEP_SYSTEM_TOOLS}/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_SYSTEM_TOOLS}/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source local tools
#
.if defined(USE_GNUSTEP_LOCAL_TOOLS)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_LOCAL_TOOLS}
BUILD_DEPENDS+=	${GNUSTEP_LOCAL_TOOLS}/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_LOCAL_TOOLS}/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source system services
#
.if defined(USE_GNUSTEP_SYSTEM_SERVICES)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_SYSTEM_SERVICES}
BUILD_DEPENDS+=	${GNUSTEP_SYSTEM_SERVICES}/${_GNUSTEP_DEP:C/:.*//}.service/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_SYSTEM_SERVICES}/${_GNUSTEP_DEP:C/:.*//}.service/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source local services
#
.if defined(USE_GNUSTEP_LOCAL_SERVICES)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_LOCAL_SERVICES}
BUILD_DEPENDS+=	${GNUSTEP_LOCAL_SERVICES}/${_GNUSTEP_DEP:C/:.*//}.service/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${GNUSTEP_LOCAL_SERVICES}/${_GNUSTEP_DEP:C/:.*//}.service/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source GNUstep.sh
#
.if defined(USE_GNUSTEP_CONFIGURE)
NO_CCACHE=	Overrides PATH set from GNUstep.sh
run-autotools::
	@${DO_NADA}

do-configure:
	@(cd ${CONFIGURE_WRKSRC}; . ${GNUSTEP_MAKEFILES}/GNUstep.sh; \
	    if ! ${SETENV} CC="${CC}" CXX="${CXX}" CPP="${CPP}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
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
NO_CCACHE=	Overrides PATH set from GNUstep.sh
do-build:
.if defined(USE_GNUSTEP_MAKE_DIRS)
.for i in ${USE_GNUSTEP_MAKE_DIRS}
	@(cd ${BUILD_WRKSRC}/${i}; . ${GNUSTEP_MAKEFILES}/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})
.endfor
.else
	@(cd ${BUILD_WRKSRC}; . ${GNUSTEP_MAKEFILES}/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})
.endif

.endif

# ---------------------------------------------------------------------------
# source GNUstep.sh
#
.if defined(USE_GNUSTEP_INSTALL)
do-install:
.if defined(USE_GNUSTEP_MAKE_DIRS)
.for i in ${USE_GNUSTEP_MAKE_DIRS}
	@(cd ${INSTALL_WRKSRC}/${i}; . ${GNUSTEP_MAKEFILES}/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
.endfor
.else
	@(cd ${INSTALL_WRKSRC}; . ${GNUSTEP_MAKEFILES}/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
.endif
.if defined(PACKAGE_BUILDING) || defined(BATCH) || defined(CLEAN_ROOT)
	rm -rf /root/GNUstep
.endif

.endif

.if !defined(GNUSTEP_WITH_BASE_GCC)
TARGLIB!=	${MAKE} -C ${PORTSDIR}/${GNUSTEP_GCC_PORT} -V TARGLIB
.endif

.endif

# ---------------------------------------------------------------------------
# run ldconfig for installed shlibs
#
.if defined(USE_GNUSTEP_LDCONFIG)
.for i in ${USE_GNUSTEP_LDCONFIG}
USE_LDCONFIG+=	${i}
.endfor
.endif

# eof
