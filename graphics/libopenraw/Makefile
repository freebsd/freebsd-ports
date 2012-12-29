# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libopenraw
PORTVERSION=	0.0.8
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://libopenraw.freedesktop.org/download/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Library for camera RAW files decoding

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		jpeg.11:${PORTSDIR}/graphics/jpeg

MAKE_JOBS_SAFE=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include

OPTIONS_DEFINE=	GNOME
OPTIONS_DEFAULT=	GNOME

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME=	gtk20
PLIST_SUB+=	GNOME=""
.else
CONFIGURE_ARGS+=--disable-gnome
PLIST_SUB+=	GNOME="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|testsuite ||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
