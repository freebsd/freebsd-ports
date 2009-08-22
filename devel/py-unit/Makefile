# New ports collection makefile for:	py-unit
# Date created:			Aug 16, 2001
# Whom:				Shell Hung <shell@shellhung.org>
#
# $FreeBSD$
#

PORTNAME=	unit
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyunit-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unit testing framework for Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyUnit

.include <bsd.port.mk>
