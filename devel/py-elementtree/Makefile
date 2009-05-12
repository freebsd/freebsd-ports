# Ports collection makefile for:				py-elementtree
# Date created:							Feb 28, 2005
# Whom:								barner
#
# $FreeBSD$
#

PORTNAME=	elementtree
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://effbot.org/media/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-20050316

MAINTAINER=	python@FreeBSD.org
COMMENT=	Container for hierarchical data structures written in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	1.2.6-20050316

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 250
IGNORE=	this comes with the Python package
.endif

.include <bsd.port.post.mk>
