# ex:ts=8
# Ports collection makefile for:	py-fortran
# Date created:			Jul 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fortran
PORTVERSION=	8.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyfortran
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyfort-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creating extensions to the Python language with Fortran routines

RUN_DEPENDS=	${PYNUMERIC}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/p/P/}

.include <bsd.port.mk>
