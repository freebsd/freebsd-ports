# Created by: miwi
# $FreeBSD$

PORTNAME=	akonadi
PORTVERSION=	1.10.3
CATEGORIES=	databases kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/src
DIST_SUBDIR=	KDE
DISTVERSIONSUFFIX=	-1
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Storage server for KDE-Pim

LICENSE=	LGPL21

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs
# Let process generate meaningful backtrace on core dump.
LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_KDE4=	kdehier kdeprefix sharedmime automoc4 soprano
USES=		cmake:outsource
USE_QT4=	corelib dbus gui network qtestlib_build sql xml \
		moc_build qmake_build rcc_build uic_build
USE_BZIP2=	yes
CMAKE_ARGS+=	-DAKONADI_BUILD_TESTS:BOOL=FALSE \
		-DINSTALL_QSQLITE_IN_QT_PREFIX:BOOL=TRUE \
		-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"
USE_LDCONFIG=	yes

PLIST_SUB+=	QT_PREFIX=${QT_PREFIX}

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE

MYSQL_DESC=	Install MySQL Qt plugin and server
PGSQL_DESC=	Install PostgreSQL Qt plugin
SQLITE_DESC=	Enable SQLite backend

OPTIONS_DEFAULT=	MYSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	server
USE_QT4+=	sql-mysql_run
.endif

.if ${PORT_OPTIONS:MPGSQL}
# Do not add a dependency on PostgreSQL server as someone preferring
# it over MySQL might like to use some advanced configuration, like a
# remote server.
#USE_PGSQL=	server
USE_QT4+=	sql-pgsql_run
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	3
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

post-patch:
.if ${PORT_OPTIONS:MSQLITE} == ""
	${REINPLACE_CMD} -e '/find_package(Sqlite)/ d' \
		${PATCH_WRKSRC}/CMakeLists.txt
.endif
	${REINPLACE_CMD} -e '/akonadi.pc/ s|pkgconfig|../libdata/pkgconfig|' \
		${PATCH_WRKSRC}/CMakeLists.txt
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
