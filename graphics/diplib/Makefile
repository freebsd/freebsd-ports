PORTNAME=	diplib
DISTVERSION=	3.4.1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and development environment for quantitative image analysis
WWW=		https://diplib.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		cmake:testing gl
USE_GL=		gl glut
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	DIPlib

CXXFLAGS_powerpc64=	-mvsx
CMAKE_OFF=	DIP_BUILD_PYDIP
CMAKE_TESTING_ON=	DIP_ENABLE_DOCTEST
CMAKE_TESTING_TARGET=	check # one test fails, see https://github.com/DIPlib/diplib/issues/120

.include <bsd.port.mk>
