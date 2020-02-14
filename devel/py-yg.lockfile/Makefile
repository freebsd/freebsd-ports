# $FreeBSD$

PORTNAME=	yg.lockfile
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Provides lockfile objects with timeouts and context manager

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15.0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zclockfile>=0:devel/py-zclockfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tempora>=0:devel/py-tempora@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}contextlib2>=0.5:devel/py-contextlib2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}jaraco.functools2>=1.16:devel/py-jaraco.functools2@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}jaraco.functools>=1.16:devel/py-jaraco.functools@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
