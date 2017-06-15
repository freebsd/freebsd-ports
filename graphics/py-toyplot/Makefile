# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	toyplot
PORTVERSION=	0.9.0
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Modern plotting toolkit supporting electronic publishing

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.7,1:math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}colormath>=2.1.1:math/py-colormath \
		${PYTHON_PKGNAMEPREFIX}multipledispatch>=0.4.7:devel/py-multipledispatch

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
