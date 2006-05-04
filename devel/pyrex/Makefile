# New ports collection makefile for:	pyrex
# Date created:		11 April 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	pyrex
PORTVERSION=	0.9.4.1
CATEGORIES=	devel lang python
MASTER_SITES=	http://nz.cosc.canterbury.ac.nz/~greg/python/Pyrex/
PKGNAMEPREFIX=	${PYTHONPKGNAMEPREFIX}
DISTNAME=	Pyrex-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Programming Language for writing Python extension modules

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-install:
	@# precompile lexicon pickle
	@cd ${WRKSRC}/Demos && ${PYTHON_CMD} ${PREFIX}/bin/pyrexc primes.pyx

.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/Demos && ${MAKE} clean

	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/Doc && ${INSTALL_DATA} ./* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/Demos -cf - . | \
	 ${TAR} -C ${EXAMPLESDIR} -xf -
.endif

.include <bsd.port.mk>
