# $FreeBSD$

PORTNAME=	agate-sql
PORTVERSION=	0.5.6
CATEGORIES=	databases textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Add SQL read/write support to agate

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}agate>=1.5.0:textproc/py-agate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=1.0.8:databases/py-sqlalchemy10@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
