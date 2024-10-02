PORTNAME=	ledger
PORTVERSION=	3.3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	finance

MAINTAINER=	woodycarey@hotmail.com
COMMENT=	John Wiegley's command line accounting program
WWW=		https://ledger-cli.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	utf8cpp>=0:devel/utf8cpp
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libboost_system.so:devel/boost-libs

USES=		cmake compiler:c++11-lib cpe libedit
CPE_VENDOR=	${PORTNAME}-cli
USE_GITHUB=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GNUPG PYTHON
OPTIONS_SUB=	yes

GNUPG_LIB_DEPENDS=	libgpgmepp.so:security/gpgme-cpp \
			libgpgme.so:security/gpgme
GNUPG_CMAKE_BOOL=	USE_GPGME

PYTHON_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boost-libs>0:devel/boost-python-libs@${PY_FLAVOR}
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boost-libs>0:devel/boost-python-libs@${PY_FLAVOR}
PYTHON_CMAKE_BOOL=	USE_PYTHON
PYTHON_USES=		python

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
