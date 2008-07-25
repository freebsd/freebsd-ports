# New ports collection makefile for:	randomshooter
# Date created:		27 Feb 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	randomshooter
DISTVERSION=	0.4-1
CATEGORIES=	games
# original url: http://parallelrealities.co.uk/download.php?proj=randomShooter&file=${DISTNAME}&type=zip
MASTER_SITES=	http://www.amdmi3.ru/distfiles/
DISTNAME=	randomshooter-${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A simple shoot'em up with online scoring and replays

USE_GMAKE=	yes
USE_SDL=	sdl mixer image ttf net

WRKSRC=		${WRKDIR}/${DISTNAME:S/-1$$//}
PORTDOCS=	*

MAKEFILE=	makefile
MAKE_ENV=	DATADIR=${DATADIR}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.for dir in font gfx help music
	${MKDIR} ${DATADIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/* ${DATADIR}/${dir}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/help/help.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
