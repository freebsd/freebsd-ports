# ex:ts=8
# New ports collection makefile for:	ply
# Date created:			Jul 31, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ply
PORTVERSION=	2.5
CATEGORIES=	devel python
MASTER_SITES=	http://www.dabeaz.com/ply/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Python Lex-Yacc

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ply.html ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/example/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
