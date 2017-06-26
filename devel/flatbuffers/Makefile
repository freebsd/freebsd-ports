# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	flatbuffers
PORTVERSION=	1.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	yuri@rawbw.com
COMMENT=	Memory efficient serialization library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	google

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DFLATBUFFERS_BUILD_SHAREDLIB:BOOL="ON"

do-test:
	cd ${WRKSRC} && ${MAKE_CMD} test

.include <bsd.port.mk>
