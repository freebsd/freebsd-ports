# Ports collection Makefile for:	SQLDict
# Date created:				10/03/2000
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		SQLDict
PORTVERSION=		1.0.0
CATEGORIES=		databases python
MASTER_SITES=		http://dustman.net/andy/python/SQLDict/1.0.0/
PKGNAMEPREFIX=		py-

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Python dictionary wrapper around a SQL database

USE_PYTHON=		yes
NO_WRKSUBDIR=		yes

do-build:
	@cd ${WRKSRC} && ${PYTHON_CMD} -c 'import SQLDict'
	@cd ${WRKSRC} && ${PYTHON_CMD} -O -c 'import SQLDict'

do-install:
.for f in SQLDict.py SQLDict.pyc SQLDict.pyo
	${INSTALL_DATA} ${WRKSRC}/${f} ${PYTHON_SITELIBDIR}/${f}
.endfor

.include <bsd.port.mk>
