PORTNAME=	vcmi
PORTVERSION=	1.7.1
CATEGORIES=	games

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open-source engine for Heroes of Might and Magic III
WWW=		https://vcmi.eu/

LICENSE=	GPLv2+

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libboost_atomic.so:devel/boost-libs \
		libfuzzylite.so:devel/fuzzylite \
		libminizip.so:archivers/minizip \
		libsquish.so:graphics/squish \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	bash:shells/bash

USES=		cmake pkgconfig sdl shebangfix
USE_GITHUB=	yes
GH_PROJECT=	innoextract:inex
GH_TAGNAME=	96e9566:inex
GH_SUBDIR=	launcher/lib/innoextract:inex
USE_SDL=	image2 mixer2 sdl2 ttf2
SHEBANG_FILES=	vcmibuilder
CMAKE_ARGS=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON \
		-DCMAKE_INSTALL_RPATH:PATH=${PREFIX}/lib/${PORTNAME} \
		-DENABLE_GITVERSION:BOOL=OFF -DENABLE_TEST:BOOL=OFF \
		-DFORCE_BUNDLED_FL:BOOL=OFF

PORTDOCS=	ChangeLog.md

OPTIONS_DEFINE=	DOCS MMAI QT
OPTIONS_DEFAULT=	QT
OPTIONS_SUB=	yes

MMAI_DESC=	Experimental machine learning-based combat AI
MMAI_LIB_DEPENDS=	libonnxruntime.so:misc/onnxruntime
MMAI_CMAKE_OFF=	-DENABLE_MMAI:BOOL=OFF

QT_DESC=	Build Qt-based game launcher and map editor
QT_USES=	qt:5
QT_USE=		QT=buildtools:build,linguisttools:build,qmake:build \
		QT=core,gui,network,svg,widgets,xml
QT_CMAKE_OFF=	-DENABLE_LAUNCHER:BOOL=OFF -DENABLE_EDITOR:BOOL=OFF

post-patch:
	@${REINPLACE_CMD} -e '/QT NAMES/s, Qt6,,' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,^target_link_libraries(vcmieditor vcmi,& pthread,' \
		${WRKSRC}/mapeditor/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,^set(vcmiservercommon_LIBS vcmi,& pthread,' \
		${WRKSRC}/server/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
