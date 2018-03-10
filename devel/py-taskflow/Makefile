# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	taskflow
PORTVERSION=	2.9.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Taskflow structured state management library

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PY_FUTURES} \
		${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.17.1:devel/py-stevedore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}retrying>=0:devel/py-retrying@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.18.0:devel/py-oslo.utils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=1.10:math/py-networkx@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monotonic>=0.6:devel/py-monotonic@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:devel/py-jsonschema@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}futurist>=0:devel/py-futurist@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasteners>=0.7:devel/py-fasteners@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}debtcollector>=1.2.0:devel/py-debtcollector@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}contextlib2>=0.4.0:devel/py-contextlib2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachetools>=1.1.0:devel/py-cachetools@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}automaton>=0.5.0:devel/py-automaton@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=3.2.1:devel/py-tenacity@${FLAVOR}

NO_ARCH=	yes

USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
