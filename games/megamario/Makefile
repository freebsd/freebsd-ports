# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	megamario
PORTVERSION=	1.7
CATEGORIES=	games
MASTER_SITES=	SF/mmario/Mega%20Mario%20Full%20Game/Mega%20Mario%20v${PORTVERSION}%20%28Full%20Game%2C%20high%20Quality%20music%29/
DISTNAME=	MegaMario_v${PORTVERSION}_full

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Super Mario Bros 1 clone

LICENSE=	LGPL21

WRKSRC=		${WRKDIR}/${DISTNAME}

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
USES=		dos2unix gmake zip:infozip
DOS2UNIX_FILES=	src/*.cpp src/*.h *.ini Makefile* *.txt *.desktop
USE_SDL=	sdl image mixer ttf
USE_GL=		glu
ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

pre-extract:
		${MKDIR} ${WRKDIR}/${DISTNAME}

PORTDOCS=	CONTROLS.txt linux.txt readme.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/pixmaps/megamario.png|${PORTNAME}|' \
		-e 's|Name=megamario|Name=Mega Mario|' \
		${WRKSRC}/${PORTNAME}.desktop
	@${REINPLACE_CMD} -e 's|slidebar.PNG|slidebar.png|' \
		${WRKSRC}/data/levels/Edit2/main ${WRKSRC}/data/levels/3_2/main
	@(cd ${WRKSRC}/help && ${MV} editor_R*.PNG editor_Roehren.png)
	@for i in `${FIND} ${WRKSRC} -name \*.JPG -or -name \*.PNG`; do \
		${MV} $$i `echo $$i | ${SED} -e 's/PNG/png/;s/JPG/jpg/'`; done

post-install:
.for d in help mp3music screens
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
