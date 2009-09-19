# Ports collection Makefile for:	PyGreSQL
# Date created:				2/22/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	PyGreSQL
PORTVERSION=	4.0
PORTEPOCH=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP \
		ftp://ftp.pygresql.org/pub/distrib/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python interface to PostgreSQL, both classic and DP-API 2.0

USE_PGSQL=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
DATETIME_DEP=	${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
