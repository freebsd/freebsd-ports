# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	flatbuffers
PORTVERSION=	1.7.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	yuri@rawbw.com
COMMENT=	Memory efficient serialization library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_ARGS=	-DFLATBUFFERS_BUILD_SHAREDLIB:BOOL="ON"
TEST_TARGET=	test

.include <bsd.port.mk>
