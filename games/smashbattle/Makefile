# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	smashbattle
PORTVERSION=	110224
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/beta-${PORTVERSION}
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	nemysis@gmx.ch
COMMENT=	8-bit style platform battle game

WRKSRC=		${WRKDIR}/${DISTNAME}/battle/Battle

USE_ZIP=	yes
EXTRACT_AFTER_ARGS=	-d ${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
USE_DOS2UNIX=	*.cpp *.h *.ini Makefile
ALL_TARGET=	battle
USE_SDL=	sdl image mixer

NO_STAGE=	yes
pre-extract:
	@${MKDIR} ${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/applications/${PORTNAME}fs.desktop \
		share/pixmaps/${PORTNAME}.png
PLIST_DIRSTRY=	share/applications

PORTDATA=	*

SUB_FILES=	${PORTNAME}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/games/smashbattle/gfx/SB.png|${PORTNAME}|' \
		-e 's|/usr/local/bin/smashbattle|${PORTNAME}|' \
		${WRKSRC}/linux/${PORTNAME}.desktop ${WRKSRC}/linux/${PORTNAME}fs.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/battle ${DATADIR}/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "gfx music sfx stage" ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/gfx/SB.png ${PREFIX}/share/pixmaps/${PORTNAME}.png
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/linux/${PORTNAME}.desktop ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/linux/${PORTNAME}fs.desktop ${PREFIX}/share/applications/

.include <bsd.port.mk>
