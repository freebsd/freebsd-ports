PORTNAME=	simpleparse
PORTVERSION=	2.2.4
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SimpleParse-${PORTVERSION}

PATCH_SITES=	https://github.com/mcfletch/simpleparse/commit/
PATCHFILES=	51c058731d7faedcef29d9e0e86e1f8e97f855b6.patch:-p1 \
		3416c19053801e41eebdf108d1a60a41593ab5fb.patch:-p1 \
		83c8b6f9f9130d114b2c9cf3ce432b989b1a65cc.patch:-p1 \
		daa2638479e5484b759fdbfa1f62f965516d1415.patch:-p1 \
		797d53c827d184496a7eac815bc137bd15e068c8.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python EBNF parser generator (with mx.TextTools derivative)
WWW=		https://simpleparse.sourceforge.net/ \
		https://github.com/mcfletch/simpleparse

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
