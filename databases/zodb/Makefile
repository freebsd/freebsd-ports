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
MASTER_SITES=	http://www.zope.org/Products/StandaloneZODB/1.0%20final/
DISTNAME=	StandaloneZODB-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Zope Object Database, a persistent object database for Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/bsddb3/__init__.py:${PORTSDIR}/databases/py-bsddb3

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
CONFLICTS=	zodb*-3.*

pre-install:
	@ ${SH} ${PKGREQ} INSTALL

.include <bsd.port.mk>
