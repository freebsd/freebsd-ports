# This file contains some variable definitions that are supposed to make your
# life easier, when dealing with ports related to the LXQt Desktop Environment.
#
# Feature:	lxqt
# Usage:	USES=lxqt:<version>
# Valid ARGS:	1, 2
#
# Available LXQt components are:
#
# buildtools / buildtools2	- Helpers CMake modules
# globalkeys			- Keyboard shortcuts daemon
# libfmqt / libfmqt6		- Libfm Qt5/Qt6 bindings
# lxqt				- LXQt core library
# qtxdg / qt6xdg		- Qt5/Qt6 implementation of freedesktop.org xdg specs
# sysstat / sysstat-qt6		- Qt5/Qt6 library to query system information
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_LXQT_MK)
_INCLUDE_USES_LXQT_MK=	yes

.  if empty(lxqt_ARGS)
IGNORE=	Incorrect 'USES+=lxqt:${lxqt_ARGS} takes arguments 1 or 2
.  endif

.  if ${lxqt_ARGS:N1:N2}
IGNORE=	Unknown argument for USES=lxqt: ${lxqt_ARGS:N1:N2}
.  endif

_LXQT_VER=	${lxqt_ARGS}
_LXQT_PROJECT=	${DISTNAME:S/-${DISTVERSION}//:tl}

MASTER_SITE_LXQT+= \
	https://github.com/lxqt/%SUBDIR%/releases/download/${PORTVERSION}/ \
	https://downloads.lxqt.org/downloads/%SUBDIR%/${PORTVERSION}/
MASTER_SITE_LXQT_SUBDIR=	${_LXQT_PROJECT}

MASTER_SITES?=	${MASTER_SITE_LXQT}
MASTER_SITE_SUBDIR?=	${MASTER_SITE_LXQT_SUBDIR}

DISTNAME=	${PORTNAME:S/2//:S/6//}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
DIST_SUBDIR=	lxqt

PLIST_SUB+=	LXQT_INCLUDEDIR="include/lxqt" \
	LXQT_SHAREDIR="share/lxqt" \
	LXQT_TRANSLATIONS="share/lxqt/translations" \
	VERSION="${PORTVERSION}"

CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/share/man

# Available LXQt components are:
_USE_LXQT1_ONLY=buildtools libfmqt qtxdg sysstat

_USE_LXQT2_ONLY=buildtools2 globalkeys libfmqt6 lxqt qt6xdg sysstat-qt6

_USE_LXQT_ALL=	${_USE_LXQT${_LXQT_VER}_ONLY}

_DATAROOTDIR=	${LOCALBASE}/share

buildtools_BUILD_DEPENDS=	${_DATAROOTDIR}/cmake/lxqt-build-tools/lxqt-build-tools-config.cmake:devel/lxqt-build-tools
buildtools2_BUILD_DEPENDS=	${_DATAROOTDIR}/cmake/lxqt2-build-tools/lxqt2-build-tools-config.cmake:devel/lxqt2-build-tools

globalkeys_LIB_DEPENDS=	liblxqt-globalkeys.so:x11/lxqt-globalkeys
globalkeys_USE_LXQT_REQ=	lxqt

libfmqt_LIB_DEPENDS=	libfm-qt.so:x11/libfm-qt
libfmqt6_LIB_DEPENDS=	libfm-qt6.so:x11/libfm-qt6

lxqt_LIB_DEPENDS=	liblxqt.so:devel/liblxqt
lxqt_USE_LXQT_REQ=	qt6xdg

qtxdg_LIB_DEPENDS=	libQt5Xdg.so:devel/libqtxdg
qt6xdg_LIB_DEPENDS=	libQt6Xdg.so:devel/libqt6xdg

sysstat_LIB_DEPENDS=	libsysstat-qt5:devel/libsysstat
sysstat-qt6_LIB_DEPENDS=libsysstat-qt6.so:devel/libsysstat-qt6

.  if defined(USE_LXQT)

# First, expand all USE_LXQT_REQ recursively.
.    for comp in ${_USE_LXQT_ALL}
.      for subcomp in ${${comp}_USE_LXQT_REQ}
${comp}_USE_LXQT_REQ+=	${${subcomp}_USE_LXQT_REQ}
.      endfor
.    endfor

# Then, use already expanded USE_LXQT_REQ to expand USE_LXQT.
.    for comp in ${USE_LXQT}
.      if empty(_USE_LXQT_ALL:M${comp})
IGNORE=	cannot install: Unknown component ${comp}
.      else
_USE_LXQT+=	${${comp}_USE_LXQT_REQ} ${comp}
.      endif
.    endfor

# Remove duplicate components
USE_LXQT=	${_USE_LXQT:O:u}

.    for comp in ${USE_LXQT}
.      if defined(${comp}_BUILD_DEPENDS)
BUILD_DEPENDS+=	${${comp}_BUILD_DEPENDS}
.      endif

.      if defined(${comp}_LIB_DEPENDS)
LIB_DEPENDS+=	${${comp}_LIB_DEPENDS}
.      endif

.      if defined(${comp}_RUN_DEPENDS)
RUN_DEPENDS+=	${${comp}_RUN_DEPENDS}
.      endif
.    endfor

.  endif # end of defined(USE_LXQT)

.endif # end of !defined(_INCLUDE_USES_LXQT_MK)

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_LXQT_POST_MK)

_INCLUDE_USES_LXQT_POST_MK=	yes

.endif
