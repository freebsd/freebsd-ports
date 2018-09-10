# Created by: Alfonso S. Siciliano <alfix86@gmail.com>
# $FreeBSD$

PORTNAME=	beret
PORTVERSION=	1.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	alfix86@gmail.com
COMMENT=	2D puzzle-platformer game

LICENSE=	LGPL3

RUN_DEPENDS=	${LOCALBASE}/share/fonts/averiagwf/AveriaSansGWF-Regular.ttf:x11-fonts/averiagwf

USE_GITHUB=	yes
GH_ACCOUNT=	alfonsosiciliano
GH_PROJECT=	beret-freebsd

USE_SDL=	sdl image ttf mixer
MAKEFILE=	BSDmakefile

WORKINGSRC=	${WRKDIR}/${GH_PROJECT}-${PORTVERSION}
DATADIR=	${PREFIX}/share/${PORTNAME}

DESKTOP_ENTRIES="Beret" "" "beret" \
		"beret" "" false

PORTDOCS=	README.txt

FONT_DEP=	AveriaSansGWF-Regular.ttf
FONTDIR_DEP=	${LOCALBASE}/share/fonts/averiagwf

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/game.c

do-install:
	${INSTALL_PROGRAM} ${WORKINGSRC}/beret ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WORKINGSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
.for datadir in images music rooms sfx
	${MKDIR} ${STAGEDIR}${DATADIR}/${datadir}
	cd ${WORKINGSRC}/${datadir} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${datadir}
.endfor
	cd ${STAGEDIR}${DATADIR} && ${LN} -s ${FONTDIR_DEP}/${FONT_DEP} ${FONT_DEP}

.include <bsd.port.mk>
