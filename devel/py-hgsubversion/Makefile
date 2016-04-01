# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	hgsubversion
PORTVERSION=	1.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Mercurial extension that allows using it as a Subversion client

LICENSE=	GPLv2

OPTIONS_DEFINE=	SUBVERTPY
OPTIONS_DEFAULT=SUBVERTPY
SUBVERTPY_DESC=	Use subvertpy python bindings

USES=		python:2
USE_PYTHON=	autoplist distutils

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSUBVERTPY}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subvertpy>=0:devel/py-subvertpy
.else
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subversion>=0:devel/py-subversion
.endif

.include <bsd.port.mk>
