# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	gdata
PORTVERSION=	2.0.18
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	GData Python Client Library

LICENSE=	APACHE20

PROJECTHOST=	gdata-python-client
USES=	python:2
USE_PYTHON=	distutils

OPTIONS_DEFINE=	GMPY M2CRYPTO PYCRYPTO EXAMPLES

# optional modules (see src/gdata/tlslite/utils/cryptomath.py)
GMPY_DESC=	Multiprecision arithmetic
M2CRYPTO_DESC=	Cryptography and SSL toolkit
PYCRYPTO_DESC=	Cryptography toolkit

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MM2CRYPTO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}m2crypto>=0.20:security/py-m2crypto
.endif
.if ${PORT_OPTIONS:MPYCRYPTO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto
.endif
.if ${PORT_OPTIONS:MGMPY}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gmpy>0:math/py-gmpy
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	@cd ${WRKSRC}/samples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
