# $FreeBSD$
#
# Handle GNUstep related ports
#
# Feature:	gnustep
# Usage:	USES=gnustep
#
# Defined specific dependencies under USE_GNUSTEP
# Expected arguments for USE_GNUSTEP:
#
# base:		depends on the gnustep-base port
# gui:		depends on the gnustep-gui port
# back:		depends on the gnustep-back port
# build:	prepare the build dependencies for a regular GNUstep port
#

.if !defined(_INCLUDE_USES_GNUSTEP_MK)
_INCLUDE_USES_GNUSTEP_MK=	yes
.include "${USESDIR}/gmake.mk"

GNUSTEP_PREFIX?=	${LOCALBASE}/GNUstep
DEFAULT_LIBVERSION?=	0.0.1

GNUSTEP_SYSTEM_ROOT=		${GNUSTEP_PREFIX}/System
GNUSTEP_MAKEFILES=		${GNUSTEP_SYSTEM_ROOT}/Library/Makefiles
GNUSTEP_SYSTEM_LIBRARIES=	${GNUSTEP_SYSTEM_ROOT}/Library/Libraries
GNUSTEP_SYSTEM_TOOLS=		${GNUSTEP_SYSTEM_ROOT}/Tools

GNUSTEP_LOCAL_ROOT=	${GNUSTEP_PREFIX}/Local
GNUSTEP_LOCAL_LIBRARIES=	${GNUSTEP_LOCAL_ROOT}/Library/Libraries
GNUSTEP_LOCAL_TOOLS=		${GNUSTEP_LOCAL_ROOT}/Tools

LIB_DIRS+=	${GNUSTEP_SYSTEM_LIBRARIES} \
		${GNUSTEP_LOCAL_LIBRARIES}

.for a in CFLAGS CPPFLAGS CXXFLAGS OBJCCFLAGS OBJCFLAGS LDFLAGS
MAKE_ENV+=	ADDITIONAL_${a}="${ADDITIONAL_${a}} ${${a}}"
.endfor
.for a in FLAGS INCLUDE_DIRS LIB_DIRS
MAKE_ENV+=	ADDITIONAL_${a}="${ADDITIONAL_${a}}"
.endfor
MAKE_ARGS+=messages=yes

MAKEFILE=	GNUmakefile
#MAKE_ENV+=	GNUSTEP_CONFIG_FILE=${PORTSDIR}/devel/gnustep-make/files/GNUstep.conf
GNU_CONFIGURE_PREFIX=	${GNUSTEP_PREFIX}

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} VERSION=${PORTVERSION}
PLIST_SUB+=	MAJORVERSION=${PORTVERSION:C/([0-9]).*/\1/1}
PLIST_SUB+=	LIBVERSION=${DEFAULT_LIBVERSION}
PLIST_SUB+=	MAJORLIBVERSION=${DEFAULT_LIBVERSION:C/([0-9]).*/\1/1}

.if defined(USE_GNUSTEP)
.  if ${USE_GNUSTEP:Mbase}
LIB_DEPENDS+=	libgnustep-base.so:lang/gnustep-base
.  endif

.  if ${USE_GNUSTEP:Mbuild}
PATH:=	${GNUSTEP_SYSTEM_TOOLS}:${GNUSTEP_LOCAL_TOOLS}:${PATH}
MAKE_ENV+=	PATH="${PATH}" GNUSTEP_MAKEFILES="${GNUSTEP_MAKEFILES}"
# All GNUstep things installed from ports should be in the System domain.
# Things installed from source can then freely live in the Local domain without
# conflicts.
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
CONFIGURE_ENV+=	PATH="${PATH}" GNUSTEP_MAKEFILES="${GNUSTEP_MAKEFILES}"
BUILD_DEPENDS+=	gnustep-make>0:devel/gnustep-make
.include "${USESDIR}/objc.mk"
.  endif

.  if ${USE_GNUSTEP:Mgui}
LIB_DEPENDS+=	libgnustep-gui.so:x11-toolkits/gnustep-gui
.  endif

.  if ${USE_GNUSTEP:Mback}
BUILD_DEPENDS+=	gnustep-back>0:x11-toolkits/gnustep-back
RUN_DEPENDS+=	gnustep-back>0:x11-toolkits/gnustep-back
.  endif

.endif

.endif
