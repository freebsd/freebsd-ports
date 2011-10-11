# New ports collection makefile for:	zbar
# Date created:				12 november 2010
# Whom:					Oliver Heesakkers <dev2@heesakkers.info>
#
# $FreeBSD$
#

PORTNAME=	zbar
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	dev2@heesakkers.info
COMMENT=	ZBar barcode reader

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_ICONV=	yes

OPTIONS=	X11         "Build with X support" on \
		IMAGEMAGICK "ImageMagick graphics support" on \
		V4L         "Build zbarcam video scanner" off \
		PYTHON      "Build PyGTK widget" off \
		GTK2        "Build GTK+2 widget" off \
		QT4         "Build Qt4 widget" off

.include <bsd.port.options.mk>

.if exists(${LOCALBASE}/lib/libjpeg.so)
CONFIGURE_ARGS+=	--with-jpeg=yes
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
.else
CONFIGURE_ARGS+=	--with-jpeg=no
.endif

.if defined(WITH_X11)
USE_XORG=	ice sm x11 xau xdmcp xext xv
LIBDEPENDS+=	xcb.2:${PORTSDIR}/x11/libxcb
CONFIGURE_ARGS+=	--with-x=yes
.else
CONFIGURE_ARGS+=	--with-x=no --without-xshm --without-xv
.endif

.if defined(WITH_IMAGEMAGICK)
LIB_DEPENDS+=	Magick++.5:${PORTSDIR}/graphics/ImageMagick
CONFIGURE_ARGS+=	--with-imagemagick=yes
PLIST_SUB+=	IMAGEMAGICK=""
MAN1=	zbarimg.1
.else
CONFIGURE_ARGS+=	--with-imagemagick=no
PLIST_SUB+=	IMAGEMAGICK="@comment "
.endif

.if defined(WITH_V4L)
BUILD_DEPENDS+=	v4l_compat>=1.0.20101027:${PORTSDIR}/multimedia/v4l_compat
CONFIGURE_ARGS+=	--enable-video=yes
PLIST_SUB+=	V4L=""
MAN1+=	zbarcam.1
.else
CONFIGURE_ARGS+=	--enable-video=no
PLIST_SUB+=	V4L="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	2.5-2.7
USE_GNOME+=	pygtk2
CONFIGURE_ARGS+=	--with-python=yes
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=	--with-python=no
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_GTK2)
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--with-gtk=yes
PLIST_SUB+=	GTK2=""
.else
CONFIGURE_ARGS+=	--with-gtk=no
PLIST_SUB+=	GTK2="@comment "
.endif

.if defined(WITH_QT4)
USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build
CONFIGURE_ARGS+=	--with-qt=yes
PLIST_SUB+=	QT4=""
.else
CONFIGURE_ARGS+=	--with-qt=no
PLIST_SUB+=	QT4="@comment "
.endif

LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} 's|^pkgconfigdir = .*|pkgconfigdir = $$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} '/^install-data-am: /s/install-dist_docDATA//' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
