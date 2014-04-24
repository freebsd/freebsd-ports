# Created by: ijliao
# $FreeBSD$

PORTNAME=	libdbi-drivers
DISTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	databases devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drivers for libdbi

LIB_DEPENDS=	libdbi.so:${PORTSDIR}/databases/libdbi

USES=		gmake libtool:keepla
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-dbi-incdir=${LOCALBASE}/include/dbi
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${DISTVERSION}

OPTIONS_MULTI=	DRIVER
OPTIONS_MULTI_DRIVER=	MYSQL PGSQL SQLITE3

OPTIONS_DEFAULT=	MYSQL PGSQL SQLITE3

OPTIONS_SUB=	yes
MYSQL_USE=	MYSQL=yes
MYSQL_CONFIGURE_WITH=	mysql
PGSQL_USE=	PGSQL=yes
PGSQL_CONFIGURE_WITH=	pgsql
SQLITE3_LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3
SQLITE3_CONFIGURE_WITH=	sqlite3

PLIST_SUB+=	INGRES="@comment "
PLIST_SUB+=	ORACLE="@comment "

post-patch:
	@${REINPLACE_CMD} -e 's|-O20|${CFLAGS}|g' \
		-e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
	@${TOUCH} ${WRKSRC}/drivers/*/dbd_*/*

.include <bsd.port.mk>
