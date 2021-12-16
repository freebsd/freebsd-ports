PORTNAME=	irrlamb
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D physics-based puzzle game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libsqlite3.so:databases/sqlite3 \
		libpng.so:graphics/png \
		libtinyxml2.so:textproc/tinyxml2 \
		libIrrlicht.so:x11-toolkits/irrlicht \
		libode.so:devel/ode \
		libccd.so:math/libccd
BUILD_DEPENDS=	${LOCALBASE}/include/glm/vec3.hpp:math/glm

USE_GITHUB=	yes
GH_ACCOUNT=	jazztickets
GH_TUPLE:=	${GH_ACCOUNT}:cmake:6e3586a:cmake/cmake

USES=		cmake compiler:c++11-lib gl jpeg openal xorg lua:53
USE_XORG=	x11 xrandr xext xxf86vm
USE_GL=		gl
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"

LDFLAGS_i386=	-Wl,-znotext

PORTDOCS=	*
PORTDATA=	*

PLIST_FILES=	bin/irrlamb \
		share/applications/irrlamb.desktop \
		share/pixmaps/irrlamb.png

OPTIONS_DEFINE=	DOCS

post-extract:
.for bundled in glm irrlicht libccd lua tinyxml2 ode
	@${RM} -r ${WRKSRC}/src/${bundled}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/cmake/*.cmake
	@${REINPLACE_CMD} -e 's|tinyxml2/tinyxml2.h|tinyxml2.h|g' ${WRKSRC}/src/*.cpp
	@${REINPLACE_CMD} -e 's|share/games|share|g' ${WRKSRC}/deployment/${PORTNAME}

.include <bsd.port.mk>
