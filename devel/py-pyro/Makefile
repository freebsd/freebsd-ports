# New ports collection makefile for:	py-pyro
# Date created:		2008-12-30
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pyro
PORTVERSION=	3.9
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/OldFiles
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pyro-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Distributed Object Middleware for Python(IPC/RPC)

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Pyro

.include <bsd.port.pre.mk>
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
