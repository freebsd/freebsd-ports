# New ports collection makefile for:	py-biopython
# Date created:		28 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	biopython
PORTVERSION=	1.23
CATEGORIES=	biology python
MASTER_SITES=	http://www.biopython.org/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wjv@FreeBSD.org
COMMENT=	A collection of Python modules for bioinformatics

CONFLICTS=	py*-martel-*

BUILD_DEPENDS=	${PYDISTUTILS}
RUN_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/mx/TextTools/__init__.py:${PORTSDIR}/lang/py-mx-base

USE_PERL5_BUILD=yes
USE_PYTHON=	2.0+
PYTHON_SETUP=	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py
CPIO=		cpio --quiet -pdum -R
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}

.if !defined(WITHOUT_REPORTLAB)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab
.endif

do-build:
	(cd ${WRKSRC} && ${PYTHON_SETUP} build)

do-install:
	(cd ${WRKSRC} && ${PYTHON_SETUP} install -c -O1 --prefix=${PREFIX})

.include <bsd.port.mk>
