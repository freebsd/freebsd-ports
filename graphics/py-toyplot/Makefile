PORTNAME=	toyplot
PORTVERSION=	2.1.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Modern plotting toolkit supporting electronic publishing
WWW=		https://pypi.org/project/toyplot/

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.8:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colormath>=2.1.1:math/py-colormath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multipledispatch>=0.4.7:devel/py-multipledispatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}png>=0.0.17:graphics/py-png@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>=3.2.0:print/py-reportlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}custom_inherit>=2.2.0:textproc/py-custom_inherit@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2:devel/py-flit-core@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
