# Created by: Oliver Heesakkers <dev2@heesakkers.info>
# $FreeBSD$

PORTNAME=	zbar
PORTVERSION=	0.10
PORTREVISION=	20
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	dev2@heesakkers.info
COMMENT=	ZBar barcode reader

LICENSE=	LGPL21

USES=		iconv jpeg libtool localbase:ldflags gmake pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--with-jpeg=yes --with-python=no --with-qt=no

OPTIONS_DEFINE=	DOCS GTK2 IMAGEMAGICK V4L X11
OPTIONS_DEFAULT=IMAGEMAGICK X11
OPTIONS_SUB=	yes
V4L_DESC=	Build zbarcam video scanner

X11_USES=	xorg
X11_USE=	XORG=ice,sm,x11,xau,xcb,xdmcp,xext,xv
X11_CONFIGURE_ON=	--with-x=yes
X11_CONFIGURE_OFF=	--with-x=no --without-xshm --without-xv

IMAGEMAGICK_LIB_DEPENDS=	libMagick++-${IMAGEMAGICK_DEFAULT}.so:graphics/ImageMagick${IMAGEMAGICK_DEFAULT}
IMAGEMAGICK_CONFIGURE_ON=	--with-imagemagick=yes
IMAGEMAGICK_CONFIGURE_OFF=	--with-imagemagick=no

# To avoid patching configure even more:
CONFIGURE_ENV+=			ac_cv_header_wand_MagickWand_h=yes

V4L_BUILD_DEPENDS=	v4l_compat>=1.0.20101027:multimedia/v4l_compat
V4L_CONFIGURE_ON=	--enable-video=yes
V4L_CONFIGURE_OFF=	--enable-video=no

GTK2_USES=	gnome
GTK2_USE=	GNOME=gtk20
GTK2_CONFIGURE_ON=	--with-gtk=yes
GTK2_CONFIGURE_OFF=	--with-gtk=no

post-patch-DOCS-off:
	@${REINPLACE_CMD} '/^install-data-am: /s/install-dist_docDATA//' \
		${WRKSRC}/Makefile.in

post-install:
	# make check-plist happy
	${RMDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
