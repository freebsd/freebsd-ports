# Created by: ijliao
# $FreeBSD$

PORTNAME=	libdbi-drivers
DISTVERSION=	0.8.3-1
PORTREVISION=	5
CATEGORIES=	databases devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.8.3-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drivers for libdbi

LIB_DEPENDS=	libdbi.so:${PORTSDIR}/databases/libdbi

USE_GNOME=	lthack
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-static \
		--with-dbi-incdir=${LOCALBASE}/include/dbi
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${DISTVERSION}

OPTIONS_MULTI=	DRIVER
OPTIONS_MULTI_DRIVER=	MYSQL MSQL PGSQL SQLITE2 SQLITE3 FIREBIRD FREETDS

OPTIONS_DEFAULT=	MYSQL PGSQL SQLITE3
SQLITE2_DESC=	SQLite 2 Database

OPTIONS_SUB=	yes
MYSQL_USE=	MYSQL=yes
MYSQL_CONFIGURE_WITH=	mysql
MSQL_USE=	MSQL=yes
MSQL_CONFIGURE_WITH=	msql
PGSQL_USE=	PGSQL=yes
PGSQL_CONFIGURE_WITH=	pgsql
SQLITE2_LIB_DEPENDS=	libsqlite.so:${PORTSDIR}/databases/sqlite2
SQLITE2_CONFIGURE_WITH=	sqlite
SQLITE3_LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3
SQLITE3_CONFIGURE_WITH=	sqlite3
FIREBIRD_LIB_DEPENDS=	libgds.so:${PORTSDIR}/databases/firebird20-client
FIREBIRD_CONFIGURE_WITH=firebird
FREETDS_LIB_DEPENDS=	libtds.so:${PORTSDIR}/databases/freetds
FREETDS_CONFIGURE_WITH=	freetds

PLIST_SUB+=	INGRES="@comment "
PLIST_SUB+=	ORACLE="@comment "

.if defined(.PARSEDIR)
USES+=		gmake
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O20|${CFLAGS}|g' \
		-e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
	@${TOUCH} ${WRKSRC}/drivers/*/dbd_*/*

.include <bsd.port.mk>
