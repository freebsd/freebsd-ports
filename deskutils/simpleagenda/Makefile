# New ports collection makefile for:    simpleagenda
# Date created:         16 Jan 2009
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	simpleagenda
PORTVERSION=	0.41
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://coyote.octets.fr/pub/gnustep/
DISTNAME=	SimpleAgenda-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	simple calendar and agenda application

LIB_DEPENDS+=	ical:${PORTSDIR}/devel/libical

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

pre-configure:
	${REINPLACE_CMD} -e 's|SimpleAgenda|SimpleAgenda.m|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-luuid||' ${WRKSRC}/GNUmakefile.preamble

.include <bsd.port.mk>
