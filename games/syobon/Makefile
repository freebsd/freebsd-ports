# New Ports collection makefile for:	Syobon Action
# Date created:		2012-05-06
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	syobon
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	http://download.zapek.com/software/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	_src.tar.gz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Syobon Action is a platform game as Super Mario Bros

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
USE_DOS2UNIX=	*.txt
ALL_TARGET=	${PORTNAME}
USE_SDL=	sdl gfx image mixer ttf
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.txt
PORTDATA=	*

MAKE_ENV=	GAMEDATA="${DATADIR}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "BGM SE res" ${DATADIR})
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
