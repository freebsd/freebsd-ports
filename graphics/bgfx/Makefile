PORTNAME=	bgfx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.118.8398-407
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform, graphics API agnostic rendering library
WWW=		https://bkaradzic.github.io/bgfx/overview.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang gl localbase:ldflags xorg
USE_GL=		glu opengl
USE_XORG=	ice x11 xext sm

USE_GITHUB=	yes
GH_ACCOUNT=	bkaradzic
GH_PROJECT=	bgfx.cmake
GH_TUPLE=	bkaradzic:bgfx:5f435ea:bgfx/bgfx \
		bkaradzic:bimg:1af9054:bimg/bimg \
		bkaradzic:bx:aed1086:bx/bx

CMAKE_OFF=	BGFX_BUILD_EXAMPLES BGFX_INSTALL_EXAMPLES \
		BGFX_CUSTOM_TARGETS
CMAKE_ARGS=	-DBGFX_LIBRARY_TYPE=SHARED

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/licences

.include <bsd.port.mk>
