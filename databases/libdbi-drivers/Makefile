# Created by: ijliao
# $FreeBSD$

PORTNAME=	libdbi-drivers
PORTVERSION=	0.9.0
PORTREVISION=	4
CATEGORIES=	databases devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drivers for libdbi

LIB_DEPENDS=	libdbi.so:databases/libdbi

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-dbi-incdir=${LOCALBASE}/include \
		--with-dbi-dbdir=/var/lib/libdbi
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${DISTVERSION}
INSTALL_TARGET=	install-strip

PORTDOCS=	*

PLIST_DIRS=	/var/lib/libdbi/firebird \
		/var/lib/libdbi/sqlite \
		/var/lib/libdbi/sqlite3 \
		/var/lib/libdbi \
		/var/lib

OPTIONS_DEFINE=	DOCS
OPTIONS_MULTI=	DRIVER
OPTIONS_MULTI_DRIVER=	MYSQL PGSQL SQLITE3
OPTIONS_DEFAULT=	MYSQL PGSQL SQLITE3
OPTIONS_SUB=	yes

MYSQL_USE=	MYSQL=yes
MYSQL_CONFIGURE_WITH=	mysql
MYSQL_PLIST_FILES=	lib/dbd/libdbdmysql.so
PGSQL_USES=	pgsql
PGSQL_CONFIGURE_WITH=	pgsql
PGSQL_PLIST_FILES=	lib/dbd/libdbdpgsql.so
SQLITE3_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3
SQLITE3_CONFIGURE_WITH=	sqlite3
SQLITE3_PLIST_FILES=	lib/dbd/libdbdsqlite3.so

post-patch:
	@${REINPLACE_CMD} -e 's|-O20|${CFLAGS}|g' \
		-e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
	@${TOUCH} ${WRKSRC}/drivers/*/dbd_*/*

.include <bsd.port.mk>
