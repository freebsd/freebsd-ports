# New ports collection makefile for:	pyrex
# Date created:		11 April 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	pyrex
PORTVERSION=	0.9.8.5
PORTREVISION=	1
CATEGORIES=	devel lang python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/
PKGNAMEPREFIX=	${PYTHONPKGNAMEPREFIX}
DISTNAME=	Pyrex-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Programming Language for writing Python extension modules

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	Pyrex

post-install:
	@# precompile lexicon pickle
	@cd ${WRKSRC}/Demos && ${PYTHON_CMD} ${PREFIX}/bin/pyrexc primes.pyx

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/Manual
	@cd ${WRKSRC}/Doc && ${INSTALL_DATA} ./[^M]* ${DOCSDIR}
	@cd ${WRKSRC}/Doc/Manual && ${INSTALL_DATA} ./* ${DOCSDIR}/Manual
.endif
.if !defined(NOPORTEXAMPLES)
	@cd ${WRKSRC}/Demos && ${MAKE} clean
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/Demos -cf - . | \
	 ${TAR} -C ${EXAMPLESDIR} -xf -
.endif

.include <bsd.port.mk>
