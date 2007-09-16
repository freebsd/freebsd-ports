# New ports collection makefile for:	pefile
# Date created:				16 July 2006
# Whom:					antoine.brodin@laposte.net
#
# $FreeBSD$
#

PORTNAME=	pefile
PORTVERSION=	1.2.7
CATEGORIES=	devel python
MASTER_SITES=	http://pefile.googlecode.com/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine.brodin@laposte.net
COMMENT=	A python module to read and work with PE files

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
