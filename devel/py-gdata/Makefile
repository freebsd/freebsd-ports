# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	gdata
PORTVERSION=	2.0.18
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	GData Python Client Library

LICENSE=	APACHE20

USES=		python:2.7
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	GMPY M2CRYPTO PYCRYPTO EXAMPLES

# optional modules (see src/gdata/tlslite/utils/cryptomath.py)
GMPY_DESC=	Multiprecision arithmetic
M2CRYPTO_DESC=	Cryptography and SSL toolkit
PYCRYPTO_DESC=	Cryptography toolkit

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

M2CRYPTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}m2crypto>=0.20:security/py-m2crypto@${PY_FLAVOR}
PYCRYPTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR}
GMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gmpy>0:math/py-gmpy@${PY_FLAVOR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	@cd ${WRKSRC}/samples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
