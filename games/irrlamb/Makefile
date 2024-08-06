PORTNAME=	irrlamb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.5
CATEGORIES=	games
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D physics-based puzzle game
WWW=		https://gitlab.com/irrlamb/code

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libpng.so:graphics/png \
		libtinyxml2.so:textproc/tinyxml2 \
		libIrrlicht.so:x11-toolkits/irrlicht \
		libode.so:devel/ode \
		libccd.so:math/libccd
BUILD_DEPENDS=	${LOCALBASE}/include/glm/vec3.hpp:math/glm

USES=		cmake compiler:c++11-lib gl jpeg openal sqlite xorg lua:53
USE_GITLAB=	yes
GL_ACCOUNT=	irrlamb
GL_PROJECT=	code
GL_TUPLE=	jazztickets:cmake:486362ce74eaf6b26067576a8b6b03dcad27a7a5:cmake/cmake
USE_XORG=	x11 xrandr xext xxf86vm
USE_GL=		gl
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"

LDFLAGS_i386=	-Wl,-znotext

CXXFLAGS+=	-DGLM_ENABLE_EXPERIMENTAL  # GLM_GTX_rotate_vector is an experimental extension

PORTDOCS=	*
PORTDATA=	*

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
