# ex:ts=8
# New ports collection makefile for:	py-optik
# Date created:			Nov 13, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	optik
PORTVERSION=	1.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Optik-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
