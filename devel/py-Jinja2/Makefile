# New ports collection makefile for:	jinja
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Jinja2
PORTVERSION=	2.4.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A fast, and easy to use stand-alone template engine

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs/_build/html && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
