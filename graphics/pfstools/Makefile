# Created by: Daniel O'Connor <darius@dons.net.au>
# $FreeBSD$

PORTNAME=	pfstools
PORTVERSION=	1.8.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	darius@dons.net.au
COMMENT=	Tools for manipulating HDR images and video frames

LICENSE=	LGPL21

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

PFS_CPPFLAGS=	-I${LOCALBASE}/include
PFS_LDFLAGS=	-L${LOCALBASE}/lib
PFS_BUILD=	${MACHINE_ARCH}-portbld-freebsd${OSREL}
PLIST_SUB+=	PFS_BASE=${PREFIX}

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	${PFS_BUILD}
CONFIGURE_ARGS=	--disable-jpeghdr --disable-matlab \
		--with-bash=${LOCALBASE}/bin/bash
CONFIGURE_ENV=	CPPFLAGS="${PFS_CPPFLAGS}" \
		LDFLAGS="${PFS_LDFLAGS}" \
		PKG_CONFIG_PATH=${LOCALBASE}/libdata/pkgconfig
USE_LDCONFIG=	yes
USES=		gmake pkgconfig libtool

OPTIONS_DEFINE=	NETPBM OPENEXR TIFF QT IMAGEMAGICK GDAL OCTAVE OPENGL
QT_DESC=	Compile programs that use QT library
GDAL_DESC=	Compile programs that use GDAL library
OCTAVE_DESC=	Compile octave interface functions

OPTIONS_DEFAULT=	TIFF
OPTIONS_SUB=		yes

NETPBM_CONFIGURE_ENABLE=	ppm
NETPBM_LIB_DEPENDS=		libnetpbm.so:${PORTSDIR}/graphics/netpbm

OPENEXR_CONFIGURE_ENABLE=	openexr
OPENEXR_CONFIGURE_ON=		--with-exrdir=${LOCALBASE}/include/OpenEXR
OPENEXR_LIB_DEPENDS=		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR

TIFF_CONFIGURE_ENABLE=		tiff
TIFF_LIB_DEPENDS=		libtiff.so:${PORTSDIR}/graphics/tiff

QT_USE=			QT4=moc_build,corelib,gui
QT_CONFIGURE_ENABLE=	qt

IMAGEMAGICK_CONFIGURE_ENABLE=	imagemagick
IMAGEMAGICK_LIB_DEPENDS=	libMagick++-6.Q16.so:${PORTSDIR}/graphics/ImageMagick

GDAL_CONFIGURE_ENABLE=	gdal
GDAL_LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal

OPENGL_CONFIGURE_ENABLE=	opengl
OPENGL_USE=			GL=glut

OCTAVE_CONFIGURE_ENABLE=	octave
OCTAVE_PATCH_DEPENDS=		octave-config:${PORTSDIR}/math/octave
OCTAVE_BUILD_DEPENDS=		mkoctfile:${PORTSDIR}/math/octave
OCTAVE_RUN_DEPENDS=		octave:${PORTSDIR}/math/octave

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOCTAVE}
OCTAVE_BASE?=	${LOCALBASE}
OCTAVE_VERSION!=${OCTAVE_BASE}/bin/octave-config -v 2>&1 || ${ECHO} "0"
OCTAVE_SITE_OCT!=${OCTAVE_BASE}/bin/octave-config --oct-site-dir 2>&1 || ${ECHO} ""
OCTAVE_SITE_M!=	${OCTAVE_BASE}/bin/octave-config --m-site-dir 2>&1 || ${ECHO} ""
PLIST_SUB+=	OCTAVE="" \
		OCTAVE_BASE=${OCTAVE_BASE} \
		OCTAVE_SITE_M=${OCTAVE_SITE_M:S|^${OCTAVE_BASE}/||} \
		OCTAVE_SITE_OCT=${OCTAVE_SITE_OCT:S|^${OCTAVE_BASE}/||}
USES+=		shebangfix
SHEBANG_FILES=	src/octave/*
SHEBANG_LANG+=	octave
octave_OLD_CMD?=/usr/bin/octave
octave_CMD?=	${LOCALBASE}/bin/octave
.endif

.include <bsd.port.mk>
