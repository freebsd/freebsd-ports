# Created by: Chao Shin <quakelee@cn.FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyutil
PORTVERSION=	1.9.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Collection of mature utilities for Python programmers

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.1.1:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}zbase32>=1.1.0:${PORTSDIR}/converters/zbase32

USE_PYTHON=	2
USE_PYDISTUTILS=easy_install

NO_STAGE=	yes
post-extract:
	@${FIND} ${WRKSRC} -type f -name "*.py~" -delete

.include <bsd.port.mk>
