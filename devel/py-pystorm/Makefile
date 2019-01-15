# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pystorm
PORTVERSION=	3.1.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Battle-tested Apache Storm Multi-Lang implementation for Python

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_MAJOR_VER} < 3
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}contextlib2>0:devel/py-contextlib2@${PY_FLAVOR}
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}unittest2>=0:devel/py-unittest2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}
.endif

post-patch:
	${RM} ${WRKSRC}/test/__init__.py

.include <bsd.port.post.mk>
