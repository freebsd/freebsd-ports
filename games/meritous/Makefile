# New ports collection makefile for:	meritous
# Date created:		24 Nov 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	meritous
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.asceai.net/files/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_v${PORTVERSION:C/\.//}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Action-adventure dungeon crawl game

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer image
ALL_TARGET=	default
USE_DOS2UNIX=	dat/d/helpfile.txt
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|dat/|${DATADIR}/|' ${WRKSRC}/src/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/meritous ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/dat && ${COPYTREE_SHARE} \* ${DATADIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
