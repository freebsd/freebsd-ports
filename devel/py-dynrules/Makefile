# New ports collection makefile for:	py-dynrules
# Date created:		2008-12-22
# Whom:			Marcus von Appen <mva@sysfault.org>
#
# $FreeBSD$
#

PORTNAME=	dynrules
PORTVERSION=	0.0.13
CATEGORIES=	devel python
MASTER_SITES=	http://sysfault.org/projects/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Dynamic Scripting for adaptive AI systems

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	dynrules

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/html
	@${TAR} -C ${WRKSRC}/doc/html -cf - . | \
		${TAR} -C ${DOCSDIR}/html -xf -
.endif

.include <bsd.port.mk>
