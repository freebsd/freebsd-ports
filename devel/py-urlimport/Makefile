# New ports collection makefile for:	py-urlimport
# Date created:		2006-12-31
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	urlimport
PORTVERSION=	0.42b
CATEGORIES=	devel python
MASTER_SITES=	http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.py

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python script for importing modules/packages over the net

NO_WRKSUBDIR=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/urlimport.py \
		%%PYTHON_SITELIBDIR%%/urlimport.pyc \
		%%PYTHON_SITELIBDIR%%/urlimport.pyo

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/${PORTNAME}.py
	${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${FILESDIR}/setup.py \
		> ${WRKSRC}/setup.py

.include <bsd.port.mk>
