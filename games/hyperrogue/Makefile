PORTNAME=	hyperrogue
PORTVERSION=	13.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Roguelike in a non-euclidean world
WWW=		https://roguetemple.com/z/hyper/ \
		https://github.com/zenorogue/hyperrogue

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		compiler:c++14-lang gl gmake localbase:ldflags sdl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	zenorogue
USE_SDL=	sdl mixer gfx ttf
USE_GL=		gl glew
ALL_TARGET=	hyperrogue

CXXFLAGS+=	-DFHS -DHYPERPATH="\\\"${DATADIR}/\\\""
MAKE_ENV=	HYPERROGUE_USE_PNG=1 HYPERROGUE_USE_GLEW=1

PORTDOCS=	README.md
PORTDATA=	*
PLIST_FILES=	bin/hyperrogue share/pixmaps/hyperrogue.ico

DESKTOP_ENTRIES="HyperRogue" \
		"" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"${PORTNAME}" \
		"Game;RolePlaying;" \
		""

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hyperrogue ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/hr-icon.ico ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.ico
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "*.ttf hyperrogue-music.txt sounds music" \
		${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
