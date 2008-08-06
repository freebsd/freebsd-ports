# New ports collection makefile for:	secretmaryochronicles-music
# Date created:		5 Aug 2008
# Whom:			Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	secretmaryochronicles-music
PORTVERSION=	4.0
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	smclone
DISTNAME=	SMC_music_${PORTVERSION}_high

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Background music for Secret Maryo Chronicles

RUN_DEPENDS=	smc:${PORTSDIR}/games/secretmaryochronicles

USE_ZIP=	yes

WRKSRC=		${WRKDIR}
DATADIR=	${PREFIX}/share/smc
NO_BUILD=	yes

do-install:
	${MKDIR} ${DATADIR}/music
	${CP} -Rv ${WRKSRC}/data/music/* ${DATADIR}/music/

.if !defined(NOPORTDOCS)
PORTDOCS=	Addon\ \-\ Music\ Readme.txt license.txt

post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
