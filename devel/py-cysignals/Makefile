# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	cysignals
DISTVERSION=	1.10.2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Interrupt and signal handling for Cython

LICENSE=	LGPL3

BUILD_DEPENDS=	cython:lang/cython
LIB_DEPENDS=	libpari.so:math/pari

USE_GITHUB=	yes
GH_ACCOUNT=	sagemath

USES=		autoreconf:build compiler:c++11-lang gettext localbase python:3.6+
USE_PYTHON=	distutils

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	${PY_SPHINX}
DOCS_USES=		gmake
PORTDOCS=		*

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && ${GMAKE} html)

post-build-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/build/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
