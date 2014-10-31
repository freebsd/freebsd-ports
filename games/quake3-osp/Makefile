# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	osp
PORTVERSION=	1.03a
CATEGORIES=	games
MASTER_SITES=	http://osp.dget.cc/orangesmoothie/downloads/
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-Quake3-${PORTVERSION}_full

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake III Arena mod: OSP Tourney DM/CA/CTF

USES=		zip
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
DATADIR=	${Q3DIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.options.mk>

post-extract:
# Replace outdated README file
	@${MV} ${WRKSRC}/README.txt ${WRKSRC}/Docs

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in *.cfg *.pk3 description.txt filters.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
.for d in cfg-* locs vm
	${CP} -a ${WRKSRC}/${d} ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Docs/*.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} "${WRKSRC}/OSP Match Quick Start.txt" \
		${STAGEDIR}${DOCSDIR}/osp-match-quick-start.txt

.include <bsd.port.mk>
