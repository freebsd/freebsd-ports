# New ports collection makefile for:	py-plex
# Date created:		11 April 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	plex
PORTVERSION=	1.1.5
CATEGORIES=	devel python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Plex/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Plex-${PORTVERSION}

MAINTAINER=	gcooper@FreeBSD.org
COMMENT=	Lexical Analysis Module for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

NO_WRKSUBDIR=	yes
DOCSDIR=	share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	share/examples/${PKGNAMEPREFIX}${PORTNAME}

post-extract:
	${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${FILESDIR}/setup.py \
		> ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ./* ${PREFIX}/${DOCSDIR}
	${MKDIR} ${PREFIX}/${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ./* ${PREFIX}/${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
