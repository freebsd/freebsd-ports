# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	magicmaze
PORTVERSION=	1.4.3.6
PORTREVISION=	1
CATEGORIES=	games ruby
MASTER_SITES=	RUBYFORGE
DISTNAME=	${PORTNAME}-${DISTVERSION:S/./_/g}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple and low-tech monster-bashing maze game

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-22

LICENSE=	GPLv2

RUN_DEPENDS=	ruby18-sdl>=1.3:${PORTSDIR}/devel/ruby-sdl

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/./_/g}

USE_SDL=	sdl image mixer
USE_RUBY=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	*
PORTDOCS=	*

SUB_FILES=	${PORTNAME}
SUB_LIST=	RUBY=${RUBY}

DESKTOP_ENTRIES="Magic Maze" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.rb ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data magicmaze" ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/data/gfx/icon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${WRKSRC}/doc/BUGS.TXT ${WRKSRC}/doc/TODO.TXT ${DOCSDIR}
.endif

.include <bsd.port.mk>
