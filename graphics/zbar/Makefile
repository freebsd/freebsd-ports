# Created by: Oliver Heesakkers <dev2@heesakkers.info>
# $FreeBSD$

PORTNAME=	zbar
PORTVERSION=	0.10
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	dev2@heesakkers.info
COMMENT=	ZBar barcode reader

LICENSE=	LGPL21

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		iconv gmake pkgconfig

CONFIGURE_ARGS=		--with-jpeg=yes

OPTIONS_DEFINE=	X11 IMAGEMAGICK V4L PYTHON GTK2 QT4
OPTIONS_DEFAULT=	X11 IMAGEMAGICK
V4L_DESC=	Build zbarcam video scanner

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	ice sm x11 xau xcb xdmcp xext xv
CONFIGURE_ARGS+=	--with-x=yes
.else
CONFIGURE_ARGS+=	--with-x=no --without-xshm --without-xv
.endif

.if ${PORT_OPTIONS:MIMAGEMAGICK}
LIB_DEPENDS+=	Magick++:${PORTSDIR}/graphics/ImageMagick
CONFIGURE_ARGS+=	--with-imagemagick=yes
PLIST_SUB+=	IMAGEMAGICK=""
MAN1=	zbarimg.1
.else
CONFIGURE_ARGS+=	--with-imagemagick=no
PLIST_SUB+=	IMAGEMAGICK="@comment "
.endif

.if ${PORT_OPTIONS:MV4L}
BUILD_DEPENDS+=	v4l_compat>=1.0.20101027:${PORTSDIR}/multimedia/v4l_compat
CONFIGURE_ARGS+=	--enable-video=yes
PLIST_SUB+=	V4L=""
MAN1+=	zbarcam.1
.else
CONFIGURE_ARGS+=	--enable-video=no
PLIST_SUB+=	V4L="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	2
USE_GNOME+=	pygtk2
CONFIGURE_ARGS+=	--with-python=yes
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=	--with-python=no
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--with-gtk=yes
PLIST_SUB+=	GTK2=""
.else
CONFIGURE_ARGS+=	--with-gtk=no
PLIST_SUB+=	GTK2="@comment "
.endif

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	gui moc_build
CONFIGURE_ARGS+=	--with-qt=yes
PLIST_SUB+=	QT4=""
.else
CONFIGURE_ARGS+=	--with-qt=no
PLIST_SUB+=	QT4="@comment "
.endif

LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} 's|^pkgconfigdir = .*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} '/^install-data-am: /s/install-dist_docDATA//' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
