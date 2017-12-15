# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	invoke
PORTVERSION=	0.17.0
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Python task execution tool & library

LICENSE=	BSD2CLAUSE

USES=		python
USE_PYTHON=	autoplist distutils

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}semantic_version>0:devel/py-semantic_version@${FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}twine>0:devel/py-twine@${FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${FLAVOR}

NO_ARCH=	YES

.include <bsd.port.mk>
