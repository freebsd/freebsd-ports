# Created by: Rusmir Dusko <nemysis@FreeBSD.org>

PORTNAME=	megamario
PORTVERSION=	1.7
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/mmario/Mega%20Mario%20Full%20Game/Mega%20Mario%20v${PORTVERSION}%20%28Full%20Game%2C%20high%20Quality%20music%29/
DISTNAME=	MegaMario_v${PORTVERSION}_full

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Super Mario Bros 1 clone

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/licence.txt

WRKSRC=		${WRKDIR}/${DISTNAME}

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
USES=		dos2unix gl gmake sdl zip
DOS2UNIX_GLOB=	*.cpp *.h *.ini Makefile* *.txt *.desktop
USE_SDL=	sdl image mixer ttf
USE_GL=		glu
ALL_TARGET=	${PORTNAME}

pre-extract:
		@${MKDIR} ${WRKDIR}/${DISTNAME}

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CONTROLS.txt fixes_v1.7.txt readme.txt

DOCSRCDIR2=	${WRKSRC}/help
DOCSDIR2=	${DOCSDIR}/help
DOC_FILES2=	*

DOCSRCDIR3=	${WRKSRC}/screens
DOCSDIR3=	${DOCSDIR}/screens
DOC_FILES3=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/pixmaps/megamario.png|${PORTNAME}|; \
		s|Name=megamario|Name=Mega Mario|' \
		${WRKSRC}/${PORTNAME}.desktop
	@${REINPLACE_CMD} -e 's|slidebar.PNG|slidebar.png|' \
		${WRKSRC}/data/levels/Edit2/main ${WRKSRC}/data/levels/3_2/main
	@(cd ${WRKSRC}/help && ${MV} editor_R*.PNG editor_Roehren.png)
	@for i in `${FIND} ${WRKSRC} -name \*.JPG -or -name \*.PNG`; do \
		${MV} $$i `echo $$i | ${SED} -e 's/PNG/png/;s/JPG/jpg/'`; done

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} mp3music ${STAGEDIR}${DATADIR})

	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
	@${MKDIR} ${STAGEDIR}${DOCSDIR3}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${STAGEDIR}${DOCSDIR3}

.include <bsd.port.mk>
