# New ports collection makefile for:	zodb
# Date created:		18 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zodb
PORTVERSION=	1.0
PORTEPOCH=	1
CATEGORIES=	databases python
MASTER_SITES=	http://www.zope.org/Products/StandaloneZODB/
DISTNAME=	StandaloneZODB-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/bsddb3/__init__.py:${PORTSDIR}/databases/py-bsddb3

USE_PYTHON=	yes
PYTHON_SETUP=	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@ cd ${WRKSRC} && ${PYTHON_SETUP} build

pre-install:
	@ ${SH} ${PKGREQ} INSTALL

do-install:
	@ cd ${WRKSRC} && ${PYTHON_SETUP} install -c -O1 --prefix=${PREFIX}

.include <bsd.port.mk>
