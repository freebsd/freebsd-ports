# Created by: pat@databits.net
# $FreeBSD$

PORTNAME=	excessive
PORTVERSION=	003
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pat
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_q3_server_${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake III Arena Mod: Excessive

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		zip:infozip
NO_BUILD=	yes

DATADIR=	${Q3DIR}/${PORTNAME}

NO_STAGE=	yes
post-extract:
	@(cd ${WRKSRC}; ${UNZIP_CMD} description.pk3)

do-install:
	@${MKDIR} ${DATADIR}
.for f in description.txt motd.cfg maplist.cfg
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
	@${MKDIR} ${DATADIR}/vm
	@${INSTALL_DATA} ${WRKSRC}/vm/qagame.qvm ${DATADIR}/vm
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.mk>
