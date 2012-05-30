# New ports collection makefile for:	pefile
# Date created:				16 July 2006
# Whom:					antoine.brodin@laposte.net
#
# $FreeBSD$
#

PORTNAME=	pefile
DISTVERSION=	1.2.10-114
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	A python module to read and work with PE files

LICENSE=	MIT

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	${DISTVERSION:C,-,_,g}

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
