PORTNAME=	ptpython
PORTVERSION=	3.0.31
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python REPL build on top of prompt_toolkit
WWW=		https://github.com/prompt-toolkit/ptpython

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.16.0:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=3.0.43<3.1.0:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ALL PTIPYTHON
ALL_DESC=	All optional dependencies
PTIPYTHON_DESC=	Interactive shell with IPython support

PTIPYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=0:devel/ipython@${PY_FLAVOR}
ALL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>=0:devel/py-black@${PY_FLAVOR}

.include <bsd.port.mk>
