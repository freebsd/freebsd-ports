# ex:ts=8
# New ports collection makefile for:	PyCXX
# Date created:			Oct 7, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cxx
PORTVERSION=	5.3.6
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pycxx-${PORTVERSION}

MAINTAINER=	lwhsu@lwhsu.org
COMMENT=	Make it easier to extend Python with C++

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
.	if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/Doc/PyCXX.html ${DOCSDIR}
.	endif

.include <bsd.port.mk>
