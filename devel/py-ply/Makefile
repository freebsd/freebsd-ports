# ex:ts=8
# New ports collection makefile for:	ply
# Date created:			Jul 31, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ply
PORTVERSION=	1.0
CATEGORIES=	devel python
MASTER_SITES=	http://systems.cs.uchicago.edu/ply/

MAINTAINER=	ijliao@FreeBSD.org

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lex.py ${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/yacc.py ${PYTHON_SITELIBDIR}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ply.html ${DOCSDIR}
	${CP} -R ${WRKSRC}/example ${DOCSDIR}
.endif

.include <bsd.port.mk>
