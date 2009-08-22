# ex:ts=8
# New ports collection makefile for:	py-optik
# Date created:			Nov 13, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	optik
PORTVERSION=	1.5.3
CATEGORIES=	devel python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	A command-line parsing library for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PLIST_SUB+=	DOCSDIR=${DOCSDIR:S@^${PREFIX}/@@}
post-install::
	@${MKDIR} ${DOCSDIR}/test
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/test/* ${DOCSDIR}/test
.endif
EXAMPLES=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PLIST_SUB+=	EXAMPLES=${EXAMPLES:S@^${PREFIX}/@@}
post-install::
	@${MKDIR} ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLES}

.include <bsd.port.mk>
