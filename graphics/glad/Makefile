# $FreeBSD$

PORTNAME=	glad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.33
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-Language Vulkan/GL/GLES/EGL/GLX/WGL loader-generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Dav1dde
USE_LDCONFIG=	yes

CMAKE_ON=	GLAD_INSTALL BUILD_SHARED_LIBS GLAD_REPRODUCIBLE

CONFLICTS_INSTALL=	mesa-libs # include/KHR/khrplatform.h, see https://github.com/Dav1dde/glad/issues/260

.include <bsd.port.mk>
