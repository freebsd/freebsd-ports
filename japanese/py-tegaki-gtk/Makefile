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

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

LIB_DEPENDS=	libzinnia.so:japanese/zinnia
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/tegaki/engine.py:japanese/py-tegaki@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	${PORTNAME}_pygtk

.include <bsd.port.mk>
