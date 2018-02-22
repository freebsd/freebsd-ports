# Created by: Oliver Heesakkers <dev2@heesakkers.info>
# $FreeBSD$

PORTNAME=	zbar
PORTVERSION=	0.10
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	dev2@heesakkers.info
COMMENT=	ZBar barcode reader

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		iconv jpeg libtool gmake pathfix pkgconfig
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--with-jpeg=yes

OPTIONS_DEFINE=	X11 IMAGEMAGICK V4L PYTHON GTK2 QT4 DOCS
OPTIONS_DEFAULT=X11 IMAGEMAGICK
OPTIONS_SUB=	yes
V4L_DESC=	Build zbarcam video scanner

X11_USE=	XORG=ice,sm,x11,xau,xcb,xdmcp,xext,xv
X11_CONFIGURE_ON=	--with-x=yes
X11_CONFIGURE_OFF=	--with-x=no --without-xshm --without-xv

IMAGEMAGICK_LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick
IMAGEMAGICK_CONFIGURE_ON=	--with-imagemagick=yes
IMAGEMAGICK_CONFIGURE_OFF=	--with-imagemagick=no

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

QT4_USE=	QT4=gui,moc_build
QT4_CONFIGURE_ON=	--with-qt=yes
QT4_CONFIGURE_OFF=	--with-qt=no

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch-DOCS-off:
	@${REINPLACE_CMD} '/^install-data-am: /s/install-dist_docDATA//' \
		${WRKSRC}/Makefile.in

post-install:
	# make check-plist happy
	${RMDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
