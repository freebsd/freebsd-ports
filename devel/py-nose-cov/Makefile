# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	nose-cov
PORTVERSION=	1.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Nose plugin for coverage reporting

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose

USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
