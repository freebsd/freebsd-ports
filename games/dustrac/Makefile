# $FreeBSD$

PORTNAME=	dustrac
PORTVERSION=	1.7.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/src

MAINTAINER=	makc@FreeBSD.org
COMMENT=	2D top-view racing game

LIB_DEPENDS=	libvorbisfile.so:${PORTSDIR}/audio/libvorbis

USES=		compiler:c++11-lib cmake openal pkgconfig zip
USE_GL=		glu
_USE_QT4=	corelib opengl xml linguist_build \
		moc_build qmake_build rcc_build uic_build
_USE_QT5=	core opengl xml widgets \
		buildtools_build linguisttools_build qmake_build
CMAKE_ARGS=	-DReleaseBuild=on \
		-DDATA_PATH=${DATADIR} \
		-DDOC_PATH=${DOCSDIR}
LDFLAGS=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS DEBUG
OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT5

TOOLKIT_DESC=	Qt toolkit
DEBUG_CMAKE_ON=	-DDebugBuild=on
QT4_USE=	${_USE_QT4:S/^/QT4=/}
QT5_USE=	${_USE_QT5:S/^/QT5=/}
QT5_CMAKE_ON=	-DUseQt5=on
QT5_CMAKE_OFF=	-DUseQt5=off

STRIP_FILES=	bin/dustrac-game \
		bin/dustrac-editor

post-patch:
	${REINPLACE_CMD} -e '/add_subdirectory(UnitTests)/d' \
		${WRKSRC}/src/game/MiniCore/CMakeLists.txt

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}

.include <bsd.port.mk>
