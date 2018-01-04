# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	toyplot
PORTVERSION=	0.15.1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Modern plotting toolkit supporting electronic publishing

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.8:math/py-numpy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colormath>=2.1.1:math/py-colormath@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multipledispatch>=0.4.7:devel/py-multipledispatch@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}png>=0.0.17:graphics/py-png@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>=3.2.0:print/py-reportlab@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
