PORTNAME=	bgfx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.124.8664-461
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
GH_TUPLE=	bkaradzic:bgfx:03a2c26:bgfx/bgfx \
		bkaradzic:bimg:678b750:bimg/bimg \
		bkaradzic:bx:03fd6f4:bx/bx

CMAKE_OFF=	BGFX_BUILD_EXAMPLES BGFX_INSTALL_EXAMPLES \
		BGFX_CUSTOM_TARGETS
CMAKE_ARGS=	-DBGFX_LIBRARY_TYPE=SHARED
CMAKE_TESTING_ON=	BGFX_BUILD_TESTS # 1 test fails, see https://github.com/bkaradzic/bgfx/issues/3123

CXXFLAGS+=	-Dftello64=ftello -Dfseeko64=fseeko

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/licences

.include <bsd.port.mk>
