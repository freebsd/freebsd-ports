PORTNAME=	robin-hood-hashing
DISTVERSION=	3.11.5
PORTREVISION=	1
CATEGORIES=	devel python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast & memory efficient hashtable based on robin hood hashing for C++
WWW=		https://github.com/martinus/robin-hood-hashing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	martinus

CMAKE_OFF=	RH_STANDALONE_PROJECT
NO_ARCH=	yes

PLIST_FILES=	include/robin_hood.h \
		lib/cmake/robin_hood/robin_hood-targets.cmake \
		lib/cmake/robin_hood/robin_hoodConfig.cmake

# tests fail to build, see https://github.com/martinus/robin-hood-hashing/issues/161

.include <bsd.port.mk>
