# New ports collection makefile for:	libopenraw
# Date created:				21 Mar 2007
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libopenraw
PORTVERSION=	0.0.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://libopenraw.freedesktop.org/download/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Library for camera RAW files decoding

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GNOME=	#
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

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

.include <bsd.port.post.mk>
