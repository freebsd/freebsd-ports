# New ports collection makefile for:	py-unit
# Date created:			Aug 16, 2001
# Whom:				Shell Hung <shell@shellhung.org>
#
# $FreeBSD$
#

PORTNAME=	unit
PORTVERSION=	1.4.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyunit
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyunit-${PORTVERSION}

MAINTAINER=	shell@shellhung.org

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} \
			${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
