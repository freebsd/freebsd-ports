# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	tegaki
PORTVERSION=	0.3.1
CATEGORIES=	japanese python
MASTER_SITES=	http://www.tegaki.org/releases/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-gtk
DISTNAME=	${PORTNAME}-pygtk-${PORTVERSION}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Tegaki PyGTK interface

LICENSE=	GPLv2

LIB_DEPENDS=	libzinnia.so:${PORTSDIR}/japanese/zinnia
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/tegaki/engine.py:${PORTSDIR}/japanese/py-tegaki

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME}_pygtk

.include <bsd.port.mk>
