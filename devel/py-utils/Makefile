# New ports collection makefile for:	py-utils
# Date created:				16 March 2006
# Whom:					Daniel Bretoi
#
# $FreeBSD$
#

PORTNAME=	utils
PORTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	http://www.voidspace.org.uk/cgi-bin/voidspace/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	downman.py?file=pythonutils-${PORTVERSION}

MAINTAINER=	daniel@netwalk.org
COMMENT=	General utility modules that simplify common programming in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pythonutils
PYDISTUTILS_EGGINFODIR=	${PYTHONPREFIX_SITELIBDIR}/pythonutils
WRKSRC=		${WRKDIR}/pythonutils-${PORTVERSION}
USE_ZIP=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
