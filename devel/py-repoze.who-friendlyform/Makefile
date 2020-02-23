# Created by: Yuan-Chung Hsiao <ychsiao@gmail.com>
# $FreeBSD$

PORTNAME=	repoze.who-friendlyform
PORTVERSION=	1.0.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Collection of developer-friendly for repoze.who-powered

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}repoze.who>=1.0.15:devel/py-repoze.who@${PY_FLAVOR}
RUN_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}repoze.who>=1.0.15:devel/py-repoze.who@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
