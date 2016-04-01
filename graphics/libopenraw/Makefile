# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libopenraw
PORTVERSION=	0.0.9
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://libopenraw.freedesktop.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for camera RAW files decoding

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		compiler:c++11-lang jpeg libtool pkgconfig tar:bzip2
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include

OPTIONS_DEFINE=	GNOME
OPTIONS_DEFAULT=	GNOME

OPTIONS_SUB=	yes
GNOME_CONFIGURE_ENABLE=	gnome
GNOME_USE=	GNOME=glib20,gdkpixbuf2

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|testsuite ||' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopenraw.so
.if ${PORT_OPTIONS:MGNOME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopenrawgnome.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gdk-pixbuf-2.0/${GTK2_VERSION}/loaders/libopenraw_pixbuf.so
.endif

.include <bsd.port.mk>
