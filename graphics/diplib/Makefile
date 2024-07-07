PORTNAME=	diplib
DISTVERSION=	3.5.1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and development environment for quantitative image analysis
WWW=		https://diplib.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_aarch64=	runaway builds, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=276690
BROKEN_i386=	compilation fails: constructor cannot be redeclared, see https://github.com/DIPlib/diplib/issues/162

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

CFLAGS_i386=	-msse2 # fix build failure: error: always_inline function '_mm_setzero_si128' requires target feature 'sse2', but would be inlined into function 'defilter_sub4' that is compiled without support for 'sse2'
CXXFLAGS_i386=	-msse2

.include <bsd.port.mk>
