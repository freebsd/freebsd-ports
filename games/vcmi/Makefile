PORTNAME=	vcmi
PORTVERSION=	1.2.1
CATEGORIES=	games

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	c7bee037d2c06c56893d631651288c33e.patch:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open-source engine for Heroes of Might and Magic III
WWW=		https://vcmi.eu/

LICENSE=	GPLv2+

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libboost_atomic.so:devel/boost-libs \
		libfuzzylite.so:devel/fuzzylite \
		libminizip.so:archivers/minizip \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	bash:shells/bash

USES=		cmake pkgconfig sdl shebangfix
USE_GITHUB=	yes
USE_SDL=	image2 mixer2 sdl2 ttf2
SHEBANG_FILES=	vcmibuilder
CMAKE_ARGS=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON \
		-DCMAKE_INSTALL_RPATH:PATH=${PREFIX}/lib/${PORTNAME} \
		-DENABLE_GITVERSION:BOOL=OFF -DENABLE_TEST:BOOL=OFF \
		-DFORCE_BUNDLED_FL:BOOL=OFF

PORTDOCS=	AUTHORS ChangeLog.md README.md

OPTIONS_DEFINE=	DOCS QT
OPTIONS_DEFAULT=	QT
OPTIONS_SUB=	yes

QT_DESC=	Build Qt-based game launcher and map editor
QT_USES=	qt:5
QT_USE=		QT=buildtools:build,linguisttools:build,qmake:build \
		QT=core,gui,network,widgets
QT_CMAKE_OFF=	-DENABLE_LAUNCHER:BOOL=OFF -DENABLE_EDITOR:BOOL=OFF

post-configure:
	${SED} -e 's,@GIT_SHA1@,c125e04,' ${WRKSRC}/Version.cpp.in \
		> ${BUILD_WRKSRC}/Version.cpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

PATCH_ARGS+=	-l
