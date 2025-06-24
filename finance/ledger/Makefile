PORTNAME=	ledger
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.2
PORTREVISION=	5
CATEGORIES=	finance

MAINTAINER=	woodycarey@hotmail.com
COMMENT=	John Wiegley's command line accounting program
WWW=		https://ledger-cli.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	utf8cpp>=0:devel/utf8cpp
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		cmake compiler:c++11-lib cpe libedit
CPE_VENDOR=	${PORTNAME}-cli
USE_GITHUB=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GNUPG PYTHON
OPTIONS_SUB=	yes

GNUPG_LIB_DEPENDS=	libgpgme.so:security/gpgme \
			libgpgmepp.so:security/gpgmepp
GNUPG_CMAKE_BOOL=	USE_GPGME

PYTHON_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boost-libs>0:devel/boost-python-libs@${PY_FLAVOR}
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boost-libs>0:devel/boost-python-libs@${PY_FLAVOR}
PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	USE_PYTHON

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
