# New ports collection makefile for:	py-instant
# Date created:		Jan. 04, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	instant
PORTVERSION=	0.9
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyinstant
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Instant-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python module for instant inlining of C and C++ code in Python

RUN_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/Instant.py \
		%%PYTHON_SITELIBDIR%%/Instant.pyc \
		%%PYTHON_SITELIBDIR%%/Instant.pyo

.include <bsd.port.mk>
