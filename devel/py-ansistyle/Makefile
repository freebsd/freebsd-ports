# ex:ts=8
# New ports collection makefile for:	py-ansistyle
# Date created:			Nov 2, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ansistyle
PORTVERSION=	0.2.1
CATEGORIES=	devel python
MASTER_SITES=   ftp://ftp.livinglogic.de/pub/livinglogic/ansistyle/
PKGNAMEPREFIX=	py-
DISTNAME=	ANSIStyle-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
