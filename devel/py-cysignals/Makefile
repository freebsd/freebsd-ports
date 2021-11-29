# Created by: thierry@pompo.net

PORTNAME=	cysignals
PORTVERSION=	1.11.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Interrupt and signal handling for Cython

LICENSE=	LGPL3

LIB_DEPENDS=	libpari.so:math/pari

#USE_GITHUB=	yes
#GH_ACCOUNT=	sagemath

USES=		autoreconf:build compiler:c++11-lang gettext localbase python:3.6+
USE_PYTHON=	cython distutils

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.6,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_USES=		gmake
PORTDOCS=		*

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && ${GMAKE} html)

post-build-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/build/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
