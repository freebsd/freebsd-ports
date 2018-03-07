# $FreeBSD$
#
# Support for Lazarus-based ports.
#
# Feature:      lazarus
# Usage:        USES=lazarus
# Valid ARGS:   (none), gtk2, qt4, qt5
#
# For FreeBSD committers:
# Please send all suggested changes to the maintainer instead of committing
# them to SVN yourself.
#
# (none)    - This automatically build lazarus-app with gtk2 interface
#
# gtk2      - This automatically build lazarus-app with gtk2 interface
#     
# qt4       - This automatically build lazarus-app with qt4 interface
#
# qt5       - This automatically build lazarus-app with qt5 interface
#                
# Variables for ports:
#
# LAZARUS_PROJECT_FILES             - List of lpi files. It must not be empty
#				    Default: empty
# LAZARUS_DIR            	    - Path to lazarus installation directory
#                       	    Default: ${LOCALBASE}/share/lazarus-${LAZARUS_VER}
# LAZBUILD_ARGS			    - lazbuild extra args. It could be -d most of cases.
#				      See man lazbuild for more information
#				    Default: empty
#

.if !defined(_INCLUDE_USES_LAZARUS_MK)

LAZARUS_Include_MAINTAINER= acm@FreeBSD.org

_INCLUDE_USES_LAZARUS_MK=   yes

.if defined(DEFAULT_LAZARUS_VER)
WARNING+=	"DEFAULT_LAZARUS_VER is defined, consider using DEFAULT_VERSIONS=lazarus=${DEFAULT_LAZARUS_VER} instead"
.endif

.if empty(lazarus_ARGS:Mgtk2) && empty(lazarus_ARGS:Mqt4) && empty(lazarus_ARGS:Mqt5)
lazarus_ARGS+=	gtk2
.endif

DEFAULT_LAZARUS_VER=	${LAZARUS_DEFAULT}
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
LAZARUS_VER=		${DEFAULT_LAZARUS_VER}
LAZARUS_ARCH=		${ARCH:S/amd64/x86_64/}
LAZARUS_PROJECT_FILES?=	# empty
LAZARUS_DIR?=		${LOCALBASE}/share/lazarus-${LAZARUS_VER}

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	not yet ported to anything other than i386 and amd64

BUILD_DEPENDS+=		fpcres:lang/fpc-utils

BUILDNAME=		${LAZARUS_ARCH}-${OPSYS:tl}
LCL_UNITS_DIR=		${LOCALBASE}/share/lazarus-${LAZARUS_VER}/lcl/units/${BUILDNAME}

.if ${lazarus_ARGS:Mgtk2}
USE_FPC+=	gtk2
USE_GNOME=	gdkpixbuf2 gtk20
LCL_PLATFORM=	gtk2
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus
.endif

.if ${lazarus_ARGS:Mqt4}
LIB_DEPENDS+=	libQt4Pas.so:x11-toolkits/qt4pas
LCL_PLATFORM=	qt
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-qt4
.endif

.if ${lazarus_ARGS:Mqt5}
LIB_DEPENDS+=	libQt5Pas.so:x11-toolkits/qt5pas
LCL_PLATFORM=	qt5
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-qt5
.endif

LAZBUILD_CMD=	${LOCALBASE}/bin/lazbuild
LAZBUILD_ARGS?=	# empty

.if !defined(NO_LAZBUILD)
.	if !target(do-build)
do-build:
.	for PROJECT_FILE in ${LAZARUS_PROJECT_FILES}
		@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${LAZARUS_CMD} \
			${LAZBUILD_ARGS} --ws=${LCL_PLATFORM} --lazarusdir=${LAZARUS_DIR} ${PROJECT_FILE})
.	endfor
.	endif # !target(do-build)
.endif

.endif
# End of lazarus.mk file
