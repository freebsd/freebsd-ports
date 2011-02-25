# New ports collection makefile for:	py-kid
# Date created:		2005-11-02
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	kid
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.kid-templating.org/dist/${PORTVERSION}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A simple template language for XML based written in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} ; ${CP} README HISTORY COPYING misc/* ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
