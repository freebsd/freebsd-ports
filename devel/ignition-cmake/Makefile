# $FreeBSD$

PORTNAME=	ignition-cmake
DISTVERSION=	2.0.0
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CMake modules to be used by the Ignition projects

LICENSE=	APACHE20

USES=		cmake:outsource pkgconfig
USE_RUBY=	yes

CMAKE_OFF=	BUILD_TESTING

BB_ACCOUNT=	ignitionrobotics
BB_PROJECT=	ign-cmake
BB_COMMIT=	776c2bfe1d18

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}
NO_ARCH=	yes

PLIST_SUB+=	CMAKE_IGN_VER=cmake${DISTVERSION:R:R}

.include <bsd.port.mk>
