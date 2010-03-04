# New ports collection makefile for:	pg_rman
# Date created:				4 March 2010
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pg_rman
PORTVERSION=	1.1.2
CATEGORIES=	databases
MASTER_SITES=	http://pg-rman.googlecode.com/files/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Online backup and restore tool for PostgreSQL

USE_GMAKE=	yes
USE_PGSQL=	YES
WANT_PGSQL_VER?=83
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ARGS=	USE_PGXS=1
PLIST_FILES=	bin/pg_rman

.include <bsd.port.pre.mk>

BUILD_DEPENDS=	${LOCALBASE}/lib/libpgport.a:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server

.include <bsd.port.post.mk>
