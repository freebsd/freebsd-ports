# Created by: Daniel O'Connor <darius@dons.net.au>
# $FreeBSD$

PORTNAME=	pfstools
PORTVERSION=	1.8.5
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	fbsd@any.com.ru
COMMENT=	Tools for manipulating HDR images and video frames

LICENSE=	LGPL21

RUN_DEPENDS+=	bash:shells/bash

PFS_BUILD=	${MACHINE_ARCH}-portbld-freebsd${OSREL}
PLIST_SUB+=	PFS_BASE=${PREFIX}

USES=		gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	${PFS_BUILD}
CONFIGURE_ARGS+=	--disable-jpeghdr --disable-matlab \
		--with-bash=${LOCALBASE}/bin/bash
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${LOCALBASE}/libdata/pkgconfig
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NETPBM OPENEXR TIFF QT IMAGEMAGICK GDAL OCTAVE OPENGL
QT_DESC=	Compile programs that use QT library
GDAL_DESC=	Compile programs that use GDAL library
OCTAVE_DESC=	Compile octave interface functions

OPTIONS_DEFAULT=	TIFF
OPTIONS_SUB=		yes

NETPBM_CONFIGURE_ENABLE=	netpbm
NETPBM_LIB_DEPENDS=		libnetpbm.so:graphics/netpbm

OPENEXR_CONFIGURE_ENABLE=	openexr
OPENEXR_CONFIGURE_ON=		--with-exrdir=${LOCALBASE}/include/OpenEXR
OPENEXR_LIB_DEPENDS=		libIlmImf.so:graphics/OpenEXR

TIFF_CONFIGURE_ENABLE=		tiff
TIFF_LIB_DEPENDS=		libtiff.so:graphics/tiff

QT_CONFIGURE_ENABLE=		qt
QT_USE=				QT4=moc_build,corelib,gui

IMAGEMAGICK_CONFIGURE_ENABLE=	imagemagick
IMAGEMAGICK_LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick

GDAL_CONFIGURE_ENABLE=		gdal
GDAL_LIB_DEPENDS=		libgdal.so:graphics/gdal

OPENGL_CONFIGURE_ENABLE=	opengl
OPENGL_USE=			GL=glut

OCTAVE_CONFIGURE_ENABLE=	octave
OCTAVE_PATCH_DEPENDS=		octave-config:math/octave
OCTAVE_BUILD_DEPENDS=		mkoctfile:math/octave
OCTAVE_RUN_DEPENDS=		octave:math/octave

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOCTAVE}
OCTAVE_BASE?=	${LOCALBASE}
OCTAVE_VERSION!=${OCTAVE_BASE}/bin/octave-config -v 2>&1 || ${ECHO} "0"
OCTAVE_SITE_OCT!=${OCTAVE_BASE}/bin/octave-config --oct-site-dir 2>&1 || ${ECHO} ""
OCTAVE_SITE_M!=	${OCTAVE_BASE}/bin/octave-config --m-site-dir 2>&1 || ${ECHO} ""
PLIST_SUB+=	\
		OCTAVE_BASE=${OCTAVE_BASE} \
		OCTAVE_SITE_M=${OCTAVE_SITE_M:S|^${OCTAVE_BASE}/||} \
		OCTAVE_SITE_OCT=${OCTAVE_SITE_OCT:S|^${OCTAVE_BASE}/||}
USES+=		shebangfix
SHEBANG_FILES=	src/octave/*
SHEBANG_LANG+=	octave
octave_OLD_CMD?=/usr/bin/octave
octave_CMD?=	${OCTAVE_BASE}/bin/octave
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib//libpfs-1.2.so.0.0.0

.include <bsd.port.mk>
