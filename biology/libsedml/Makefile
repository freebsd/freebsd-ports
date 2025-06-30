PORTNAME=	libsedml
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.33
PORTREVISION=	1
CATEGORIES=	biology devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ SED-ML library
WWW=		https://github.com/fbergmann/libSEDML

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	libsbml>0:biology/libsbml \
		libnuml>0:biology/libnuml # statically linked, even into a shared library, see https://github.com/fbergmann/libSEDML/issues/155
RUN_DEPENDS=	libsbml>0:biology/libsbml \
		libnuml>0:biology/libnuml # when static lib libnuml.a is fixed these should be run-time dependency

USES=		cmake:testing compiler:c++11-lang gnome
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fbergmann
GH_PROJECT=	libSEDML

CMAKE_OFF=		BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS

post-install:
	# no need to install LICENSE, README, VERSION
	@${RM} -r ${STAGEDIR}${DATADIR}
	# workaround for https://github.com/fbergmann/libSEDML/issues/163
	${RM} -r ${STAGEDIR}${PREFIX}/share/cmake

# the project builds static libs with -fPIC, see https://github.com/fbergmann/libSEDML/issues/155

# tests as of 2.0.33: All tests passed (351 assertions in 33 test cases)

.include <bsd.port.mk>
