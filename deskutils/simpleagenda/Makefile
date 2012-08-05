# New ports collection makefile for:    simpleagenda
# Date created:         16 Jan 2009
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	simpleagenda
PORTVERSION=	0.42
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://coyote.octets.fr/pub/gnustep/
DISTNAME=	SimpleAgenda-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	simple calendar and agenda application

LIB_DEPENDS+=	ical:${PORTSDIR}/devel/libical

LICENSE=	GPLv2

BROKEN=		does not build

USE_GNUSTEP=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
ADDITIONAL_OBJCFLAGS=	'-Dsel_isEqual(x,y) (x==y)'

pre-configure:
	${REINPLACE_CMD} -e 's|SimpleAgenda|SimpleAgenda.m|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-luuid||' ${WRKSRC}/GNUmakefile.preamble

.include <bsd.port.mk>
