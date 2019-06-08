# Created by: Alfonso S. Siciliano <alfix86@gmail.com>
# $FreeBSD$

PORTNAME=	beret
PORTVERSION=	1.2.1
CATEGORIES=	games

MAINTAINER=	alfix86@gmail.com
COMMENT=	2D puzzle-platformer game

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/lgpl-3.0.txt

RUN_DEPENDS=	${LOCALBASE}/share/fonts/averiagwf/AveriaSansGWF-Regular.ttf:x11-fonts/averiagwf

USES=	sdl
USE_SDL=	image ttf mixer

MAKEFILE=	BSDmakefile

USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_PROJECT=	${PORTNAME}-freebsd
GL_COMMIT=	ab3c397400be60ce69903389727acf6cdf0a3119

DATADIR=	${PREFIX}/share/${PORTNAME}

DESKTOP_ENTRIES=	"Beret" \
			"2D puzzle-platformer" \
			"" \
			"beret" \
			"Game;" \
			false

PORTDOCS=	README.txt

FONT_DEP=	AveriaSansGWF-Regular.ttf
FONTDIR_DEP=	${LOCALBASE}/share/fonts/averiagwf

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/game.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/beret ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
.for datadir in images music rooms sfx
	${MKDIR} ${STAGEDIR}${DATADIR}/${datadir}
	cd ${WRKSRC}/${datadir} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${datadir}
.endfor
	cd ${STAGEDIR}${DATADIR} && ${LN} -s ${FONTDIR_DEP}/${FONT_DEP} ${FONT_DEP}

.include <bsd.port.mk>
