# Created by: Valeri Vassiliev
# $FreeBSD$

PORTNAME=	pybookreader
PORTVERSION=	0.5.0
PORTREVISION=	7
CATEGORIES=	deskutils python
MASTER_SITES=	SF/${PORTNAME}/PyBookReader/PyBookReader%2BOrnamentBook-${PORTVERSION}
DISTNAME=	PyBookReader-${PORTVERSION}

MAINTAINER=	ufo@februality.com
COMMENT=	Program for reading e-books

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:textproc/py-libxml2

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	PyBookReader
USE_GNOME=	pygtk2

.include <bsd.port.mk>
