# Created by: Wen Heping <wenhping@gmail.com>
# $FreeBSD$

PORTNAME=	cython
PORTVERSION=	0.19.1
PORTREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	http://www.cython.org/release/ \
		CHEESESHOP
DISTNAME=	Cython-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Compiler for Writing C Extensions for the Python Language

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pkg_resources.py:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Cython

NO_STAGE=	yes
.include <bsd.port.mk>
