# Created by: Travis Poppe <tlp@liquidx.org>

PORTNAME=	wargus
PORTVERSION=	3.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Warcraft 2 mod for the Stratagus game engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	stratagus:games/stratagus \
		cdparanoia:audio/cdparanoia \
		ffmpeg:multimedia/ffmpeg
BUILD_DEPENDS=	stratagus:games/stratagus
LIB_DEPENDS=	libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	Wargus

USES=		cmake compiler:c++11-lang pkgconfig
CMAKE_ARGS=	-DGAMEDIR:STRING="bin" \
		-DSHAREDIR:STRING="${DATADIR_REL}"
CMAKE_OFF=	WITH_STORMLIB  # not in ports
SUB_FILES=	pkg-message

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.6 ${STAGEDIR}${MAN6PREFIX}/share/man/man6/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/doc/changelog \
		${WRKSRC}/doc/pud-specs.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
