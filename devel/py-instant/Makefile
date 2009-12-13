# New ports collection makefile for:	py-instant
# Date created:		Jan. 04, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	instant
PORTVERSION=	0.9
CATEGORIES=	devel python
MASTER_SITES=	SF/py${PORTNAME}/Instant-${PORTVERSION}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Instant-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python module for instant inlining of C and C++ code in Python

RUN_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Instant
PYDISTUTILS_PKGVERSION=	0.8

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/Instant.py \
		%%PYTHON_SITELIBDIR%%/Instant.pyc \
		%%PYTHON_SITELIBDIR%%/Instant.pyo

.include <bsd.port.mk>
