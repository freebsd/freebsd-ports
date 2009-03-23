# Ports collection makefile for:				py-elementtree
# Date created:							Feb 28, 2005
# Whom:								barner
#
# $FreeBSD$
#

PORTNAME=	elementtree
PORTVERSION=	1.2.6
CATEGORIES=	devel python
MASTER_SITES=	http://effbot.org/media/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-20050316

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Container for hierarchical data structures written in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	1.2.6-20050316

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
