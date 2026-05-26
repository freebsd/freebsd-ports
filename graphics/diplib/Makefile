PORTNAME=	diplib
DISTVERSION=	3.6.0
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and development environment for quantitative image analysis
WWW=		https://diplib.org/ \
		https://github.com/DIPlib/diplib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libglfw.so:graphics/glfw
TEST_DEPENDS=	doctest>0:devel/doctest

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

# tests as of 3.6.0:
# [doctest] test cases:  104 |  104 passed | 0 failed | 0 skipped
# [doctest] assertions: 3686 | 3686 passed | 0 failed |
# [doctest] Status: SUCCESS!

.include <bsd.port.mk>
