# ex:ts=8
# New ports collection makefile for:	py-optik
# Date created:			Nov 13, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	optik
PORTVERSION=	1.4
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Optik-${PORTVERSION}

MAINTAINER=	alane@FreeBSD.org

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PLIST_SUB+=	DOCSDIR=${DOCSDIR:S@^${PREFIX}/@@}
post-install::
	@${MKDIR} ${DOCSDIR}/test
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/test/* ${DOCSDIR}/test
.endif
EXAMPLES=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PLIST_SUB+=	EXAMPLES=${EXAMPLES:S@^${PREFIX}/@@}
post-install::
	@${MKDIR} ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLES}

.include <bsd.port.mk>
