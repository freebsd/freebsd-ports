# Ports collection makefile for:        py-emphem
# Date created:                 Feb 27, 2007
# Whom:                         db
#
# $FreeBSD$
#

PORTNAME=	pyephem
PORTVERSION=	3.7b
CATEGORIES=	astro math hamradio
MASTER_SITES=	http://rhodesmill.org/brandon/projects/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Scientific-grade astronomical computations for Python

USE_PYTHON=	2.4+
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC}; ${PYTHON_CMD} setup.py install)
.if     !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pyephem-manual.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
