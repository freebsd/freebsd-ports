# ex:ts=8
# New ports collection makefile for:	PyCXX
# Date created:			Oct 7, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cxx
PORTVERSION=	6.0.0
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/CXX/PyCXX%20V${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pycxx-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Make it easier to extend Python with C++

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
PYDISTUTILS_PKGNAME=	CXX
PYDISTUTILS_PKGVERSION=	5.3

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*

.if !defined(NOPORTDOCS)
post-install:
		@${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/Doc/PyCXX.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
