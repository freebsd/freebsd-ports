# New ports collection makefile for:	py-biopython
# Date created:		28 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	biopython
PORTVERSION=	1.30
CATEGORIES=	biology python
MASTER_SITES=	http://www.biopython.org/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of Python modules for bioinformatics

CONFLICTS=	py*-martel-*

BUILD_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/mx/TextTools/__init__.py:${PORTSDIR}/lang/py-mx-base
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.2+
USE_PYDISTUTILS=yes

.if !defined(WITHOUT_REPORTLAB)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab
.endif

.include <bsd.port.mk>
