PORTNAME=	pydot
PORTVERSION=	4.0.1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the Graphviz Dot language
WWW=		https://github.com/pydot/pydot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSES/MIT.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	dot:graphics/graphviz \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=3.1.0:devel/py-pyparsing@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
