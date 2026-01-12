PORTNAME=	dhewm3
DISTVERSION=	1.5.5
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

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DEDICATED SDL3 DOCS
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS DEDICATED
OPTIONS_SUB=	yes

DEDICATED_DESC=		Build dedicated server
DEDICATED_CMAKE_ON=	-DDEDICATED=ON

SDL3_DESC=	Use SDL3 instead of SDL2
SDL3_USE=	SDL=sdl3
SDL3_USE_OFF=	SDL=sdl2
SDL3_CMAKE_ON=	-DSDL2=OFF -DSDL3=ON
SDL3_CMAKE_OFF=	-DSDL2=ON -DSDL3=OFF

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
