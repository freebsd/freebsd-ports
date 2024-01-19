# This should be sub-packages...

PORTNAME=	base
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	databases
PKGNAMEPREFIX=	qt6-
PKGNAMESUFFIX=	_sqldriver-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt base (${FLAVOR} sqldriver)

FLAVORS=	sqlite mysql odbc psql
FLAVOR?=	sqlite

WRKSRC_SUBDIR=	src/plugins/sqldrivers

USES=		cmake compiler:c++17-lang pkgconfig qt-dist:6 \
		${${FLAVOR}_USES}
USE_QT=		base

CMAKE_ARGS=	-DCMAKE_PROJECT_NAME=Qt6${FLAVOR}
CMAKE_ON=	FEATURE_sql_${FLAVOR} ${${FLAVOR}_CMAKE_ON}
CMAKE_OFF=	${FLAVORS:N${FLAVOR}:S/^/FEATURE_sql_/} \
		FEATURE_sql_ibase

mysql_USES=		mysql
odbc_LIB_DEPENDS=	libodbc.so:databases/unixODBC
psql_USES=		pgsql
sqlite_USES=		sqlite:3
sqlite_CMAKE_ON=	QT_FEATURE_system_sqlite
${FLAVOR}_PLIST=	${.CURDIR}/pkg-plist.${FLAVOR}

.if ${FLAVOR:U} == mysql
IGNORE_WITH_MYSQL=	105m 106m 1011m
.endif

.include <bsd.port.mk>
