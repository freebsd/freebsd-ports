# New ports collection makefile for:   mono
# Date created:        22 July 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mono
PORTVERSION=	0.12
CATEGORIES=	lang
MASTER_SITES=	http://www.go-mono.com/archive/

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	glib-2.0.0:${PORTSDIR}/devel/glib20 \
		gc.1:${PORTSDIR}/devel/boehm-gc

USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include " \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		mcs.1 mint.1 mono.1 monoburg.1 monodis.1 monostyle.1

pre-patch:
		@find ${WRKSRC} -name Makefile.in | xargs ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'
		@find ${WRKSRC}/mono -name *.c | xargs ${REINPLACE_CMD} -e \
		's|gc/gc.h|'${LOCALBASE}/'include/gc.h|g'

.include <bsd.port.mk>
