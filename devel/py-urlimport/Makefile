# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	urlimport
PORTVERSION=	0.42b
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.py

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python script for importing modules/packages over the net

NO_WRKSUBDIR=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/${PORTNAME}.py
	${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${FILESDIR}/setup.py \
		> ${WRKSRC}/setup.py

.include <bsd.port.mk>
