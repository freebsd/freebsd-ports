PORTNAME=	bgfx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.128.8777-475
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform, graphics API agnostic rendering library
WWW=		https://bkaradzic.github.io/bgfx/overview.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang gl localbase:ldflags xorg
USE_GL=		glu opengl
USE_XORG=	ice x11 xext sm

USE_GITHUB=	yes
GH_ACCOUNT=	bkaradzic
GH_PROJECT=	bgfx.cmake
GH_TUPLE=	bkaradzic:bgfx:af12904d8c91ab143407e8370aa220eedeafbbfa:bkaradzic_bgfx/bgfx \
		bkaradzic:bx:e7ede513dc8b90386960587e348c73b241f7735d:bkaradzic_bx/bx \
		bkaradzic:bimg:2afa64c14c1e3dd5d28412ee03bee0dfe7242f03:bkaradzic_bimg/bimg

CMAKE_OFF=	BGFX_BUILD_EXAMPLES BGFX_INSTALL_EXAMPLES \
		BGFX_CUSTOM_TARGETS
CMAKE_ARGS=	-DBGFX_LIBRARY_TYPE=SHARED
CMAKE_TESTING_ON=	BGFX_BUILD_TESTS # 1 test fails, see https://github.com/bkaradzic/bgfx/issues/3123

CXXFLAGS+=	-Dftello64=ftello -Dfseeko64=fseeko

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/licences

.include <bsd.port.mk>
