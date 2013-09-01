# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	imlib2
PORTVERSION=	1.4.5
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment/imlib2-src/${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	The next generation graphics library for Enlightenment

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		pathfix pkgconfig
USE_EFL=	libtool_hack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	JPEG PNG TIFF GIF ID3 X11
OPTIONS_DEFAULT=	JPEG PNG TIFF GIF ID3 X11

.include <bsd.port.options.mk>

.if ${ARCH} == "i386" && !empty(MACHINE_CPU:Mmmx)
CONFIGURE_ARGS+=	--enable-mmx
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--enable-amd64
.else
CONFIGURE_ARGS+=	--disable-amd64
.endif

.if ! ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=	--without-x
PKGNAMESUFFIX+=	-nox11
PLIST_SUB=	X11="@comment "
.else
USE_XORG=	x11 sm xext
PLIST_SUB=	X11=""
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEG=""
.else
CONFIGURE_ARGS+=	--without-jpeg
PLIST_SUB+=	JPEG="@comment "
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=	--without-png
PLIST_SUB+=	PNG="@comment "
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	TIFF=""
.else
CONFIGURE_ARGS+=	--without-tiff
PLIST_SUB+=	TIFF="@comment "
.endif

.if ${PORT_OPTIONS:MGIF}
LIB_DEPENDS+=	gif.5:${PORTSDIR}/graphics/giflib
PLIST_SUB+=	GIF=""
.else
CONFIGURE_ARGS+=	--without-gif
PLIST_SUB+=	GIF="@comment "
.endif

.if ${PORT_OPTIONS:MID3}
LIB_DEPENDS+=	id3tag.0:${PORTSDIR}/audio/libid3tag
PLIST_SUB+=	ID3=""
.else
CONFIGURE_ARGS+=	--without-id3
PLIST_SUB+=	ID3="@comment "
.endif

.include <bsd.port.mk>
