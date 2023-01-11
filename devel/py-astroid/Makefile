PORTNAME=	astroid
PORTVERSION=	2.12.13
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Abstract syntax tree for Python with inference support
WWW=		https://github.com/PyCQA/astroid

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lazy-object-proxy>=1.4.0:devel/py-lazy-object-proxy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.14<2:devel/py-wrapt@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CONFLICTS=	${PYTHON_PKGNAMEPREFIX}astroid253

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typed-ast>=1.4.0<2.0:devel/py-typed-ast@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.10:devel/py-typing-extensions@${PY_FLAVOR}
.endif

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.post.mk>
