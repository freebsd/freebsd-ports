PORTNAME=	pycocotools
PORTVERSION=	2.0.10
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official APIs for the MS-COCO dataset
WWW=		https://github.com/ppwwyyxx/cocoapi/tree/master/PythonAPI

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=43.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython3 pep517

OPTIONS_DEFINE=	ALL
ALL_DESC=	All optional dependencies

ALL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=2.1.0:math/py-matplotlib@${PY_FLAVOR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
