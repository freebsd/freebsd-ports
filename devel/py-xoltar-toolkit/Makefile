# Ports collection Makefile for:	py-functional
# Date created:				10/03/2000
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		functional
PORTVERSION=		0.5
CATEGORIES=		devel python
# The functional.py distfile disappeared.
# I'm storing it on MASTER_SITE_LOCAL until I get around to
# making a port of the xoltar-toolkit.
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
#MASTER_SITE_SUBDIR=	xoltar-toolkit
PKGNAMEPREFIX=		py-
DISTNAME=		functional.py
EXTRACT_SUFX=		.gz

MAINTAINER=		nectar@FreeBSD.org

EXTRACT_AFTER_ARGS=	> ${DISTNAME}
USE_PYTHON=		yes
NO_WRKSUBDIR=		yes

do-build:
	@cd ${WRKSRC} && ${PYTHON_CMD} -c 'import functional'
	@cd ${WRKSRC} && ${PYTHON_CMD} -O -c 'import functional'

do-install:
.for f in functional.py functional.pyc functional.pyo
	${INSTALL_DATA} ${WRKSRC}/${f} ${PYTHON_SITELIBDIR}/${f}
.endfor

.include <bsd.port.mk>
