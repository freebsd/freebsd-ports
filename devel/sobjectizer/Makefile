PORTNAME=	sobjectizer
PORTVERSION=	5.8.5
CATEGORIES=	devel
MASTER_SITES=	https://github.com/Stiffstream/${PORTNAME}/releases/download/v${PORTVERSION}/
DISTNAME=	so-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cross-platform C++ actor framework
WWW=		https://stiffstream.com/en/products/sobjectizer.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		cmake:testing compiler:c++17-lang tar:xz
CMAKE_OFF=	SOBJECTIZER_BUILD_STATIC
CMAKE_TESTING_ON=	BUILD_TESTS

WRKSRC_SUBDIR=	dev

.include <bsd.port.mk>
