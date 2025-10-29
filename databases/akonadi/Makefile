PORTNAME=	akonadi
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	databases kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Storage server for KDE-Pim
WWW=		https://community.kde.org/KDE_PIM/Akonadi

LICENSE=	LGPL21

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libkaccounts6.so:net-im/kaccounts-integration \
		libaccounts-qt6.so:net-im/libaccounts-qt@qt6
# Let process generate meaningful backtrace on core dump.
BUILD_DEPENDS=	xsltproc:textproc/libxslt

USES=		cmake compiler:c++11-lib gettext gnome kde:6 qt:6 \
		shared-mime-info sqlite:3 tar:xz xorg
USE_GNOME=	libxml2
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons guiaddons i18n iconthemes itemmodels itemviews kio \
		service widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base \
		sqldriver-sqlite:run
USE_XORG=	x11
CMAKE_ARGS+=	-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include" \
		-DMYSQLD_EXECUTABLE:FILEPATH="${LOCALBASE}/libexec/mysqld" \
		-DMYSQLD_SCRIPTS_PATH:PATH="${LOCALBASE}/bin" \
		-DPOSTGRES_PATH:FILEPATH="${LOCALBASE}/bin/pg_ctl"

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS
OPTIONS_GROUP=		DB
OPTIONS_GROUP_DB=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL

MYSQL_DESC=		Install MySQL Qt plugin and server
MYSQL_USES=		mysql:server
MYSQL_USE=		QT=sqldriver-mysql:run

PGSQL_DESC=		Install PostgreSQL Qt plugin
PGSQL_USE=		QT=sqldriver-psql:run

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
CMAKE_ARGS+=	-DDATABASE_BACKEND:STRING="MYSQL"
.elif ${PORT_OPTIONS:MPGSQL}
CMAKE_ARGS+=	-DDATABASE_BACKEND:STRING="POSTGRES"
.endif

post-patch:
# To avoid overflow, MySQL settings need to be lower than
# INT_MAX / kern.hz. This setting assumes kern.hz=2000, and
# it's nothing but a temporary hack.
	${REINPLACE_CMD} -e '/wait_timeout/ s|31536000|1073741|' \
		${PATCH_WRKSRC}/src/server/storage/*.conf

.include <bsd.port.mk>
