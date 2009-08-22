# New ports collection makefile for:   pybookreader
# Date created:        30 September 2006
# Whom:                Valeri Vassiliev
#
# $FreeBSD$
#

PORTNAME=	pybookreader
PORTVERSION=	0.5.0
PORTREVISION=	3
CATEGORIES=	deskutils python
MASTER_SITES=	SF/${PORTNAME}/PyBookReader/PyBookReader%2BOrnamentBook-${PORTVERSION}
DISTNAME=	PyBookReader-${PORTVERSION}

MAINTAINER=	ufo@februality.com
COMMENT=	Program for reading e-books

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2

USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyBookReader
USE_GNOME=	pygtk2

.include <bsd.port.mk>
