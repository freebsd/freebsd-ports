# Created by: Joseph Mingrone <jrm@ftfl.ca>
# $FreeBSD$

PORTNAME=	psycopg2cffi
PORTVERSION=	2.7.4
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jrm@ftfl.ca
COMMENT=	Implementation of the psycopg2 module using cffi

LICENSE=	LGPL3+

BUILD_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/_cffi_backend.so:devel/py-cffi
RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/_cffi_backend.so:devel/py-cffi

NO_ARCH=	yes

USE_PYTHON=	autoplist distutils
USES=		pgsql python

.include <bsd.port.mk>
