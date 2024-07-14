PORTNAME=	gdstk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.53
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for creation and manipulation of GDSII and OASIS files
WWW=		https://heitzmann.github.io/gdstk/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libqhull_r.so:math/qhull

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	heitzmann

CMAKE_ON=	BUILD_SHARED_LIBS

CONFLICTS_INSTALL=	misc/vxl # both install lib/libclipper.so

.include <bsd.port.mk>
