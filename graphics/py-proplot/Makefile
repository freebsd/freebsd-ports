PORTNAME=	proplot
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Succinct matplotlib wrapper for making beautiful, publication-quality graphics
WWW=		https://proplot.readthedocs.io/en/stable/ \
		https://github.com/proplot-dev/proplot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=44:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.3:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3.3.0:math/py-matplotlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-patch:
# https://github.com/proplot-dev/proplot/commit/d364120851c474ece25b55e857ce179d8b745166
	@${CHMOD} ugo-x ${WRKSRC}/proplot/internals/context.py

.include <bsd.port.mk>
