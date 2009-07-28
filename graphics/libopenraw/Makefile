# New ports collection makefile for:	libopenraw
# Date created:				21 Mar 2007
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libopenraw
PORTVERSION=	0.0.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://libopenraw.freedesktop.org/download/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Library for camera RAW files decoding

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		jpeg.10:${PORTSDIR}/graphics/jpeg

MAKE_JOBS_SAFE=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include

OPTIONS=	GNOME "GNOME support (needs gtk20)" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GNOME)
USE_GNOME=	gtk20
PLIST_SUB+=	GNOME=""
.else
CONFIGURE_ARGS+=--disable-gnome
PLIST_SUB+=	GNOME="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|testsuite ||' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
