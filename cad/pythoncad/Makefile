# ex:ts=8
# Ports collection makefile for:	pythoncad
# Date created:			Nov 11, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pythoncad
PORTVERSION=	10
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.pythoncad.org/releases/
DISTNAME=	PythonCAD-DS1-R${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open-source CAD package built designed around Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.pth:${PORTSDIR}/x11-toolkits/py-gtk2

USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gtkpycad.py ${PREFIX}/bin

.include <bsd.port.mk>
