# ex:ts=8
# Ports collection makefile for:	libdbi-drivers
# Date created:			Oct 30, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libdbi-drivers
PORTVERSION=	0.7.0
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	libdbi drivers

LIB_DEPENDS=	dbi.0:${PORTSDIR}/databases/libdbi

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbi-incdir=${LOCALBASE}/include/dbi

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql-client$
CONFIGURE_ARGS+=	--with-pgsql
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_SQLITE)
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite
CONFIGURE_ARGS+=	--with-sqlite
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

#.if defined(WITH_MSQL)
#LIB_DEPENDS+=	msql.1:${PORTSDIR}/databases/msql
#CONFIGURE_ARGS+=	--with-msql
#PLIST_SUB+=	MSQL=""
#.else
#PLIST_SUB+=	MSQL="@comment "
#.endif

.include <bsd.port.mk>
