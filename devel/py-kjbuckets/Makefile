# Ports collection Makefile for:	kjbuckets
# Version required:			2.2
# Date created:				03/27/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=		kjb
PKGNAME=		py-kjbuckets-2.2
CATEGORIES=		devel
MASTER_SITES=		http://www.chordate.com/kjbuckets/             \
			http://www.nectar.com/distfiles/

MAINTAINER=		nectar@FreeBSD.org

BUILD_DEPENDS=		python:${PORTSDIR}/lang/python
RUN_DEPENDS=		python:${PORTSDIR}/lang/python

MAKEFILE=		makefile
WRKSRC=			${WRKDIR}

do-install:
	${MKDIR} ${PREFIX}/lib/python1.5/site-packages
	${INSTALL_DATA} ${WRKSRC}/kjbucketsmodule.so                   \
		${PREFIX}/lib/python1.5/site-packages/
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/kjbuckets.html ${PREFIX}/share/doc/
.endif

.include <bsd.port.mk>
