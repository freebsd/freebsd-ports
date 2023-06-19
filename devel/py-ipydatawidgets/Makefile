PORTNAME=	ipydatawidgets
PORTVERSION=	4.3.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of widgets to facilitate reuse of large datasets across widgets
WWW=		https://github.com/vidartf/ipydatawidgets

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-packaging>0:devel/py-jupyter-packaging@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipywidgets>=7.0.0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}traittypes>=0.2.0:devel/py-traittypes@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
