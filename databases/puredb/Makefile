# New ports collection makefile for:	puredb
# Date created:		01 Nov 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	puredb
PORTVERSION=	2.1
CATEGORIES=	databases
MASTER_SITES=	http://www.pureftpd.org/puredb/
DISTNAME=	pure-db-${PORTVERSION}

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Set of libraries for creating and reading constant databases

USE_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes

DOCS=		AUTHORS FORMAT_DESCR NEWS README

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
