# New ports collection makefile for:	Ludia
# Date created:		January 5, 2008
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ludia
PORTVERSION=	1.5.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	ludia/32461

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	PostgreSQL extension for full-text search indexing

PGSQL_PORT=	${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
RUN_DEPENDS=	${LOCALBASE}/bin/postmaster:${PGSQL_PORT} \
		senna-cfg:${PORTSDIR}/textproc/senna
BUILD_DEPENDS=	${LOCALBASE}/bin/postmaster:${PGSQL_PORT} \
		senna-cfg:${PORTSDIR}/textproc/senna

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22
USE_PGSQL=	yes

.include <bsd.port.pre.mk>

# let configure find postgres stuff in non-standard places
CONFIGURE_ARGS+=--with-pgconfigdir=${LOCALBASE}/bin \
  --with-pgbindir=${LOCALBASE}/bin \
  --with-pgincludedir=${LOCALBASE}/include \
  --with-pgincludeserverdir=${LOCALBASE}/include/postgresql/server \
  --with-pglibdir=${LOCALBASE}/lib \
  --with-pgpkglibdir=${LOCALBASE}/lib/postgresql \
  --with-pgsharedir=${LOCALBASE}/share/postgresql

.include <bsd.port.post.mk>
