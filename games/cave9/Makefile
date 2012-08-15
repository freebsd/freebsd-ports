# New ports collection makefile for:	cave9
# Date created:		17 Sep 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cave9
PORTVERSION=	0.3
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}_src-${PORTVERSION}
DISTFILES=	${DISTNAME}.tgz \
		${PORTNAME}_data-${DATAVER}.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Gravity cave-exploration game

DATAVER=	4

USE_GMAKE=	yes
USE_SDL=	sdl ttf image

BUILD_WRKSRC=	${WRKSRC}/src

MAKEFILE=	GNUmakefile
CFLAGS+=	-DDATADIR=\\\"${DATADIR}\\\"

PORTDOCS=	*

post-extract:
	@${MV} ${WRKDIR}/data ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cave9 ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/* ${DATADIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
