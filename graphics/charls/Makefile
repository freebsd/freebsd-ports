PORTNAME=	charls
PORTVERSION=	2.4.2
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ JPEG-LS library implementation
WWW=		https://github.com/team-charls/charls

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake compiler:c++14-lang

CMAKE_ON=	BUILD_SHARED_LIBS BUILD_TESTING
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	team-charls
USE_GITHUB=	yes

.include <bsd.port.mk>
