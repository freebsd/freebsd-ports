# New ports collection makefile for:	blinkensisters
# Date created:		26 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	blinkensisters
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	LostPixels_${PORTVERSION}_src

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Parallax-style 2D scrolling platform game

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer image ttf

WRKSRC=		${WRKDIR}/LostPixels_${PORTVERSION}

MAKE_ARGS=	CC="${CXX}"

PORTDOCS=	AUTHORS HOWTOPLAY INSTALL README SCRIPTING

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" && ${OSVERSION} >= 700000
BROKEN=		Doesn't build
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/LostPixels ${PREFIX}/bin/${PORTNAME}

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/TTF/*.ttf ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/SND/*.ogg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/GFX/*.bmp ${WRKSRC}/GFX/*.jpg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/LEVELS/*.dat ${WRKSRC}/LEVELS/*.conf \
		${WRKSRC}/LEVELS/*.bsl ${DATADIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
