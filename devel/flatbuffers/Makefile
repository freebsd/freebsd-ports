# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	flatbuffers
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Memory efficient serialization library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_ARGS=	-DFLATBUFFERS_BUILD_SHAREDLIB:BOOL="ON"
TEST_TARGET=	test
PLIST_SUB=	SHLIB_VER=${PORTVERSION}

.include <bsd.port.mk>
