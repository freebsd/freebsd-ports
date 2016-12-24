# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	gdata
PORTVERSION=	2.0.18
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	GData Python Client Library

LICENSE=	APACHE20

USES=		python:2
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	GMPY M2CRYPTO PYCRYPTO EXAMPLES

# optional modules (see src/gdata/tlslite/utils/cryptomath.py)
GMPY_DESC=	Multiprecision arithmetic
M2CRYPTO_DESC=	Cryptography and SSL toolkit
PYCRYPTO_DESC=	Cryptography toolkit

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

M2CRYPTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}m2crypto>=0.20:security/py-m2crypto
PYCRYPTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto
GMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gmpy>0:math/py-gmpy

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	@cd ${WRKSRC}/samples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
