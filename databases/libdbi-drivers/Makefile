# Ports collection makefile for:	libdbi-drivers
# Date created:				Oct 30, 2003
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	libdbi-drivers
DISTVERSION=	0.8.3-1
PORTREVISION=	3
CATEGORIES=	databases devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.8.3-1

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Drivers for libdbi

LIB_DEPENDS=	dbi.0:${PORTSDIR}/databases/libdbi

USE_GNOME=	gnometarget lthack
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--disable-static \
		--with-dbi-incdir=${LOCALBASE}/include/dbi
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${DISTVERSION}

OPTIONS=	MYSQL		"With MySQL Driver" 		on  \
		MSQL		"With MSQL Driver" 		off \
		PGSQL		"With PostgreSQL Driver"	on  \
		SQLITE2		"With SQLite 2 Driver" 		off \
		SQLITE3		"With SQLite 3 Driver" 		on  \
		FIREBIRD	"With Firebird Driver (BROKEN)"	off \
		FREETDS		"With FreeTDS Driver"		off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MYSQL) && defined(WITHOUT_MSQL) && defined(WITHOUT_PGSQL) \
	&& defined(WITHOUT_SQLITE2) && defined(WITHOUT_SQLITE3) \
	&& defined(WITHOUT_FIREBIRD) && defined(WITHOUT_FREETDS)
IGNORE=		choose at least one driver
.endif

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_MSQL)
LIB_DEPENDS+=	msql.1:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql
PLIST_SUB+=	MSQL=""
.else
PLIST_SUB+=	MSQL="@comment "
.endif

.if !defined(WITHOUT_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_SQLITE2)
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_ARGS+=	--with-sqlite
PLIST_SUB+=	SQLITE2=""
.else
PLIST_SUB+=	SQLITE2="@comment "
.endif

.if !defined(WITHOUT_SQLITE3)
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-sqlite3
PLIST_SUB+=	SQLITE3=""
.else
PLIST_SUB+=	SQLITE3="@comment "
.endif

.if defined(WITH_FIREBIRD)
LIB_DEPENDS+=	gds.2:${PORTSDIR}/databases/firebird20-client
CONFIGURE_ARGS+=	--with-firebird
PLIST_SUB+=	FIREBIRD=""
.else
PLIST_SUB+=	FIREBIRD="@comment "
.endif

.if defined(WITH_FREETDS)
LIB_DEPENDS+=	tds.5:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=	--with-freetds
PLIST_SUB+=	FREETDS=""
.else
PLIST_SUB+=	FREETDS="@comment "
.endif

PLIST_SUB+=	INGRES="@comment "
PLIST_SUB+=	ORACLE="@comment "

post-patch:
	@${REINPLACE_CMD} -e 's|-O20|${CFLAGS}|g' \
		-e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
	@${TOUCH} ${WRKSRC}/drivers/*/dbd_*/*

.include <bsd.port.post.mk>
