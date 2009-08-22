# New ports collection makefile for:	py-serial
# Date created:		26 February 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	serial
PORTVERSION=	2.4
CATEGORIES=	comms python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyserial-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Serial port encapsulation library for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
USE_PYTHON_PREFIX=	yes
PYDISTUTILS_PKGNAME=	pyserial
PORTDOCS=	*.txt
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/*.txt ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif


.include <bsd.port.mk>
