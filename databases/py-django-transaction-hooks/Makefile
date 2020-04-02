# Created by: René Ladan <rene@freebsd.org>
# $FreeBSD$

PORTNAME=	django-transaction-hooks
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Django database backends to register transaction-commit hooks

LICENSE=	BSD3CLAUSE

DEPRECATED=	Unmaintained upstream and merged into Django since 1.9
EXPIRATION_DATE=	2020-07-02

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=1.11:www/py-django111@${PY_FLAVOR}

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
