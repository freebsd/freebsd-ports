# $FreeBSD$

PORTNAME=	ludia
PORTVERSION=	1.5.2
CATEGORIES=	databases
MASTER_SITES=	SFJP
MASTER_SITE_SUBDIR=	ludia/38430

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	PostgreSQL extension for full-text search indexing

BUILD_DEPENDS=	senna-cfg:${PORTSDIR}/textproc/senna
RUN_DEPENDS=	senna-cfg:${PORTSDIR}/textproc/senna

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_PGSQL=	server
# WANT_PGSQL_VER=	83

BROKEN=		Does not work with postgresql-9.0 or postgresql-8.4

# let configure find postgres stuff in non-standard places
CONFIGURE_ARGS+=--with-pgconfigdir=${LOCALBASE}/bin \
  --with-pgbindir=${LOCALBASE}/bin \
  --with-pgincludedir=${LOCALBASE}/include \
  --with-pgincludeserverdir=${LOCALBASE}/include/postgresql/server \
  --with-pglibdir=${LOCALBASE}/lib \
  --with-pgpkglibdir=${LOCALBASE}/lib/postgresql \
  --with-pgsharedir=${LOCALBASE}/share/postgresql

NO_STAGE=	yes
.include <bsd.port.mk>
