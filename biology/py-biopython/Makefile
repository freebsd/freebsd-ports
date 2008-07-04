# New ports collection makefile for:	py-biopython
# Date created:		28 July 2000
# Whom:			Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	biopython
PORTVERSION=	1.45
CATEGORIES=	biology python
MASTER_SITES=	http://www.biopython.org/DIST/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mauricio@arareko.net
COMMENT=	A collection of Python modules for bioinformatics

BUILD_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/mx/TextTools/__init__.py:${PORTSDIR}/lang/py-mx-base
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS=	py*-martel-[0-9]*

USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes

.if !defined(WITHOUT_REPORTLAB)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab
.endif

.include <bsd.port.mk>
