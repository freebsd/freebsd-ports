# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	biopython
PORTVERSION=	1.60
PORTREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	http://www.biopython.org/DIST/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mauricio@arareko.net
COMMENT=	Collection of Python modules for bioinformatics

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

.if !defined(WITHOUT_REPORTLAB)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}reportlab>0:${PORTSDIR}/print/py-reportlab
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
