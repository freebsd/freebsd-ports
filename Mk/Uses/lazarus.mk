#
# $FreeBSD$
#
# Support for Lazarus-based ports.
#
# Feature:      lazarus
# Usage:        USES=lazarus
# Valid ARGS:   (none), gtk2, qt4, qt5, flavors
#
# (none)    - This automatically build lazarus-app with gtk2 interface
#
# gtk2      - This automatically build lazarus-app with gtk2 interface
#     
# qt4       - This automatically build lazarus-app with qt4 interface
#
# qt5       - This automatically build lazarus-app with qt5 interface
#                
# flavors   - This automatically build lazarus-app with flavors feature
#
# If the port not requires compile lazarus project files automatically, you can
# defined the following:
#
# NO_LAZBUILD=	yes
#                
# Variables for ports:
#
# LAZARUS_PROJECT_FILES		- List of lpi files. It must not be empty
#				Default: empty
# LAZARUS_DIR                   - Path to lazarus installation directory
#                               Default: ${LOCALBASE}/share/lazarus-${LAZARUS_VER}
# LAZBUILD_ARGS                 - lazbuild extra args. It could be -d most of cases.
#                                 See man lazbuild for more information
#                               Default: empty
# LAZARUS_NO_FLAVORS		- Do NOT build these lazarus flavors.
#                                 If LAZARUS_NO_FLAVORS is not define then all
#                             	  valid lazarus flavors are assumed.
#
# Example:
#        
#	USES+=	lazarus:flavors
#	LAZARUS_NO_FLAVORS=qt5
#

.if !defined(_INCLUDE_USES_LAZARUS_MK)

LAZARUS_Include_MAINTAINER= acm@FreeBSD.org

_INCLUDE_USES_LAZARUS_MK=   yes

.if defined(DEFAULT_LAZARUS_VER)
WARNING+=	"DEFAULT_LAZARUS_VER is defined, consider using DEFAULT_VERSIONS=lazarus=${DEFAULT_LAZARUS_VER} instead"
.endif

.if ${lazarus_ARGS:Ngtk2:Nqt4:Nqt5:Nflavors}
IGNORE=		Unknown argument for USES=lazarus: ${lazarus_ARGS:Ngtk2:Nqt4:Nqt5:Nflavors}
.endif

.if !empty(LAZARUS_NO_FLAVORS)
.if ${LAZARUS_NO_FLAVORS:Ngtk2:Nqt4:Nqt5}
IGNORE=         Unknown argument for LAZARUS_NO_FLAVORS: ${LAZARUS_NO_FLAVORS:Ngtk2:Nqt4:Nqt5}
.endif
.endif

DEFAULT_LAZARUS_VER=	${LAZARUS_DEFAULT}
DEFAULT_FPC_VER=	${FPC_DEFAULT}
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
LAZARUS_VER=		${DEFAULT_LAZARUS_VER}
FPC_VER=		${DEFAULT_FPC_VER}
LAZARUS_ARCH=		${ARCH:S/amd64/x86_64/}
LAZARUS_PROJECT_FILES?=	# empty
LAZARUS_DIR?=		${LOCALBASE}/share/lazarus-${LAZARUS_VER}

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	not yet ported to anything other than i386 and amd64

BUILD_DEPENDS+=		fpcres:lang/fpc-utils

BUILDNAME=		${LAZARUS_ARCH}-${OPSYS:tl}
LCL_UNITS_DIR=		${LOCALBASE}/share/lazarus-${LAZARUS_VER}/lcl/units/${BUILDNAME}
MKINSTDIR=		${LOCALBASE}/lib/fpc/${FPC_VER}/fpmkinst/${BUILDNAME}

LAZARUS_FLAVORS=	gtk2 qt4 qt5

.if ${lazarus_ARGS:Mflavors}
.	if defined(LAZARUS_NO_FLAVORS)
.		for flavor in ${LAZARUS_NO_FLAVORS}
FLAVORS:=	${LAZARUS_FLAVORS:N${flavor}}
.		endfor
.	else
FLAVORS:=	${LAZARUS_FLAVORS}
.	endif

.	if empty(FLAVOR)
FLAVOR=		${FLAVORS:[1]}
.	endif
.endif

LAZARUS_PKGNAMESUFFIX=	-${FLAVOR}

.if ${lazarus_ARGS:Mgtk2} || ${FLAVOR} == gtk2
BUILD_DEPENDS+=	${MKINSTDIR}/gtk2.fpm:x11-toolkits/fpc-gtk2
LIB_DEPENDS+=	libglib-2.0.so:devel/glib20 \
		libgtk-x11-2.0.so:x11-toolkits/gtk20 \
		libatk-1.0.so:accessibility/atk \
		libpango-1.0.so:x11-toolkits/pango \
		libgdk_pixbuf-2.0.so:graphics/gdk-pixbuf2
LCL_PLATFORM=	gtk2
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus
.endif

.if ${lazarus_ARGS:Mqt4} || ${FLAVOR} == qt4
LIB_DEPENDS+=	libQt4Pas.so:x11-toolkits/qt4pas
LCL_PLATFORM=	qt
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-qt4
.endif

.if ${lazarus_ARGS:Mqt5} || ${FLAVOR} == qt5
LIB_DEPENDS+=	libQt5Pas.so:x11-toolkits/qt5pas
LCL_PLATFORM=	qt5
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-qt5
.endif

LAZBUILD_CMD=	${LOCALBASE}/bin/lazbuild
LAZBUILD_ARGS?=	# empty

_USES_POST+=	lazarus
.endif 
# End of _INCLUDE_USES_LAZARUS_MK

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_LAZARUS_POST_MK)
_INCLUDE_USES_LAZARUS_POST_MK=	yes

.if !defined(NO_LAZBUILD)
.if !target(do-build)
do-build:
.	for PROJECT_FILE in ${LAZARUS_PROJECT_FILES}
		@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${LAZBUILD_CMD} \
			${LAZBUILD_ARGS} --ws=${LCL_PLATFORM} --lazarusdir=${LAZARUS_DIR} ${PROJECT_FILE})
.	endfor
.endif # !target(do-build)
.endif

.endif
# End of _INCLUDE_USES_LAZARUS_POST_MK
