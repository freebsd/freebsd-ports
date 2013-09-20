# Created by: Daniel Bretoi
# $FreeBSD$

PORTNAME=	utils
PORTVERSION=	0.4.0
CATEGORIES=	devel python
MASTER_SITES=	http://www.voidspace.org.uk/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pythonutils-${PORTVERSION}

MAINTAINER=	daniel@netwalk.org
COMMENT=	General utility modules that simplify common programming in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pythonutils
PYDISTUTILS_EGGINFODIR=	${PYTHONPREFIX_SITELIBDIR}/pythonutils
WRKSRC=		${WRKDIR}/pythonutils-${PORTVERSION}
USE_ZIP=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
