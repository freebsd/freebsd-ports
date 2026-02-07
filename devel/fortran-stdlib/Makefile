PORTNAME=	fortran-stdlib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	devel

MAINTAINER=	rwn@mailo.com
COMMENT=	Fortran Standard Library
WWW=		https://stdlib.fortran-lang.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake fortran compiler:features

BUILD_DEPENDS=	fypp:devel/py-fypp

USE_GITHUB=	yes
GH_ACCOUNT=	fortran-lang
GH_PROJECT=	stdlib

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
