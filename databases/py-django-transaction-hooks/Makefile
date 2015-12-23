# Created by: René Ladan <rene@freebsd.org>
# $FreeBSD$

PORTNAME=	django-transaction-hooks
PORTVERSION=	0.2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rene@freebsd.org
COMMENT=	Django database backends to register transaction-commit hooks

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.6.1:${PORTSDIR}/www/py-django

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
