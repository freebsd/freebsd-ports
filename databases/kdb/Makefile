# $FreeBSD$

PORTNAME=		kdb
DISTVERSION=		3.1.0
PORTREVISION=		3
CATEGORIES=		databases kde
MASTER_SITES=		KDE/stable/${PORTNAME}/src
DIST_SUBDIR=		KDE/${PORTNAME}

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Database connectivity and creation framework

LIB_DEPENDS=		libicuuc.so:devel/icu

USES=			cmake:outsource compiler:c++11-lang gettext kde:5 \
			python:2.7 qt:5 tar:xz
USE_KDE=		coreaddons ecm i18n
USE_QT=			core gui network widgets xml \
			buildtools_build qmake_build

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
