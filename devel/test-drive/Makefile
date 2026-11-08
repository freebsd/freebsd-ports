PORTNAME=	test-drive
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple testing framework
WWW=		https://github.com/fortran-lang/test-drive

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-Apache
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cmake:testing fortran
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fortran-lang

CMAKE_ON=	BUILD_SHARED_LIBS

# tests as od 0.6.1: 100% tests passed out of 3

.include <bsd.port.mk>
