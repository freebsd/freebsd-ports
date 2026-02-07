PORTNAME=	imtui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.5-30
DISTVERSIONSUFFIX=	-g72f3722
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Immediate Mode Text-based User Interface C++ Library
WWW=		https://github.com/ggerganov/imtui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ggerganov
GH_TUPLE=	ggerganov:imgui:d413be8:imgui/third-party/imgui/imgui

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	IMTUI_BUILD_EXAMPLES

.include <bsd.port.mk>
