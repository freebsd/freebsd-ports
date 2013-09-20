# Created by: Yuan-Chung Hsiao <ychsiao@gmail.com>
# $FreeBSD$

PORTNAME=	tw.forms
PORTVERSION=	0.9.9
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Web Widgets for building and validating forms

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ToscaWidgets>=0:${PORTSDIR}/devel/py-ToscaWidgets \
		${PYTHON_PKGNAMEPREFIX}formencode>=0:${PORTSDIR}/www/py-formencode
RUN_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}ToscaWidgets>=0:${PORTSDIR}/devel/py-ToscaWidgets \
		${PYTHON_PKGNAMEPREFIX}formencode>=0:${PORTSDIR}/www/py-formencode

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	tw.forms

NO_STAGE=	yes
.include <bsd.port.mk>
