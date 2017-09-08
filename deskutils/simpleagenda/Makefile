# $FreeBSD$

PORTNAME=	simpleagenda
PORTVERSION=	0.43
PORTREVISION=	6
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://coyote.octets.fr/pub/gnustep/
DISTNAME=	SimpleAgenda-${PORTVERSION}

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	simple calendar and agenda application

LIB_DEPENDS+=	libical.so:devel/libical

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include

pre-configure:
	${REINPLACE_CMD} -e 's|SimpleAgenda|SimpleAgenda.m|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-luuid||' ${WRKSRC}/GNUmakefile.preamble

.include <bsd.port.mk>
