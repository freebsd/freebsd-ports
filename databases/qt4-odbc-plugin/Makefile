# -*-mode: makefile-*-
# New ports collection makefile for:		qt-odbc-plugin
# Date created:                         	31 December 2003
# Whom:					Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	qt4-${DB}-plugin
PORTVERSION=	${QT4_VERSION}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_QT}
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt ODBC database plugin

DB=		odbc

LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC

USE_QT_VER=	4
QT_COMPONENTS=	moc_build sql
QT_NONSTANDARD=	yes
MAKE_JOBS_SAFE=	yes

DRIVER=		src/sql/drivers/${DB}
PLUGIN=		src/plugins/sqldrivers/${DB}
EXTRACT_AFTER_ARGS?=| ${TAR} -xf - \
		${DISTNAME}/${DRIVER} \
		${DISTNAME}/${PLUGIN}
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	DB="${DB}" DRIVER="${DRIVER}" MOC="${MOC}" \
		PLUGIN="${PLUGIN}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		QT_INCDIR="${QT_INCDIR}" \
		QT_LIBDIR="${QT_LIBDIR}"
PLIST_SUB=	DB=${DB}

.include <bsd.port.mk>
