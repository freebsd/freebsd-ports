# Ports collection Makefile for:	kjbuckets
# Date created:				03/27/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		kjbuckets
PORTVERSION=		2.2
CATEGORIES=		devel python
MASTER_SITES=		http://www.chordate.com/kjbuckets/
PKGNAMEPREFIX=		py-
DISTNAME=		kjb

MAINTAINER=		nectar@FreeBSD.org

USE_PYTHON=		yes
NO_WRKSUBDIR=		yes
MAKE_ENV=		PYTHON_VERSION=${PYTHON_VERSION}
MAKEFILE=		makefile

do-install:
	${MKDIR} ${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/kjbucketsmodule.so ${PYTHON_SITELIBDIR}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/kjbuckets.html ${PREFIX}/share/doc/
.endif

.include <bsd.port.mk>
