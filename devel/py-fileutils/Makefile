# ex:ts=8
# New ports collection makefile for:	py-fileutils
# Date created:			Nov 2, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fileutils
PORTVERSION=	0.4
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.livinglogic.de/pub/livinglogic/fileutils/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FileUtils-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
