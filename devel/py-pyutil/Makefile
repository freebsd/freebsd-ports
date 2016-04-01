# Created by: Chao Shin <quakelee@cn.FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyutil
PORTVERSION=	2.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Collection of mature utilities for Python programmers

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.1.1:devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}zbase32>=1.1.0:converters/zbase32

USES=		python:2
USE_PYTHON=	distutils autoplist

post-extract:
	@${FIND} ${WRKSRC} -type f -name "*.py~" -delete

.include <bsd.port.mk>
