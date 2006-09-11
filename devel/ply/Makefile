# ex:ts=8
# New ports collection makefile for:	ply
# Date created:			Jul 31, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ply
PORTVERSION=	1.9
CATEGORIES=	devel python
MASTER_SITES=	http://www.dabeaz.com/ply/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mva@sysfault.org
COMMENT=	Python Lex-Yacc

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ply.html ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/example/ ${EXAMPLESDIR}
.endif

BROKEN=		Does not fetch: a new version (2.0) available

.include <bsd.port.mk>
