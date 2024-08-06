PORTNAME=	click_aliases
PORTVERSION=	1.0.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	aishapoval@mts.ru
COMMENT=	Add (multiple) aliases to a click_ group or command
WWW=		https://github.com/click-contrib/click-aliases
LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry>=0:devel/py-poetry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.0<9:devel/py-click@${PY_FLAVOR}
                                                                              
USES=		python:3.9-3.11
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
