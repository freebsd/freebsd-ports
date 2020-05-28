# $FreeBSD$

PORTNAME=	simpleagenda
PORTVERSION=	0.43
PORTREVISION=	11
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://coyote.octets.fr/pub/gnustep/
DISTNAME=	SimpleAgenda-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple calendar and agenda application

LIB_DEPENDS+=	libical.so:devel/libical \
		libuuid.so:misc/e2fsprogs-libuuid

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include

pre-configure:
	${REINPLACE_CMD} -e 's|SimpleAgenda|SimpleAgenda.m|' ${WRKSRC}/configure

.include <bsd.port.mk>
