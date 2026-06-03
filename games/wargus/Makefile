PORTNAME=	wargus
PORTVERSION=	3.3.2
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Warcraft 2 mod for the Stratagus game engine
WWW=		https://stratagus.com/ \
		https://github.com/Wargus/wargus

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
SUB_FILES=	pkg-message

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS STORMLIB
OPTIONS_DEFAULT=STORMLIB

STORMLIB_DESC=		Support importing data from BattleNet (GoG) edition
STORMLIB_CMAKE_BOOL=	WITH_STORMLIB StormLib_FIND_REQUIRED
STORMLIB_LIB_DEPENDS=	libstorm.so:archivers/stormlib

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.6 ${STAGEDIR}${PREFIX}/share/man/man6/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/doc/changelog \
		${WRKSRC}/doc/pud-specs.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
