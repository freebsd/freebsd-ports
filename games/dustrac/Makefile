PORTNAME=	dustrac
PORTVERSION=	2.2.0
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D top-view racing game
WWW=		https://dustrac.sourceforge.net/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vulkan-headers>=0:graphics/vulkan-headers
LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans-Bold.ttf:x11-fonts/dejavu

USE_GITHUB=	yes
GH_ACCOUNT=	juzzlin
GH_PROJECT=	DustRacing2D

USES=		compiler:c++11-lib cmake gl openal pkgconfig qt:6
USE_GL=		gl glu
USE_QT=		base tools:build
CMAKE_OFF=	USE_CCACHE
CMAKE_ON=	ReleaseBuild \
		SystemFonts
CMAKE_ARGS=	-DDATA_PATH=${DATADIR} \
		-DDOC_PATH=${DOCSDIR}
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dustrac-editor

.include <bsd.port.mk>
