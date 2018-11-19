# $FreeBSD$

PORTNAME=	ignition-cmake
DISTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CMake modules to be used by the Ignition projects

LICENSE=	APACHE20

BUILD_DEPENDS=	ruby:lang/ruby24
RUN_DEPENDS=	ruby:lang/ruby24

USES=		cmake:outsource pkgconfig

CMAKE_OFF=	BUILD_TESTING

BB_ACCOUNT=	ignitionrobotics
BB_PROJECT=	ign-cmake
BB_COMMIT=	6d43bfc00ac1

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}
NO_ARCH=	src/ign.in

.include <bsd.port.mk>
