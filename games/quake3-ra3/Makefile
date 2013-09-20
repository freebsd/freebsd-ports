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

NO_PACKAGE=	package will be 131MB, set FORCE_PACKAGE if you really want it

USE_ZIP=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/arena
DATADIR=	${Q3DIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${DATADIR}
.for f in *.cfg *.pk3
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
