# -*-mode: makefile-*-
# New ports collection makefile for:	qt-mysql-plugin
# Date created:				20 April 2003
# Whom:					Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	qt-${DB}-plugin
PORTVERSION=	3.3.8
PORTREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_QT}
DISTNAME=	qt-x11-free-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	A plugin for QT to connect to MySQL-Databases

DB=		mysql

LIB_DEPENDS+=	qt-mt:${PORTSDIR}/x11-toolkits/qt33

USE_MYSQL=	yes
USE_BZIP2=	yes
PLUGIN=		plugins/src/sqldrivers/${DB}
DRIVER=		src/sql/drivers/${DB}
EXTRACT_AFTER_ARGS?=| ${TAR} -xf - ${DISTNAME}/${PLUGIN} \
		${DISTNAME}/${DRIVER} ${DISTNAME}/src/sql/drivers/cache
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	DB="${DB}" DRIVER="${DRIVER}" PLUGIN="${PLUGIN}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB=	DB=${DB}

.include <bsd.port.mk>
