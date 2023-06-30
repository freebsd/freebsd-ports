PORTNAME=	mdspan
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0.6.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reference implementation of mdspan targeting C++23
WWW=		https://github.com/kokkos/mdspan

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	kokkos

CMAKE_TESTING_ON=	MDSPAN_ENABLE_TESTS

NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
