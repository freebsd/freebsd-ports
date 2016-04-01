# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	jigzo
PORTVERSION=	0.6.1
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://www.iua.upf.es/~mdeboer/resorama/jigzo/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OpenGL jigsaw puzzle game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL.txt

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake jpeg tar:tgz
USE_SDL=	sdl mixer
USE_GL=		gl
MAKE_ARGS=	CXX=${CXX}

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*

DESKTOP_ENTRIES="Jigzo" \
		"An OpenGL jigsaw puzzle game" \
		"" \
		"jigzo" \
		"Game;LogicGame;KidsGame;" \
		false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|int_p_NULL|NULL|g" \
		${WRKSRC}/src/Loader.cxx
.for i in font image puzzles sound
	@${REINPLACE_CMD} -e "s|${i}/|${DATADIR}/${i}/|g" \
	    ${WRKSRC}/src/main.cxx
.endfor
	@${FIND} ${WRKSRC} -name .thumbnails | ${XARGS} ${RM} -rf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "font image puzzles sound" \
		${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
