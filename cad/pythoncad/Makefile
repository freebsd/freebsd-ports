# ex:ts=8
# Ports collection makefile for:	pythoncad
# Date created:			Nov 11, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pythoncad
PORTVERSION=	36
PORTREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	http://www.pythoncad.org/releases/
DISTNAME=	PythonCAD-DS1-R${PORTVERSION}

MAINTAINER=	fbsd-ports@xbsd.net
COMMENT=	An open-source CAD package built designed around Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PythonCAD
PYDISTUTILS_PKGVERSION=	DS1-R${PORTVERSION}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gtkpycad.py ${PREFIX}/bin/gtkpycad

.include <bsd.port.mk>
