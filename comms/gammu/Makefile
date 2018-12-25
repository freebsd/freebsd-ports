# Created by: Kirill Bezzubets <kirill@solaris.ru>
# $FreeBSD$

PORTNAME=	gammu
PORTVERSION=	1.39.0
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	http://dl.cihar.com/gammu/releases/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	GNU All Mobile Management Utilities

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

CMAKE_ARGS=	-DINSTALL_LIBDATA_DIR:PATH=${PREFIX}/libdata \
		-DINSTALL_MAN_DIR:PATH=${PREFIX}/man

USES=		cmake compiler:c++11-lang gettext iconv pkgconfig shebangfix tar:xz
SHEBANG_FILES=	utils/jadmaker utils/gammu-config
bash_CMD=	/bin/sh
USE_GNOME=	glib20
USE_LDCONFIG=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}

PORTDOCS=	*

OPTIONS_DEFINE=		BASH DBI DOCS PGSQL MYSQL ODBC
OPTIONS_DEFAULT=	BASH
OPTIONS_SUB=		yes

BASH_BUILD_DEPENDS=	bash:shells/bash
BASH_RUN_DEPENDS=	${BASH_BUILD_DEPENDS}
BASH_CMAKE_OFF=		-DINSTALL_BASH_COMPLETION:BOOL=OFF
DBI_DESC=		Database support via LibDBI
DBI_LIB_DEPENDS=	libdbi.so:databases/libdbi
DBI_CMAKE_OFF=		-DWITH_LibDBI:BOOL=OFF
PGSQL_USES=		pgsql
PGSQL_CMAKE_OFF=	-DWITH_Postgres:BOOL=OFF
MYSQL_USES=		mysql
MYSQL_CMAKE_OFF=	-DWITH_MySQL:BOOL=OFF
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
ODBC_CMAKE_OFF=		-DWITH_ODBC:BOOL=OFF

.include <bsd.port.mk>
