# Created by: Patrick Li <pat@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ut
PORTVERSION=	3.7
CATEGORIES=	games
MASTER_SITES=	http://bigfoot.morphos-team.net/misc/Quake3Mods/
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTNAME=	UrbanTerror${PORTVERSION:S/.//}_full

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake III Arena mod: Urban Terror

USES=		gmake zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${Q3DIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../quake3-data/Makefile.include"

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.pk3 description.txt \
		 ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} beta3.html radio_commands.txt \
		readme*.txt ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
