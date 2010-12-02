# -*-mode: makefile-*-
# New ports collection makefile for:		qt-sqlite-plugin
# Date created:                         	27 February 2004
# Whom:                                        	Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	qt4-${DB}-plugin
DISTVERSION=	${QT4_VERSION}
CATEGORIES=	databases

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt SQLite 3.x database plugin

DB=		sqlite
DISTINFO_FILE=	${PORTSDIR}/devel/qt4/distinfo

LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3

USE_QT_VER=	4
QT_COMPONENTS=	moc_build sql
QT_NONSTANDARD=	yes
QT_DIST=	yes
MAKE_JOBS_SAFE=	yes

DRIVER=		src/sql/drivers/${DB}
PLUGIN=		src/plugins/sqldrivers/${DB}
EXTRACT_AFTER_ARGS?=| ${TAR} -xf - \
		${DISTNAME}/${DRIVER} ${DISTNAME}/${PLUGIN} \
		${DISTNAME}/include/QtSql \
		${DISTNAME}/src/sql/kernel
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	DB="${DB}" DRIVER="${DRIVER}" MOC="${MOC}" \
		PLUGIN="${PLUGIN}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		QT_INCDIR="${QT_INCDIR}" \
		QT_LIBDIR="${QT_LIBDIR}"
PLIST_SUB=	DB=${DB}

.include <bsd.port.mk>
