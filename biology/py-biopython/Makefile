# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	biopython
PORTVERSION=	1.60
PORTREVISION=	4
CATEGORIES=	biology python
MASTER_SITES=	http://www.biopython.org/DIST/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mauricio@arareko.net
COMMENT=	Collection of Python modules for bioinformatics

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.if !defined(WITHOUT_REPORTLAB)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}reportlab1>0:${PORTSDIR}/print/py-reportlab1
.endif

.include <bsd.port.mk>
