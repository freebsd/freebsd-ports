# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	imlib2
PORTVERSION=	1.4.6
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment/imlib2-src/${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	The next generation graphics library for Enlightenment

LICENSE=	imlib2
LICENSE_NAME=	imlib2 license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_EFL=	libtool_hack
USE_LDCONFIG=	yes
USES=		pathfix pkgconfig

CONFIGURE_ARGS+=	--enable-visibility-hiding
CONFIGURE_ENV+=	ac_cv_lib_dl_dlopen=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	INSTALL_STRIP_FLAG="${STRIP}"

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
PLIST_SUB=	X11="@comment "
.else
USE_XORG=	x11 sm xext
PLIST_SUB=	X11=""
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEG=""
.else
CONFIGURE_ARGS+=	--without-jpeg
PLIST_SUB+=	JPEG="@comment "
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=	--without-png
PLIST_SUB+=	PNG="@comment "
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	libtiff.so:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	TIFF=""
.else
CONFIGURE_ARGS+=	--without-tiff
PLIST_SUB+=	TIFF="@comment "
.endif

.if ${PORT_OPTIONS:MGIF}
LIB_DEPENDS+=	libgif.so:${PORTSDIR}/graphics/giflib
PLIST_SUB+=	GIF=""
.else
CONFIGURE_ARGS+=	--without-gif
PLIST_SUB+=	GIF="@comment "
.endif

.if ${PORT_OPTIONS:MID3}
LIB_DEPENDS+=	libid3tag.so:${PORTSDIR}/audio/libid3tag
PLIST_SUB+=	ID3=""
.else
CONFIGURE_ARGS+=	--without-id3
PLIST_SUB+=	ID3="@comment "
.endif

.if ! ${PORT_OPTIONS:MX11}
post-patch:
	@${REINPLACE_CMD} -e '/MY_LIBS =/s/-lXext -lX11//' \
	${WRKSRC}/src/lib/Makefile.in

.endif

.include <bsd.port.mk>
