# New ports collection makefile for:	py-plex
# Date created:		11 April 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	plex
PORTVERSION=	1.1.4
CATEGORIES=	devel python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/~greg/python/Plex/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Plex-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

DOCDIR=		share/doc/py-plex
EXAMPLESDIR=	share/examples/py-plex

post-extract:
	${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${FILESDIR}/setup.py \
		> ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ./* ${PREFIX}/${DOCDIR}
	${MKDIR} ${PREFIX}/${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ./* ${PREFIX}/${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
