# New ports collection makefile for:	Codeville
# Date created:		Wed Dec  8 01:00:39 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	codeville
PORTVERSION=	0.1.12
CATEGORIES=	devel python
MASTER_SITES=	http://codeville.org/download/
DISTNAME=	Codeville-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	An "anarchic" control version system without unnecessary re-merges

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PORTDOCS=	\
		LICENSE.txt

EXAMPLE_FILES=	\
		cdvserver.conf.sample

post-install:
# examples
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
# documentation
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
