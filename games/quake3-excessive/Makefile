# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	excessive
PORTVERSION=	003
CATEGORIES=	games
MASTER_SITES=	LOCAL/pat
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_q3_server_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake III Arena Mod: Excessive

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		zip:infozip
NO_BUILD=	yes

DATADIR=	${Q3DIR}/${PORTNAME}
PORTDATA=	description.txt motd.cfg maplist.cfg vm
PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

post-extract:
	@${UNZIP_CMD} ${WRKSRC}/description.pk3 -d ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/vm
.for f in description.txt motd.cfg maplist.cfg
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/vm/qagame.qvm ${STAGEDIR}${DATADIR}/vm
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.mk>
