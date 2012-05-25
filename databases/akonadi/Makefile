# New ports collection Makefile for:	akonadi
# Date created:				2008-01-20
# Whom:					miwi
#
# $FreeBSD$

PORTNAME=	akonadi
PORTVERSION=	1.7.2
CATEGORIES=	databases kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/src/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Storage server for KDE-Pim

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/lgpl-license

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs
# Let process generate meaningful backtrace on core dump.
LIB_DEPENDS+=	execinfo.1:${PORTSDIR}/devel/libexecinfo
BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib network qtestlib dbus gui sql \
		qmake_build moc_build rcc_build uic_build
USE_KDE4=	kdehier kdeprefix sharedmime automoc4 soprano
KDE4_BUILDENV=	yes
CMAKE_ARGS+=	-DAKONADI_BUILD_TESTS:BOOL=FALSE \
		-DINSTALL_QSQLITE_IN_QT_PREFIX:BOOL=TRUE \
		-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB+=	QT_PREFIX=${QT_PREFIX}

OPTIONS=	MYSQL "Install MySQL plugin and server (recommended)" on \
		PGSQL "Install PostgreSQL plugin" off \
		SQLITE "Enable SQLite backend (unused)" off

.include <bsd.port.options.mk>

.ifndef(WITHOUT_MYSQL)
USE_MYSQL=	server
QT_COMPONENTS+=	sql-mysql_run
.endif

.ifdef(WITH_PGSQL)
# Do not add a dependency on PostgreSQL server as someone preferring
# it over MySQL might like to use some advanced configuration like a
# remote server.
#USE_PGSQL=	server
QT_COMPONENTS+=	sql-pgsql_run
.endif

.ifdef(WITH_SQLITE)
USE_SQLITE=	3
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

post-patch:
.ifndef(WITH_SQLITE)
	${REINPLACE_CMD} -e '/find_package(Sqlite)/ d' \
		${PATCH_WRKSRC}/CMakeLists.txt
.endif
	${REINPLACE_CMD} -e '/akonadi.pc/ s|pkgconfig|../libdata/pkgconfig|' \
		${PATCH_WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e '/find_program/ s|mysqld|mysqld_safe ${LOCALBASE}/bin|g' \
		${PATCH_WRKSRC}/server/CMakeLists.txt
	# Prevent updating MIME during build.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/CMakeLists.txt

post-install:
	@-update-mime-database ${KDE4_PREFIX}/share/mime

.include <bsd.port.mk>
