# Created by: jpaetzel
# $FreeBSD$

PORTNAME=	htsql
PORTVERSION=	2.3.3
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Database Query Language (Core & SQLite Backend)

LICENSE=	AGPLv3

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-11-15

USES=		python:2.7
USE_PYTHON=	distutils autoplist

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

.include <bsd.port.mk>
