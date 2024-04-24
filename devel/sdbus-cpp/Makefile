PORTNAME=	sdbus-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	High-level C++ D-Bus library
WWW=		https://github.com/Kistler-Group/sdbus-cpp

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbasu.so:devel/basu \
		libexpat.so:textproc/expat2
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	Kistler-Group
CMAKE_ON=	BUILD_CODE_GEN
CMAKE_OFF=	BUILD_DOC
CMAKE_TESTING_ON=	BUILD_TESTS
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/cpp/c++/}

.include <bsd.port.mk>
