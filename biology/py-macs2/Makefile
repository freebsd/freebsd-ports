# $FreeBSD$

PORTNAME=	macs2
PORTVERSION=	2.1.0.p20170505
PORTREVISION=	2
CATEGORIES=	biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Analysis of chromatin immunoprecipitation (ChIP) sequences

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY}

USES=		python:2.7
USE_PYTHON=	autoplist concurrent cython distutils

USE_GITHUB=	yes
GH_ACCOUNT=	taoliu
GH_PROJECT=	MACS
GH_TAGNAME=	6946b2f

PYSETUP=	setup_w_cython.py

post-stage:
	${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/MACS2/*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/MACS2/*/*.so

.include <bsd.port.mk>
