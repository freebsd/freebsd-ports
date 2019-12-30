# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	charls
PORTVERSION=	2.1.0
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ JPEG-LS library implementation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake compiler:c++14-lang

CMAKE_ON=	BUILD_SHARED_LIBS BUILD_TESTING
USE_LDCONFIG=	yes

GH_ACCOUNT=	team-charls
USE_GITHUB=	yes

.include <bsd.port.mk>
