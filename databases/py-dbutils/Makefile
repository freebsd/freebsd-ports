# New ports collection makefile for:   py-dbutils
# Date created:                2005-11-02
# Whom:                        Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	dbutils
PORTVERSION=	1.0
CATEGORIES=	databases python
MASTER_SITES=	http://www.w4py.org/downloads/DBUtils/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	DBUtils-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Providing solid, persistent and pooled connections to a database

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	DBUtils

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/DBUtils/Docs/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
