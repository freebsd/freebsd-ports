# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$
#

PORTNAME=	gdata
PORTVERSION=	2.0.17
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	GData Python Client Library

LICENSE=	AL2

PROJECTHOST=	gdata-python-client
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes

OPTIONS_DEFINE=	GMPY M2CRYPTO PYCRYPTO

# optional modules (see src/gdata/tlslite/utils/cryptomath.py)
GMPY_DESC=	Multiprecision arithmetic
M2CRYPTO_DESC=	Cryptography and SSL toolkit
PYCRYPTO_DESC=	Cryptography toolkit

OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.include <bsd.port.pre.mk>

# avoid warning with Python > 2.5
.if ${PYTHON_REL} > 250
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_atom-mock_service.py \
		${FILESDIR}/extra-patch-src_gdata_tlslite-mathls.py \
		${FILESDIR}/extra-patch-src_gdata_tlslite-messages.py \
		${FILESDIR}/extra-patch-src_gdata_tlslite-TLSRecordLayer.py \
		${FILESDIR}/extra-patch-src_gdata_tlslite_utils-jython_compat.py
.endif

.if ${PORT_OPTIONS:MM2CRYPTO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}m2crypto>=0.20:${PORTSDIR}/security/py-m2crypto
.endif
.if ${PORT_OPTIONS:MPYCRYPTO}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto
.endif
.if ${PORT_OPTIONS:MGMPY}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gmpy.so:${PORTSDIR}/math/py-gmpy
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	${CP} -R ${WRKSRC}/samples/ ${EXAMPLESDIR}/
.endif

.include <bsd.port.post.mk>
