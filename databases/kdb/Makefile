PORTNAME=		kdb
DISTVERSION=		3.2.0
PORTREVISION=		15
CATEGORIES=		databases kde
MASTER_SITES=		KDE/stable/${PORTNAME}/src
DIST_SUBDIR=		KDE/${PORTNAME}

PATCH_SITES=		https://invent.kde.org/libraries/kdb/-/commit/
PATCHFILES=		b36d74f13a1421437a725fb74502c993c359392a.diff:-p1

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Database connectivity and creation framework
WWW=		https://community.kde.org/KDb

LIB_DEPENDS=		libicuuc.so:devel/icu

USES=		cmake compiler:c++11-lang kde:5 python qt:5 tar:xz
USE_KDE=	coreaddons i18n \
		ecm:build
USE_QT=		core gui network widgets xml \
		buildtools:build qmake:build

# In the future, these options will be moved into slave ports
OPTIONS_DEFINE=		SQLITE MYSQL PGSQL
OPTIONS_SUB=		YES
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

SQLITE_USES=		sqlite
SQLITE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Sqlite
MYSQL_USES=		mysql
MYSQL_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_MySQL
PGSQL_USES=		pgsql
PGSQL_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_PostgreSQL

.include <bsd.port.mk>
