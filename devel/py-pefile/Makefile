# New ports collection makefile for:	pefile
# Date created:				16 July 2006
# Whom:					antoine.brodin@laposte.net
#
# $FreeBSD$
#

PORTNAME=	pefile
PORTVERSION=	1.1
CATEGORIES=	devel python
MASTER_SITES=	http://dkbza.org/pefile/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine.brodin@laposte.net
COMMENT=	A python module to read and work with PE files

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
