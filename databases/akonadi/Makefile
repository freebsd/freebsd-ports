# $FreeBSD$

PORTNAME=	akonadi
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	databases kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Storage server for KDE-Pim

LICENSE=	LGPL21

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs
# Let process generate meaningful backtrace on core dump.
BUILD_DEPENDS=	xsltproc:textproc/libxslt

CONFLICTS=	akonadi-[0-9]* akonadi-kf5-git-[0-9]*

USES=		cmake compiler:c++11-lib gettext kde:5 \
		qt:5 shared-mime-info tar:xz
USE_GNOME=	libxml2
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons ecm guiaddons i18n iconthemes itemmodels itemviews \
		kio service windowsystem widgetsaddons xmlgui \
		designerplugin_build designerplugin_run
USE_QT=		core dbus designer gui network sql testlib widgets xml \
		buildtools_build qmake_build
CMAKE_ARGS+=	-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"

USE_LDCONFIG=	yes

OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_SUB=		yes

MYSQL_DESC=		Install MySQL Qt plugin and server
MYSQL_USES=	qt:5
MYSQL_USE=		MYSQL=server QT=sql-mysql_run

PGSQL_DESC=		Install PostgreSQL Qt plugin
# Do not add a dependency on PostgreSQL server as someone preferring
# it over MySQL might like to use some advanced configuration, like a
# remote server.
#PGSQL_USE=	PGSQL=server
PGSQL_USES=	qt:5
PGSQL_USE=		QT=sql-pgsql_run

SQLITE_DESC=		Enable SQLite backend
SQLITE_USES=		qt:5 sqlite:3
SQLITE_USE=		QT=sql-sqlite3_run
SQLITE_CMAKE_ON=	-DAKONADI_BUILD_QSQLITE:BOOL=ON
SQLITE_CMAKE_OFF=	-DAKONADI_BUILD_QSQLITE:BOOL=OFF

OPTIONS_DEFAULT=	MYSQL

OPTIONS_DEFINE=	DOCS

post-patch:
# To avoid overflow, MySQL settings need to be lower than
# INT_MAX / kern.hz. This setting assumes kern.hz=2000, and
# it's nothing but a temporary hack.
	${REINPLACE_CMD} -e '/wait_timeout/ s|31536000|1073741|' \
		${PATCH_WRKSRC}/src/server/storage/*.conf

.include <bsd.port.mk>
