PORTNAME=	sdl3-imgui-filedialogs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0.0
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL3 ImGui File Dialogs Library
WWW=		https://github.com/samuelvenable/SDL3-ImGui-FileDialogs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++20-lang pkgconfig sdl

USE_GITHUB=	yes
GH_ACCOUNT=	samuelvenable
GH_PROJECT=	SDL3-ImGui-FileDialogs

USE_SDL=	sdl3

CMAKE_ARGS=	-DIFD_USE_BASIC_ICONS=ON \
		-DIFD_USE_BUILD_ALL=ON \
		-DIFD_USE_INSTALL_ALL=ON

post-install:
	${RM} ${STAGEDIR}${PREFIX}/include/*.hpp

.include <bsd.port.mk>
