PORTNAME=	vcmi
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open-source engine for Heroes of Might and Magic III
WWW=		https://vcmi.eu/

LICENSE=	GPLv2+

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libboost_atomic.so:devel/boost-libs \
		libfuzzylite.so:devel/fuzzylite \
		libluajit-5.1.so:lang/luajit \
		libminizip.so:archivers/minizip \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	bash:shells/bash

USES=		cmake sdl shebangfix
USE_GITHUB=	yes
USE_SDL=	image2 mixer2 sdl2 ttf2
SHEBANG_FILES=	vcmibuilder
CMAKE_ARGS=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON \
		-DCMAKE_INSTALL_RPATH:PATH=${PREFIX}/lib/${PORTNAME} \
		-DENABLE_GITVERSION:BOOL=OFF -DENABLE_TEST:BOOL=OFF \
		-DFORCE_BUNDLED_FL:BOOL=OFF

PORTDOCS=	AUTHORS ChangeLog README.md

OPTIONS_DEFINE=	DOCS LAUNCHER
OPTIONS_DEFAULT=LAUNCHER
OPTIONS_SUB=	yes

LAUNCHER_DESC=	Build Qt-based game launcher
LAUNCHER_USES=	qt:5
LAUNCHER_USE=	QT=buildtools:build,qmake:build,core,gui,network,widgets
LAUNCHER_CMAKE_OFF=	-DENABLE_LAUNCHER:BOOL=OFF

post-configure:
	${SED} -e 's,@GIT_SHA1@,cedc9a9,' ${WRKSRC}/Version.cpp.in \
		> ${BUILD_WRKSRC}/Version.cpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
