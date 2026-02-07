PORTNAME=	kms-cmake-utils
DISTVERSION=	6.18.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CMake common files used to build all Kurento C/C++ projects
WWW=		https://github.com/Kurento/kms-cmake-utils

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Kurento

NO_ARCH=	yes

PLIST_SUB=	CMAKE_VERSION=${_CMAKE_VERSION:R}

.include <bsd.port.mk>
