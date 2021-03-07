# $FreeBSD$

PORTNAME=	astroid
PORTVERSION=	2.5.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Abstract syntax tree for Python with inference support

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lazy-object-proxy>=1.4.0:devel/py-lazy-object-proxy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.11<1.13:devel/py-wrapt@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typed-ast>=1.4.0<1.5:devel/py-typed-ast@${PY_FLAVOR}
.endif

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.post.mk>
