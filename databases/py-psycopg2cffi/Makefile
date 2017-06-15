# $FreeBSD$

PORTNAME=	psycopg2cffi
PORTVERSION=	2.7.5
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Implementation of the psycopg2 module using cffi

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/_cffi_backend.so:devel/py-cffi
RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/_cffi_backend.so:devel/py-cffi

NO_ARCH=	yes

USE_PYTHON=	autoplist distutils
USES=		pgsql python

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/_impl/_libpq.so

.include <bsd.port.mk>
