# New ports collection makefile for:	randomshooter
# Date created:		27 Feb 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	randomshooter
DISTVERSION=	0.1-1
CATEGORIES=	games
# original url: http://parallelrealities.co.uk/download.php?proj=randomShooter&file=${DISTNAME}&type=zip
MASTER_SITES=	http://www.amdmi3.ru/distfiles/
DISTNAME=	RandomShooter-${DISTVERSION}

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	A simple shoot'em up with online scoring and replays

USE_GMAKE=	yes
USE_SDL=	sdl mixer image ttf net

WRKSRC=		${WRKDIR}/RandomShooter
PORTDOCS=	*

MAKEFILE=	makefile
MAKE_ENV=	CXX="${CXX}"
CXXFLAGS+=	-DINSTALL_DIR=\\\"${DATADIR}/\\\"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.for dir in font gfx music
	${MKDIR} ${DATADIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/* ${DATADIR}/${dir}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/help/help.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
