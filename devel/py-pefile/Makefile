# New ports collection makefile for:	pefile
# Date created:				16 July 2006
# Whom:					antoine.brodin@laposte.net
#
# $FreeBSD$
#

PORTNAME=	pefile
DISTVERSION=	1.2.10-93
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	A python module to read and work with PE files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFO=	${PORTNAME}-${DISTVERSION:C,-,_,g}-py${PYTHON_VER}.egg-info

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
