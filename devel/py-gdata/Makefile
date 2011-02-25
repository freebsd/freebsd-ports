# New ports collection makefile for:	py-gdata
# Date created:		Mar. 28, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	gdata
PORTVERSION=	2.0.13
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	GData Python Client Library

PROJECTHOST=	gdata-python-client
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

LICENSE=	ASL

# optional modules (see src/gdata/tlslite/utils/cryptomath.py)
OPTIONS=	M2CRYPTO "Add cryptography and SSL toolkit for Python" off \
		PYCRYPTO "Add cryptography toolkit for Python" off \
		GMPY "Add multiprecision arithmetic for Python" off

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

.if defined(WITH_M2CRYPTO)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}m2crypto>=0.20:${PORTSDIR}/security/py-m2crypto
.endif
.if defined(WITH_PYCRYPTO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto
.endif
.if defined(WITH_GMPY)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gmpy.so:${PORTSDIR}/math/py-gmpy
.endif

.if !defined(NOPORTEXAMPLES)
post-install:
	${MKDIR} ${EXAMPLESDIR}/
	${CP} -R ${WRKSRC}/samples/ ${EXAMPLESDIR}/
.endif

.include <bsd.port.post.mk>
