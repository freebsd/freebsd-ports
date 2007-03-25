# -*-mode: makefile-*-
# New ports collection makefile for:		qt-odbc-plugin
# Date created:                         	31 December 2003
# Whom:					Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	qt4-${DB}-plugin
PORTVERSION=	4.2.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_QT}
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@freebsd.org
COMMENT=	Qt ODBC database plugin

DB=		odbc

LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC \
		QtSql:${PORTSDIR}/databases/qt4-sql

#USE_BZIP2=	yes
DRIVER=		src/sql/drivers/${DB}
EXTRACT_AFTER_ARGS?=| ${TAR} -xf - \
		${DISTNAME}/${DRIVER}
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	DB="${DB}" DRIVER="${DRIVER}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB=	DB=${DB}

.include <bsd.port.mk>
