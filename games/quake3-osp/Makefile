# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	osp
PORTVERSION=	1.03a
CATEGORIES=	games
MASTER_SITES=	http://osp.jsmart.web.id/orangesmoothie/downloads/
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTNAME=	osp-Quake3-${PORTVERSION}_full

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake III Arena mod: OSP Tourney DM/CA/CTF

USES=		zip
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
DATADIR=	${Q3DIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.options.mk>

post-extract:
# Replace outdated README file
	@${MV} ${WRKSRC}/README.txt ${WRKSRC}/Docs

do-install:
	@${MKDIR} ${DATADIR}
.for f in *.cfg *.pk3 description.txt filters.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.for d in cfg-* locs vm
	${CP} -a ${WRKSRC}/${d} ${DATADIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Docs/*.txt ${DOCSDIR}
	${INSTALL_DATA} "${WRKSRC}/OSP Match Quick Start.txt" \
		${DOCSDIR}/osp-match-quick-start.txt
.endif

.include <bsd.port.mk>
