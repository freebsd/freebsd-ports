# Created by: miwi
# $FreeBSD$

PORTNAME=	akonadi
PORTVERSION=	1.13.0
PORTREVISION=	10
CATEGORIES=	databases kde
MASTER_SITES=	KDE/stable/${PORTNAME}/src
PKGNAMESUFFIX=	-kde4
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Storage server for KDE-Pim

LICENSE=	LGPL21

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs
# Let process generate meaningful backtrace on core dump.
BUILD_DEPENDS=	xsltproc:textproc/libxslt

USES=		cmake kde:4 qt:4 shared-mime-info \
		compiler:c++11-lang pathfix tar:bzip2
USE_KDE=	automoc4 soprano
USE_QT=		corelib dbus gui network qtestlib_build sql xml \
		moc_build qmake_build rcc_build uic_build
CMAKE_ARGS+=	-DAKONADI_BUILD_TESTS:BOOL=FALSE \
		-DINSTALL_QSQLITE_IN_QT_PREFIX:BOOL=TRUE \
		-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"
USE_LDCONFIG=	yes

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_SUB=	yes # SQLITE

MYSQL_DESC=	Install MySQL Qt plugin and server
MYSQL_USE=	QT=sql-mysql_run
MYSQL_USES=	mysql:server qt:4

PGSQL_DESC=	Install PostgreSQL Qt plugin
# Do not add a dependency on PostgreSQL server as someone preferring
# it over MySQL might like to use some advanced configuration, like a
# remote server.
#PGSQL_USE=	PGSQL=server
PGSQL_USES=	qt:4
PGSQL_USE=	QT=sql-pgsql_run

SQLITE_DESC=	Enable SQLite backend
SQLITE_USES=	sqlite:3
SQLITE_CMAKE_OFF=	-DAKONADI_BUILD_QSQLITE=off

OPTIONS_DEFAULT=	MYSQL

post-patch:
	${REINPLACE_CMD} -e '/find_program/ s|mysqld|mysqld_safe ${LOCALBASE}/bin|g' \
		${PATCH_WRKSRC}/server/CMakeLists.txt
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${PATCH_WRKSRC}/server/src/storage/dbconfigmysql.cpp
# To avoid overflow, MySQL settings need to be lower than
# INT_MAX / kern.hz. This setting assumes kern.hz=2000, and
# it's nothing but a temporary hack.
	${REINPLACE_CMD} -e '/wait_timeout/ s|31536000|1073741|' \
		${PATCH_WRKSRC}/server/src/storage/*.conf
# Prevent updating MIME during build.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d' \
		-e '/find_package(SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
