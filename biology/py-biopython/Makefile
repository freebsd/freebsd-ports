# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	biopython
PORTVERSION=	1.72
PORTREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	http://www.biopython.org/DIST/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mauricio@arareko.net
COMMENT=	Collection of Python modules for bioinformatics

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	REPORTLAB
OPTIONS_DEFAULT=	REPORTLAB

REPORTLAB_DESC=	PDF support in Bio.Graphics module
REPORTLAB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR}

pre-configure: # unbreak for python3: README.rst can't be decoded with the ascii codec: https://github.com/biopython/biopython/issues/1649
	@truncate -s 0 ${WRKSRC}/README.rst

.include <bsd.port.mk>
