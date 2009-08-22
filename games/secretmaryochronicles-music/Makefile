# New ports collection makefile for:	secretmaryochronicles-music
# Date created:		5 Aug 2008
# Whom:			Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	secretmaryochronicles-music
PORTVERSION=	4.0
CATEGORIES=	games
MASTER_SITES=	SF/smclone/Addon%20-%20Music/${PORTVERSION}
DISTNAME=	SMC_music_${PORTVERSION}_high

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Background music for Secret Maryo Chronicles

RUN_DEPENDS=	smc:${PORTSDIR}/games/secretmaryochronicles

USE_ZIP=	yes

WRKSRC=		${WRKDIR}
DATADIR=	${PREFIX}/share/smc
NO_BUILD=	yes

post-patch:
# The pointyhat build system doesn't like spaces in $PORTDOCS,
# so this makes it happier
	${MV} ${WRKSRC}/docs/Addon\ -\ Music\ Readme.txt \
		${WRKSRC}/docs/Addon_-_Music_Readme.txt

do-install:
	cd ${WRKSRC}/data && \
		${FIND} music | ${CPIO} -pdmvu ${DATADIR}

.if !defined(NOPORTDOCS)
PORTDOCS=	Addon_-_Music_Readme.txt license.txt

post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
