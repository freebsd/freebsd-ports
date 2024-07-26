PORTNAME=	dhewm3
DISTVERSION=	1.5.4
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Doom 3 GPL source port
WWW=		https://dhewm3.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/../COPYING.txt

LIB_DEPENDS=	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	dhewm

USES=		cmake compiler:c++11-lang openal:al sdl
USE_CXXSTD=	c++14
USE_SDL=	sdl2
CMAKE_ON=	REPRODUCIBLE_BUILD

LDFLAGS_i386=	-Wl,-znotext

WRKSRC_SUBDIR=	neo

SUB_FILES=	pkg-message

PORTDOCS=	*

DESKTOP_ENTRIES="dhewm 3" \
		"" \
		"doom3" \
		"${PORTNAME}" \
		"Game;ActionGame;" \
		""

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DEDICATED DOCS
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS DEDICATED
OPTIONS_SUB=	yes

DEDICATED_DESC=		Build dedicated server
DEDICATED_CMAKE_ON=	-DDEDICATED=ON

post-patch-OPTIMIZED_CFLAGS-off:
	@${REINPLACE_CMD} -e 's|-O3 -ffast-math -fno-unsafe-math-optimizations -fomit-frame-pointer||' ${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/base
	@${MKDIR} ${STAGEDIR}${DATADIR}/d3xp
	${INSTALL_DATA} ${WRKSRC}/sys/linux/setup/image/doom3.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
