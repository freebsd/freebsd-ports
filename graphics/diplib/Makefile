PORTNAME=	diplib
DISTVERSION=	3.4.2
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and development environment for quantitative image analysis
WWW=		https://diplib.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_aarch64=	runaway builds, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=276690

LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		cmake:testing compiler:c++14-lang gl
USE_GL=		gl glut
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	DIPlib

CXXFLAGS_powerpc64=	-mvsx
CMAKE_OFF=	DIP_BUILD_PYDIP
CMAKE_TESTING_ON=	DIP_ENABLE_DOCTEST
CMAKE_TESTING_TARGET=	check # one test fails, see https://github.com/DIPlib/diplib/issues/120

.include <bsd.port.mk>
