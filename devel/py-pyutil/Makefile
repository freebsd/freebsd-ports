# New ports collection makefile for:	py-pyutil
# Date created:		2007-5-31
# Whom:			Chao Shin <quakelee@cn.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyutil
PORTVERSION=	1.8.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A collection of mature utilities for Python programmers

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>=0.8.0:${PORTSDIR}/devel/py-argparse \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.1.1:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}zbase32>=1.1.0:${PORTSDIR}/converters/zbase32

USE_PYTHON=	2.5+
USE_PYDISTUTILS=easy_install

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not configure on sparc64
.endif

.include <bsd.port.post.mk>
