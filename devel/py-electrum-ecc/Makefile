PORTNAME=	electrum-ecc
DISTVERSION=	0.0.6
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Pure python ctypes wrapper for libsecp256k1
WWW=		https://pypi.org/project/electrum-ecc/ \
		https://github.com/spesmilo/electrum-ecc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

post-extract:
	@${RM} ${WRKSRC}/setup.py

.include <bsd.port.mk>
