# ex:ts=8
# Ports collection makefile for:	libdbi-drivers
# Date created:			Oct 30, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libdbi-drivers
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Drivers for libdbi

LIB_DEPENDS=	dbi.0:${PORTSDIR}/databases/libdbi

USE_GNOME=	gnometarget lthack
USE_LIBTOOL_VER=	15
CONFIGURE_ARGS=	--disable-static \
		--with-dbi-incdir=${LOCALBASE}/include/dbi

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

OPTIONS=	MYSQL	"With MySQL Driver" on \
		MSQL	"With MSQL Driver" off \
		PGSQL	"With PostgreSQL Driver" on \
		SQLITE	"With SQLite Driver" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MYSQL) && defined(WITHOUT_PGSQL) && defined(WITHOUT_SQLITE) && defined(WITHOUT_MSQL)
IGNORE=		You must choose at least one driver
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_SQLITE)
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_ARGS+=	--with-sqlite
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if defined(WITH_MSQL)
LIB_DEPENDS+=	msql.1:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql
PLIST_SUB+=	MSQL=""
.else
PLIST_SUB+=	MSQL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O20|$$CFLAGS|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
