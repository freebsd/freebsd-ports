# New Ports collection makefile for:	Syobon Action
# Date created:		2012-05-06
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	syobon
PORTVERSION=	1.0.1
PORTREVISION=	1
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

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.txt
PORTDATA=	*

MAKE_ENV=	GAMEDATA="${DATADIR}"

.include <bsd.port.options.mk>

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Data
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "BGM SE res" ${DATADIR})

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
