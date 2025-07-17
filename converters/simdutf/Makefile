PORTNAME=	simdutf
DISTVERSIONPREFIX=	v
DISTVERSION=	7.3.3
CATEGORIES=	converters textproc

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Unicode validation and transcoding with SIMD
WWW=		https://simdutf.github.io/simdutf/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cmake:testing compiler:c++17-lang pathfix python:build,test
USE_GITHUB=	yes
USE_LDCONFIG=	yes

# test suite fails on armv7 with -fno-strict-aliasing
# see https://github.com/simdutf/simdutf/issues/581
WITHOUT_NO_STRICT_ALIASING=	yes

CMAKE_TESTING_ON=	SIMDUTF_TESTS

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	SIMDUTF_TESTS

OPTIONS_DEFINE=	ICONV TOOLS
OPTIONS_DEFAULT=	ICONV TOOLS
OPTIONS_SUB=		yes

TOOLS_DESC=		Build tools

ICONV_USES=	iconv
ICONV_CMAKE_BOOL=	SIMDUTF_ICONV

TOOLS_CMAKE_BOOL=	SIMDUTF_TOOLS

.include <bsd.port.mk>
