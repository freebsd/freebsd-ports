# New ports collection makefile for:    py-interface
# Date created:         		20 July 2009
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	interface
PORTVERSION=	0.96
CATEGORIES=	devel python
MASTER_SITES=	http://www.lysator.liu.se/~tab/erlang/py_interface/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py_${PORTNAME}-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	A Python implementation of an Erlang node

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
DOCSDIR=	${PREFIX}/share/doc/py_${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py_${PORTNAME}

post-install:
	@${TRUE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} * ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
