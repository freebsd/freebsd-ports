# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libopenraw
PORTVERSION=	0.0.9
CATEGORIES=	graphics
MASTER_SITES=	http://libopenraw.freedesktop.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for camera RAW files decoding

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

USES=		compiler:c++11-lang libtool pkgconfig tar:bzip2
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

post-patch:
	@${REINPLACE_CMD} -e 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|testsuite ||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
