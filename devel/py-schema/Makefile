# $FreeBSD$

PORTNAME=	schema
DISTVERSION=	0.7.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple data validation library

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}contextlib2>=0.5.5:devel/py-contextlib2@${PY_FLAVOR}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		python:3.6+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
