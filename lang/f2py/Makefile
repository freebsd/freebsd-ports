# ex:ts=8
# Ports collection makefile for:	f2py
# Date created:			Jun 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	f2py
PORTVERSION=	2.37.233.1545
CATEGORIES=	lang python
MASTER_SITES=	http://cens.ioc.ee/projects/f2py2e/2.x/
DISTNAME=	${PORTNAME:U}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fortran to Python Interface Generator

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
