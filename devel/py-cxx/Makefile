# ex:ts=8
# New ports collection makefile for:	PyCXX
# Date created:			Oct 7, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cxx
PORTVERSION=	5.1r1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyCXX-V${PORTVERSION:S/r/-rc/}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Make it easier to extend Python with C++

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/PyCXX.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
