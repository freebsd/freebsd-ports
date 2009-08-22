# New ports collection makefile for:	pycogent
# Date created:		20 June, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pycogent
PORTVERSION=	1.3.1
CATEGORIES=	biology python
MASTER_SITES=	SF/${PORTNAME}/PyCogent/${PORTVERSION}
DISTNAME=	PyCogent-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wenheping@gmail.com
COMMENT=	A toolkit for statistical analysis of biological sequences

BUILD_DEPENDS=	${PYNUMPY} \
		${LOCALBASE}/bin/cython:${PORTSDIR}/lang/cython \
		${LOCALBASE}/bin/sphinx-build:${PORTSDIR}/textproc/py-sphinx \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.5:${PORTSDIR}/databases/py-sqlalchemy
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	cogent

.include <bsd.port.mk>
