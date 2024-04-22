PORTNAME=	gammu
PORTVERSION=	1.42.0
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://dl.cihar.com/gammu/releases/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	GNU All Mobile Management Utilities
WWW=		https://wammu.eu/gammu/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake compiler:c++11-lang gettext gnome iconv pkgconfig \
		shebangfix tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes
SHEBANG_FILES=	utils/gammu-config utils/jadmaker
bash_CMD=	/bin/sh

CMAKE_ARGS=	-DINSTALL_LIBDATA_DIR:PATH=${PREFIX}/libdata \
		-DINSTALL_MAN_DIR:PATH=${PREFIX}/share/man

PLIST_SUB+=	VERSION=${PORTVERSION}

PORTDOCS=	*

OPTIONS_DEFINE=		BASH DBI DOCS MYSQL ODBC PGSQL
OPTIONS_DEFAULT=	BASH
OPTIONS_SUB=		yes

DBI_DESC=	Database support via LibDBI

BASH_BUILD_DEPENDS=	bash:shells/bash
BASH_RUN_DEPENDS=	${BASH_BUILD_DEPENDS}
BASH_CMAKE_OFF=		-DINSTALL_BASH_COMPLETION:BOOL=OFF
DBI_LIB_DEPENDS=	libdbi.so:databases/libdbi
DBI_CMAKE_OFF=		-DWITH_LibDBI:BOOL=OFF
MYSQL_USES=		mysql
MYSQL_CMAKE_OFF=	-DWITH_MySQL:BOOL=OFF
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
ODBC_CMAKE_OFF=		-DWITH_ODBC:BOOL=OFF
PGSQL_USES=		pgsql
PGSQL_CMAKE_OFF=	-DWITH_Postgres:BOOL=OFF

.include <bsd.port.mk>
