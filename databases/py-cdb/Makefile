# New ports collection makefile for:	py-cdb
# Date created:				03 December 2001
# Whom:					Jason R. Mastaler <jason@mastaler.com>
#
# $FreeBSD$
#

PORTNAME=	cdb
PORTVERSION=	0.31.a
CATEGORIES=	databases python
MASTER_SITES=	http://pilcrow.madison.wi.us/sw/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION:S/.a/a/}

MAINTAINER=	jason@mastaler.com

BUILD_DEPENDS=	${PYDISTUTILS}
USE_PYTHON=	yes

do-build:
	(cd ${WRKSRC}; ${PYTHON_CMD} setup.py build)

do-install:
	(cd ${WRKSRC}; ${PYTHON_CMD} setup.py install)

.include <bsd.port.mk>
