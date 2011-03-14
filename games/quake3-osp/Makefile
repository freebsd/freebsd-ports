# New ports collection makefile for:	Q3 Mod: OSP Tourney DM/CA/CTF
# Date created:				Mon Jun  4 16:20:32 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	osp
PORTVERSION=	1.03a
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTNAME=	osp-Quake3-${PORTVERSION}_full

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake III Arena Mod: OSP Tourney DM/CA/CTF

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	yes
USE_CRLF=	yes
NO_BUILD=	yes

DATADIR=	${Q3DIR}/${PORTNAME}

do-install:
	@${MKDIR} ${DATADIR}
.for f in *.cfg *.pk3 description.txt filters.txt
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.for d in cfg-GfxExample locs vm
	@${CP} -R ${WRKSRC}/${d} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Docs/*.txt ${DOCSDIR}
	@${INSTALL_DATA} "${WRKSRC}/OSP Match Quick Start.txt" \
		${DOCSDIR}/osp-match-quick-start.txt
.endif

.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.mk>
