PORTNAME=	shadered
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.6
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight, cross-platform & full-featured shader IDE
WWW=		https://shadered.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glm>0:math/glm
LIB_DEPENDS=	\
		libinotify.so:devel/libinotify

USES=		cmake:insource compiler:c++17-lang gl localbase:ldflags pkgconfig python:build sdl # outsource build fails, see https://github.com/dfranx/SHADERed/issues/303
USE_GL=		glew glu opengl
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	dfranx
GH_PROJECT=	SHADERed
GH_TUPLE=	dfranx:assimp:2012451:assimp/libs/assimp \
		dfranx:imgui:b29c8de:imgui/libs/imgui \
		dfranx:ImGuiColorTextEdit:fb08648:ImGuiColorTextEdit/libs/ImGuiColorTextEdit \
		dfranx:SpvGenTwo:5fba6bd:SpvGenTwo/libs/SpvGenTwo \
		dfranx:ShaderExpressionParser:2f9cb35:ShaderExpressionParser/libs/ShaderExpressionParser \
		dfranx:SPIRV-VM:439434f:spirv_vm/libs/SPIRV-VM \
		KhronosGroup:glslang:c594de2:glslang/libs/glslang \
		zeux:pugixml:40be014:pugixml/libs/pugixml

LDFLAGS+=	-linotify

post-install: # workaround for https://github.com/dfranx/SHADERed/issues/304
	${RM} -r \
		${STAGEDIR}${PREFIX}/include \
		${STAGEDIR}${PREFIX}/lib \
		${STAGEDIR}${PREFIX}/libdata

.include <bsd.port.mk>
