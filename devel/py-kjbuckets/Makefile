# Ports collection Makefile for:	kjbuckets
# Date created:				03/27/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		kjbuckets
PORTVERSION=		2.2
CATEGORIES=		devel python
MASTER_SITES=		http://www.chordate.com/kjbuckets/             \
			http://www.nectar.com/distfiles/
PKGNAMEPREFIX=		py-
DISTNAME=		kjb

MAINTAINER=		nectar@FreeBSD.org

BUILD_DEPENDS=		python:${PORTSDIR}/lang/python
RUN_DEPENDS=		python:${PORTSDIR}/lang/python

NO_WRKSUBDIR=		yes
MAKEFILE=		makefile

do-install:
	${MKDIR} ${PREFIX}/lib/python1.5/site-packages
	${INSTALL_DATA} ${WRKSRC}/kjbucketsmodule.so                   \
		${PREFIX}/lib/python1.5/site-packages/
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/kjbuckets.html ${PREFIX}/share/doc/
.endif

.include <bsd.port.mk>
