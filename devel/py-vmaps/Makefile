# ex:ts=8
# Ports collection makefile for:	py-vmaps
# Date created:			Mar 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vmaps
PORTVERSION=	1.1
CATEGORIES=	devel python
MASTER_SITES=	http://sovereignit.com/Vmaps/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Vmaps-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Arrays on mmap()

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Vmaps
PYDISTUTILS_PKGVERSION=	1.0

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Vmaps.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
