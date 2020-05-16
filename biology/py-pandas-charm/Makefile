# $FreeBSD$

PORTNAME=	pandas-charm
DISTVERSION=	0.3.0
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for getting character matrices into and out of pandas

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPEDNS=	${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
