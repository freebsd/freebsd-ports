# ex:ts=8
# New ports collection makefile for:	ply
# Date created:			Jul 31, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ply
PORTVERSION=	1.1
CATEGORIES=	devel python
MASTER_SITES=	http://systems.cs.uchicago.edu/ply/

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lex.py ${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/yacc.py ${PYTHON_SITELIBDIR}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ply.html ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/example/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
