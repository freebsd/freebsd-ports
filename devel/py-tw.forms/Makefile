# Created by: Yuan-Chung Hsiao <ychsiao@gmail.com>
# $FreeBSD$

PORTNAME=	tw.forms
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Web Widgets for building and validating forms

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ToscaWidgets>=0:devel/py-ToscaWidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}formencode>=0:www/py-formencode@${PY_FLAVOR}
RUN_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}ToscaWidgets>=0:devel/py-ToscaWidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}formencode>=0:www/py-formencode@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
