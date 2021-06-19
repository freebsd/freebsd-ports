PORTNAME=	hyperrogue
PORTVERSION=	12.0a
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Roguelike in a non-euclidean world

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_11=	does not build: hyperrogue-hyper.o: file not recognized: File format not recognized

LIB_DEPENDS=	libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	zenorogue

USES=		compiler:c++11-lang gl gmake localbase:ldflags sdl xorg
USE_SDL=	sdl mixer gfx ttf
USE_GL=		gl glew
ALL_TARGET=	hyperrogue

# remove -O2, otherwise clang takes gigabytes of memory
CXXFLAGS:=	${CXXFLAGS:C/-O[0-9]//} -DFHS -DHYPERPATH="\\\"${DATADIR}/\\\""

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
	@${MKDIR} ${STAGEDIR}${DATADIR}/sounds
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/hyperrogue-music.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sounds/* ${STAGEDIR}${DATADIR}/sounds
	${INSTALL_DATA} ${WRKSRC}/music/* ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
