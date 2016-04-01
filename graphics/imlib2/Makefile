# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	imlib2
PORTVERSION=	1.4.7
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	SF/enlightenment/imlib2-src/${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	The next generation graphics library for Enlightenment

LICENSE=	imlib2
LICENSE_NAME=	imlib2 license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libfreetype.so:print/freetype2

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool pathfix pkgconfig tar:bzip2

CONFIGURE_ARGS+=	--enable-visibility-hiding --disable-static
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
USES+=		jpeg
PLIST_SUB+=	JPEG=""
.else
CONFIGURE_ARGS+=	--without-jpeg
PLIST_SUB+=	JPEG="@comment "
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng.so:graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=	--without-png
PLIST_SUB+=	PNG="@comment "
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	libtiff.so:graphics/tiff
PLIST_SUB+=	TIFF=""
.else
CONFIGURE_ARGS+=	--without-tiff
PLIST_SUB+=	TIFF="@comment "
.endif

.if ${PORT_OPTIONS:MGIF}
LIB_DEPENDS+=	libgif.so:graphics/giflib
PLIST_SUB+=	GIF=""
.else
CONFIGURE_ARGS+=	--without-gif
PLIST_SUB+=	GIF="@comment "
.endif

.if ${PORT_OPTIONS:MID3}
LIB_DEPENDS+=	libid3tag.so:audio/libid3tag
PLIST_SUB+=	ID3=""
.else
CONFIGURE_ARGS+=	--without-id3
PLIST_SUB+=	ID3="@comment "
.endif

.if ! ${PORT_OPTIONS:MX11}
post-patch:
	@${REINPLACE_CMD} -e '/MY_LIBS =/s/-lXext -lX11//' \
		${WRKSRC}/src/lib/Makefile.in
	@${REINPLACE_CMD} -e '/# ifndef X_DISPLAY_MISSING/,/# endif/ d' \
		${WRKSRC}/src/lib/Imlib2.h
.endif

.include <bsd.port.mk>
