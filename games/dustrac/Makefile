# $FreeBSD$

PORTNAME=	dustrac
PORTVERSION=	1.9.2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/src

MAINTAINER=	makc@FreeBSD.org
COMMENT=	2D top-view racing game

LIB_DEPENDS=	libvorbisfile.so:${PORTSDIR}/audio/libvorbis

USES=		compiler:c++11-lib cmake:outsource openal pkgconfig
USE_GL=		glu
USE_QT5=	core opengl xml widgets \
		buildtools_build linguisttools_build qmake_build
CMAKE_ARGS=	-DReleaseBuild=on \
		-DDATA_PATH=${DATADIR} \
		-DDOC_PATH=${DOCSDIR}
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

STRIP_FILES=	bin/dustrac-game \
		bin/dustrac-editor

post-patch:
	${REINPLACE_CMD} -e '/add_subdirectory(UnitTests)/d' \
		${WRKSRC}/src/game/MiniCore/CMakeLists.txt

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}

.include <bsd.port.mk>
