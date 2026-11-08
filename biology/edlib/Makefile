PORTNAME=	edlib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.7
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast C++ library for sequence alignment using edit distance
WWW=		https://github.com/Martinsos/edlib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Martinsos

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	EDLIB_BUILD_EXAMPLES
CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM:STRING=3.5 # CMake 4 compatibility, see https://github.com/Martinsos/edlib/issues/242

.include <bsd.port.mk>
