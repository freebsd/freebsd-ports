PORTNAME=	Js2Py
DISTVERSION=	0.74
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JavaScript to Python translator and interpreter
WWW=		https://pypi.org/project/Js2Py/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyjsparser>=2.4.5:devel/py-pyjsparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=1.2:devel/py-tzlocal@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
