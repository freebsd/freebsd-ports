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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ToscaWidgets>=0:devel/py-ToscaWidgets \
		${PYTHON_PKGNAMEPREFIX}formencode>=0:www/py-formencode
RUN_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}ToscaWidgets>=0:devel/py-ToscaWidgets \
		${PYTHON_PKGNAMEPREFIX}formencode>=0:www/py-formencode

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
