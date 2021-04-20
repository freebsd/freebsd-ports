PORTNAME=	dustrac
PORTVERSION=	2.1.1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D top-view racing game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans-Bold.ttf:x11-fonts/dejavu

USE_GITHUB=	yes
GH_ACCOUNT=	juzzlin
GH_PROJECT=	DustRacing2D
GH_TAGNAME=	ae380b8  # includes crash fix

USES=		compiler:c++11-lib cmake gl openal pkgconfig qt:5
USE_GL=		gl glu
USE_QT=		core gui opengl xml widgets testlib sql \
		buildtools_build linguisttools_build qmake_build
CMAKE_ARGS=	-DReleaseBuild=on \
		-DSystemFonts=on \
		-DDATA_PATH=${DATADIR} \
		-DDOC_PATH=${DOCSDIR}
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dustrac-editor

.include <bsd.port.mk>
