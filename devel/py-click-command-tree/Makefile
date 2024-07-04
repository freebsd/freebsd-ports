PORTNAME=	click-command-tree
PORTVERSION=	1.1.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	aishapoval@mts.ru
COMMENT=	Python click plugin to show the command tree of your CLI
WWW=	https://github.com/whwright/click-command-tree
LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.0<9:devel/py-click@${PY_FLAVOR}


USES=		python:3.9-3.11
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
