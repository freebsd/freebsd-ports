# New ports collection makefile for:	libpreps
# Date created:		Fri Mar 19 14:27:30 EET 2004
# Whom:			shadow@psoft.net
#
# $FreeBSD$
#

PORTNAME=	libpreps
PORTVERSION=	1.9.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://webpages.charter.net/stuffle/linux/preps/
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	prep

MAINTAINER=	shadow@psoft.net
COMMENT=	Problem reporting system

CONFLICTS=	libpreps-1.6.*
LATEST_LINK=	libpreps-devel

INSTALLS_SHLIB=	yes

USE_PGSQL=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	glib12

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=--with-pgsqldir=${LOCALBASE} --with-plpgsqldir=${LOCALBASE}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SERVER)
CONFIGURE_ARGS+=--disable-server
PKGNAMESUFFIX=	-client
PLIST_SUB+=	SERVER="@comment "
.else
MAN1=		create_prepsdb.1 update_prepsdb.1
PLIST_SUB+=	SERVER=""
.endif

# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/postmaster)
PGSQL_VER!=	${LOCALBASE}/bin/postmaster -V | \
		${SED} -n 's/postmaster.*PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif
PGSQL_PORT=	${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
BUILD_DEPENDS+=	postgres:${PGSQL_PORT}
RUN_DEPENDS+=	postgres:${PGSQL_PORT}

.include <bsd.port.post.mk>
