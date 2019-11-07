# Created by: Oliver Heesakkers <dev2@heesakkers.info>
# $FreeBSD$

PORTNAME=	zbar
PORTVERSION=	0.10
PORTREVISION=	18
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	dev2@heesakkers.info
COMMENT=	ZBar barcode reader

LICENSE=	LGPL21

USES=		iconv jpeg libtool gmake pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--with-jpeg=yes --with-qt=no

OPTIONS_DEFINE=	X11 V4L PYTHON GTK2 DOCS
OPTIONS_DEFAULT=X11 V7
OPTIONS_RADIO=	IMAGEMAGICK
OPTIONS_RADIO_IMAGEMAGICK=	V6 V7
OPTIONS_SUB=	yes
V4L_DESC=	Build zbarcam video scanner

X11_USES=	xorg
X11_USE=	XORG=ice,sm,x11,xau,xcb,xdmcp,xext,xv
X11_CONFIGURE_ON=	--with-x=yes
X11_CONFIGURE_OFF=	--with-x=no --without-xshm --without-xv

V6_DESC=	With ImageMagick6
V6_LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick6
V6_CONFIGURE_ON=	--with-imagemagick=yes

V7_DESC=	With ImageMagick7
V7_LIB_DEPENDS=	libMagick++-7.so:graphics/ImageMagick7
V7_CONFIGURE_ON=	--with-imagemagick=yes

.if empty(VARIABLE:MV6) && empty(VARIABLE:MV7)
CONFIGURE_ARGS+=	--with-imagemagick=no
.endif

# To avoid patching configure even more:
CONFIGURE_ENV+=			ac_cv_header_wand_MagickWand_h=yes

V4L_BUILD_DEPENDS=	v4l_compat>=1.0.20101027:multimedia/v4l_compat
V4L_CONFIGURE_ON=	--enable-video=yes
V4L_CONFIGURE_OFF=	--enable-video=no

PYTHON_USE=		GNOME=pygtk2
PYTHON_USES=		python:2.7
PYTHON_CONFIGURE_ON=	--with-python=yes
PYTHON_CONFIGURE_OFF=	--with-python=no

GTK2_USE=	GNOME=gtk20
GTK2_CONFIGURE_ON=	--with-gtk=yes
GTK2_CONFIGURE_OFF=	--with-gtk=no

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch-DOCS-off:
	@${REINPLACE_CMD} '/^install-data-am: /s/install-dist_docDATA//' \
		${WRKSRC}/Makefile.in

post-install:
	# make check-plist happy
	${RMDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
