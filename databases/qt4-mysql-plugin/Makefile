# -*-mode: makefile-*-
# New ports collection makefile for:	qt-mysql-plugin
# Date created:				20 April 2003
# Whom:					Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	qt4-${DB}-plugin
PORTVERSION=	4.2.3
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_QT}
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@freebsd.org
COMMENT=	Qt MySQL database plugin

DB=		mysql

BUILD_DEPENDS+= moc-qt4:${PORTSDIR}/devel/qt4-moc
LIB_DEPENDS+=	QtSql:${PORTSDIR}/databases/qt4-sql

USE_MYSQL=	yes
#USE_BZIP2=	yes
DRIVER=		src/sql/drivers/${DB}
PLUGIN=		src/plugins/sqldrivers/${DB}
EXTRACT_AFTER_ARGS?=| ${TAR} -xf - \
		${DISTNAME}/${DRIVER} ${DISTNAME}/${PLUGIN}
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	DB="${DB}" DRIVER="${DRIVER}" \
		PLUGIN="${PLUGIN}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB=	DB=${DB}

.include <bsd.port.mk>
