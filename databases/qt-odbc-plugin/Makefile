# -*-mode: makefile-*-
# New ports collection makefile for:		qt-odbc-plugin
# Date created:                         	31 December 2003
# Whom:					Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	qt-${DB}-plugin
PORTVERSION=	3.3.4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_QT}
DISTNAME=	qt-x11-free-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@freebsd.org
COMMENT=	A plugin for QT to connect to ODBC-compatible databases

DB=		odbc

LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC \
		qt-mt:${PORTSDIR}/x11-toolkits/qt33

USE_BZIP2=	yes
PLUGIN=		plugins/src/sqldrivers/${DB}
DRIVER=		src/sql/drivers/${DB}
EXTRACT_AFTER_ARGS?=| ${TAR} -xf - ${DISTNAME}/${PLUGIN} \
		${DISTNAME}/${DRIVER} ${DISTNAME}/src/sql/drivers/cache
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	DB="${DB}" DRIVER="${DRIVER}" PLUGIN="${PLUGIN}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
USE_X_PREFIX=	yes
PLIST_SUB=	DB=${DB}

.include <bsd.port.mk>
