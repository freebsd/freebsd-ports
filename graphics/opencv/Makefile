# New ports collection makefile for:   opencv - open source computer vision
# library from Intel
# Date created:                05 March 2005
# Whom:                        Marc Abramowitz (http://marc.abramowitz.info)
#
# $FreeBSD$
#

PORTNAME=	opencv
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/opencvlibrary

MAINTAINER=	msabramo@yahoo.com
COMMENT=	Open Source Computer Vision Library from Intel

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat

CFLAGS+=	-I${LOCALBASE}/include/OpenEXR
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/OpenEXR
LDFLAGS+=	-L${LOCALBASE}/lib
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-v4l --without-quicktime --without-carbon \
				--without-1394libs \
				--without-swig # I don't know anything about swig ...
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg \
				png:${PORTSDIR}/graphics/png \
				tiff:${PORTSDIR}/graphics/tiff \
				jasper:${PORTSDIR}/graphics/jasper \
				IlmImf:${PORTSDIR}/graphics/OpenEXR
USE_GNOME=

OPTIONS=	GTK "Enable GTK+-2.0 support" Off \
			XINE "Enable XINE support" Off \
			FFMPEG "Enable FFMPEG support" Off \
			PYTHON "Enable PYTHON support" Off \
			DEBUG "Build debugging symbols" Off \
			DEMO "Build demo apps" Off
# XXX:
# I cannot disable the following features if they have been installed,
# thus they should be enable now ...
#
#			JPEG "Enable JPEG support" On \
#			PNG	"Enable PNG support" On \
#			TIFF "Enable TIFF support" On \
#			JASPER "Enable JASPER support" Off \
#			OPENEXR "Enable OpenEXR support" Off \

.include <bsd.port.pre.mk>

.if defined(WITH_GTK)
USE_GNOME=	gtk20
CONFIGURE_ARGS+=--with-gtk
.else
CONFIGURE_ARGS+=--without-gtk
.endif

#.if !defined(WITHOUT_JPEG)
#LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
#.endif
#
#.if !defined(WITHOUT_PNG)
#LIB_DEPENDS+=	png:${PORTSDIR}/graphics/png
#.endif
#
#.if !defined(WITHOUT_TIFF)
#LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
#.endif
#
#.if defined(WITH_JASPER)
#LIB_DEPENDS+=	jasper:${PORTSDIR}/graphics/jasper
#.endif
#
#.if defined(WITH_OPENEXR)
#LIB_DEPENDS+=	libIlmImf:${PORTSDIR}/graphics/OpenEXR
#CFLAGS+=	-I${LOCALBASE}/include/OpenEXR
#CPPFLAGS+=	-I${LOCALBASE}/include/OpenEXR
#.endif

.if defined(WITH_XINE)
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIB_DEPENDS+=	xine:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=--with-xine
.else
CONFIGURE_ARGS+=--without-xine
.endif

.if defined(WITH_FFMPEG)
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=--with-ffmpeg
.else
CONFIGURE_ARGS+=--without-ffmpeg
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
CONFIGURE_ARGS+=--with-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

.if defined(WITH_DEMO)
CONFIGURE_ARGS+=--enable-apps
PLIST_SUB+=	DEMO=""
.else
CONFIGURE_ARGS+=--disable-apps
PLIST_SUB+=	DEMO="@comment "
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

.include <bsd.port.post.mk>
