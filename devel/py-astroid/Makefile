# $FreeBSD$

PORTNAME=	astroid
PORTVERSION=	2.2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Abstract syntax tree for Python with inference support

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lazy-object-proxy>=0:devel/py-lazy-object-proxy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=0:devel/py-wrapt@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3500
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing>=0:devel/py-typing@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 3700
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typed-ast>=0:devel/py-typed-ast@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
