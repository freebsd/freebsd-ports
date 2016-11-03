# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	invoke
PORTVERSION=	0.13.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Python task execution tool & library

LICENSE=	BSD2CLAUSE

USES=		python
USE_PYTHON=	autoplist distutils

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}semantic_version>0:devel/py-semantic_version
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}twine>0:devel/py-twine
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage

NO_ARCH=	YES

.include <bsd.port.mk>
