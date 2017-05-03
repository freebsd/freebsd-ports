# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rq
PORTVERSION=	0.5.6
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Simple library for creating background jobs, and processing them

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=2.7:databases/py-redis \
		${PYTHON_PKGNAMEPREFIX}click>=4.1:devel/py-click

USES=		python shebangfix
USE_PYTHON=	autoplist distutils
SHEBANG_FILES=	rq/scripts/rqgenload.py

.include <bsd.port.mk>
