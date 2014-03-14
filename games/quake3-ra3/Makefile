# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	ra3
PORTVERSION=	1.76	# 1.80 exists, but is kinda goofy; 1.76 is classic
CATEGORIES=	games
MASTER_SITES=	http://games.mirrors.tds.net/pub/planetquake3/modifications/rocketarena3/
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake III Arena mod: Rocket Arena 3

USES=		zip
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/arena
DATADIR=	${Q3DIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../quake3-data/Makefile.include"

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in *.cfg *.pk3
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
