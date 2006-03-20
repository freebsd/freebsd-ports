# New ports collection makefile for:	py-utils
# Date created:				16 March 2006
# Whom:					Daniel Bretoi
#
# $FreeBSD$
#

PORTNAME=	utils
PORTVERSION=	0.2.5
CATEGORIES=	devel
MASTER_SITES=	http://www.voidspace.org.uk/cgi-bin/voidspace/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	downman.py?file=pythonutils-${PORTVERSION}

MAINTAINER=	daniel@netwalk.org
COMMENT=	General utility modules that simplify common programming in Python

USE_PYTHON=	2.2+
USE_PYDISTUTILS=yes
WRKSRC=		${WRKDIR}/pythonutils-${PORTVERSION}
USE_ZIP=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
