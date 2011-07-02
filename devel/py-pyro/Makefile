# New ports collection makefile for:	py-pyro
# Date created:		2008-12-30
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pyro
PORTVERSION=	4.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pyro4-${PORTVERSION}

MAINTAINER=	cvs-src@yandex.ru
COMMENT=	Distributed Object Middleware for Python(IPC/RPC)

LICENSE=	MIT

USE_DOS2UNIX=	yes
USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Pyro4

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
