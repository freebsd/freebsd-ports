# $FreeBSD$

PORTNAME=	dustrac
PORTVERSION=	2.0.3
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D top-view racing game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis

USE_GITHUB=	yes
GH_ACCOUNT=	juzzlin
GH_PROJECT=	DustRacing2D

USES=		compiler:c++11-lib cmake gl openal pkgconfig qt:5
USE_GL=		gl glu
USE_QT=		core gui opengl xml widgets testlib \
		buildtools_build linguisttools_build qmake_build
CMAKE_ARGS=	-DReleaseBuild=on \
		-DDATA_PATH=${DATADIR} \
		-DDOC_PATH=${DOCSDIR}
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

STRIP_FILES=	bin/dustrac-game \
		bin/dustrac-editor

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dustrac-*

.include <bsd.port.mk>
