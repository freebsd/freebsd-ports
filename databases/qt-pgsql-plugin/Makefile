# -*-mode: makefile-*-
# New ports collection makefile for:	qt-pgsql-plugin
# Date created:				5 August 2003
# Whom:					Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	qt-pgsql-plugin
PORTREVISION=	0
CATEGORIES=	databases x11-toolkits

MAINTAINER=	kde@freebsd.org
COMMENT=	A plugin for QT to connect to PostgreSQL-Databases

LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql7

USE_QT_VER=	3
QT_NONSTANDARD=	yes

LDCONFIG_DIRS=	%%PREFIX%%/lib/plugins/sqldrivers
CONFIGURE_ARGS=	-plugin-sql-psql
CONFIGURE_ENV=	${ECHO} yes | MOC="${MOC}" CPPFLAGS="${QTCPPFLAGS}" \
		LIBS="${QTCFGLIBS}" LOCALBASE="${LOCALBASE}"

BUILD_PLUGIN_ONLY=	yes

do-build:
	cd ${WRKSRC}/plugins/src/sqldrivers/psql; \
		${SETENV} ${MAKE_ENV} ${GMAKE}

do-install:
	@${MKDIR} ${PREFIX}/lib/plugins/sqldrivers
	${INSTALL_DATA} ${WRKSRC}/plugins/sqldrivers/libqsqlpsql.so \
		${PREFIX}/lib/plugins/sqldrivers/

.include "../../x11-toolkits/qt31/Makefile"
