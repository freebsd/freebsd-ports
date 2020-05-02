# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	teeworlds
PORTVERSION=	0.7.5
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Platform game featuring buggers equipped with weapons

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.txt

USE_GITHUB=	yes
GH_TUPLE=	teeworlds:teeworlds-translation:4ed69dd:translations/datasrc/languages \
		teeworlds:teeworlds-maps:1d3401a:maps/datasrc/maps

USES=		cmake cpe pkgconfig python ssl
USE_CSTD=	c99
CPE_VERSION=	${PORTVERSION:C/^0\.//}
CMAKE_ARGS=	-DPYTHON_EXECUTABLE="${PYTHON_CMD}"

PLIST_FILES=	bin/${PORTNAME}_srv
PORTDATA=	*

OPTIONS_DEFINE=		CLIENT TEST
OPTIONS_DEFAULT=	CLIENT TEST

CLIENT_DESC=		Build game client
CLIENT_CMAKE_BOOL=	CLIENT
CLIENT_USES=		gl sdl xorg
CLIENT_USE=		GL=gl XORG=x11 SDL=sdl2
CLIENT_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libwavpack.so:audio/wavpack \
			libpnglite.so:graphics/pnglite
CLIENT_PLIST_FILES=	bin/${PORTNAME}

TEST_BUILD_DEPENDS=	googletest>=0:devel/googletest
TEST_TEST_TARGET=	run_tests

post-extract:
	@${RM} -r ${WRKSRC}/src/engine/external/wavpack
	@${RM} -r ${WRKSRC}/src/engine/external/pnglite
	@${RM} -r ${WRKSRC}/src/engine/external/zlib

post-patch:
	@${REINPLACE_CMD} -e '/find_package.*Git/ d' ${WRKSRC}/CMakeLists.txt

post-patch-CLIENT-off:
	@${REINPLACE_CMD} -e '/find_package.*Pnglite/ d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/find_package.*Wavpack/ d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/find_package.*SDL2/ d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/find_package.*Freetype/ d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/find_package.*OpenGL/ d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/find_package.*X11/ d' ${WRKSRC}/CMakeLists.txt

post-patch-TEST-off:
	@${REINPLACE_CMD} -e '/find_package.*GTest/ d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
