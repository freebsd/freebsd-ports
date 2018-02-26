# $FreeBSD$

PORTNAME=	astroid
PORTVERSION=	1.6.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	abstract syntax tree for Python with inference support

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

RUN_DEPENDS=	${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}lazy-object-proxy>=0:devel/py-lazy-object-proxy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=0:devel/py-wrapt@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.functools_lru_cache>=0:devel/py-backports.functools_lru_cache@${FLAVOR}
.endif

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}singledispatch>=0:devel/py-singledispatch@${FLAVOR}
.endif

.include <bsd.port.post.mk>
