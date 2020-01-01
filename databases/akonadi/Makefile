# $FreeBSD$

PORTNAME=	akonadi
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	databases kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Storage server for KDE-Pim

LICENSE=	LGPL21

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs
# Let process generate meaningful backtrace on core dump.
BUILD_DEPENDS=	xsltproc:textproc/libxslt

CONFLICTS=	akonadi-[0-9]* akonadi-kf5-git-[0-9]*

USES=		cmake compiler:c++11-lib gettext gnome kde:5 qt:5 \
		shared-mime-info tar:xz
USE_GNOME=	libxml2
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons ecm guiaddons i18n iconthemes itemmodels itemviews \
		kio service windowsystem widgetsaddons xmlgui \
		designerplugin_build designerplugin_run
USE_QT=		concurrent core dbus designer gui network sql testlib widgets xml \
		buildtools_build qmake_build
CMAKE_ARGS+=	-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	MYSQL

MYSQL_DESC=		Install MySQL Qt plugin and server
MYSQL_USES=	mysql:server qt:5
MYSQL_USE=		QT=sql-mysql_run
MYSQL_CMAKE_BOOL=	AKONADI_BUILD_MYSQL

PGSQL_DESC=		Install PostgreSQL Qt plugin
# Do not add a dependency on PostgreSQL server as someone preferring
# it over MySQL might like to use some advanced configuration, like a
# remote server.
#PGSQL_USE=	PGSQL=server
PGSQL_USES=	qt:5
PGSQL_USE=		QT=sql-pgsql_run
PGSQL_CMAKE_BOOL=	AKONADI_BUILD_PGSQL

SQLITE_DESC=		Enable SQLite backend
SQLITE_USES=		qt:5 sqlite:3
SQLITE_USE=		QT=sql-sqlite3_run
SQLITE_CMAKE_BOOL=	AKONADI_BUILD_QSQLITE

.include <bsd.port.options.mk>

# Multiple backends may be enabled, but there can be only
# one default. Set a default (the user can change it locally)
# based on the selected backends, preferring MySQL (if enabled).
#
# If you build this port with only a single backend selected,
# that one will be the default. This is useful for users of SQLite.
.if ${PORT_OPTIONS:MMYSQL}
CMAKE_ARGS+=	-DDATABASE_BACKEND=MYSQL
.else
.  if ${PORT_OPTIONS:MPGSQL}
CMAKE_ARGS+=	-DDATABASE_BACKEND=POSTGRES
.  else
.    if ${PORT_OPTIONS:MSQLITE}
CMAKE_ARGS+=	-DDATABASE_BACKEND=SQLITE
.    else
# Nothing else selected, very odd
CMAKE_ARGS+=	-DDATABASE_BACKEND=MYSQL
.    endif
.  endif
.endif

post-patch:
# To avoid overflow, MySQL settings need to be lower than
# INT_MAX / kern.hz. This setting assumes kern.hz=2000, and
# it's nothing but a temporary hack.
	${REINPLACE_CMD} -e '/wait_timeout/ s|31536000|1073741|' \
		${PATCH_WRKSRC}/src/server/storage/*.conf

.include <bsd.port.mk>
