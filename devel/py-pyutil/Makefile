# Created by: Chao Shin <quakelee@cn.FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyutil
PORTVERSION=	3.1.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Collection of mature utilities for Python programmers

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.1.0:devel/py-simplejson@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zbase32>=1.0:converters/zbase32

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils

post-extract:
	@${FIND} ${WRKSRC} -type f -name "*.py~" -delete

.include <bsd.port.mk>
