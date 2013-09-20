# Created by: ijliao
# $FreeBSD$

PORTNAME=	libdbi-drivers
DISTVERSION=	0.8.3-1
PORTREVISION=	5
CATEGORIES=	databases devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.8.3-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drivers for libdbi

LIB_DEPENDS=	dbi.1:${PORTSDIR}/databases/libdbi

USE_GNOME=	lthack
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-static \
		--with-dbi-incdir=${LOCALBASE}/include/dbi
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${DISTVERSION}

OPTIONS_MULTI=	DRIVER
OPTIONS_MULTI_DRIVER=	MYSQL MSQL PGSQL SQLITE2 SQLITE3 FIREBIRD FREETDS

OPTIONS_DEFAULT=	MYSQL PGSQL SQLITE3
SQLITE2_DESC=	SQLite 2 Database

.if defined(.PARSEDIR)
USE_GMAKE=	yes
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MMSQL}
LIB_DEPENDS+=	msql.1:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql
PLIST_SUB+=	MSQL=""
.else
PLIST_SUB+=	MSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE2}
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_ARGS+=	--with-sqlite
PLIST_SUB+=	SQLITE2=""
.else
PLIST_SUB+=	SQLITE2="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE3}
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-sqlite3
PLIST_SUB+=	SQLITE3=""
.else
PLIST_SUB+=	SQLITE3="@comment "
.endif

.if ${PORT_OPTIONS:MFIREBIRD}
LIB_DEPENDS+=	gds.2:${PORTSDIR}/databases/firebird20-client
CONFIGURE_ARGS+=	--with-firebird
PLIST_SUB+=	FIREBIRD=""
.else
PLIST_SUB+=	FIREBIRD="@comment "
.endif

.if ${PORT_OPTIONS:MFREETDS}
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

.include <bsd.port.mk>
