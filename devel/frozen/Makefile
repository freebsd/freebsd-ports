PORTNAME=	frozen
PORTVERSION=	1.2.0
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Header-only, constexpr alternative to gperf for C++14 users
WWW=		https://github.com/serge-sans-paille/frozen

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++14-lang

CMAKE_OFF=	frozen.benchmark \
		frozen.coverage \
		frozen.tests
CMAKE_ON=	frozen.installation
CMAKE_TESTING_ON=	frozen.tests
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	serge-sans-paille

.include <bsd.port.mk>
