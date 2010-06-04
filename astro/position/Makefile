# New ports collection makefile for:    position
# Date created:         21 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	position
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	astro gnustep
MASTER_SITES=	http://www.gnustep.it/enrico/position/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GPS and Moving-Map Applikation

LIB_DEPENDS=	proj:${PORTSDIR}/graphics/proj

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/Position/Position
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

post-patch:
	${REINPLACE_CMD} -e 's|UV |projUV |' \
		${WRKSRC}/Functions.m

.include <bsd.port.mk>
