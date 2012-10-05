# New ports collection makefile for:	py-dynrules
# Date created:		2008-12-22
# Whom:			Marcus von Appen <mva@sysfault.org>
#
# $FreeBSD$
#

PORTNAME=	dynrules
PORTVERSION=	0.0.15
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	python-${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Dynamic Scripting for adaptive AI systems

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/html
	@${TAR} -C ${WRKSRC}/doc/html -cf - . | \
		${TAR} -C ${DOCSDIR}/html -xf -
.endif

.include <bsd.port.mk>
