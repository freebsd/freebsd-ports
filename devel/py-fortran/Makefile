# ex:ts=8
# Ports collection makefile for:	py-fortran
# Date created:			Jul 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fortran
PORTVERSION=	8.5.3
CATEGORIES=	devel python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/8.5
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pyfort-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Creating extensions to the Python language with Fortran routines

RUN_DEPENDS=	${PYNUMERIC}:${PORTSDIR}/math/py-numeric

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Pyfort
WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.mk>
