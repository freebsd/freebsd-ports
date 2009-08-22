# New ports collection makefile for:    pychecker
# Date created:         		13 April 2001
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pychecker
PORTVERSION=	0.8.18
CATEGORIES=	devel python
MASTER_SITES=	SF

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Python source code checking tool to help hunting common bugs

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyChecker

DOCS=		CHANGELOG COPYRIGHT KNOWN_BUGS MAINTAINERS README TODO VERSION

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
