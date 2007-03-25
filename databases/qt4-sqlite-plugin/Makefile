# -*-mode: makefile-*-
# New ports collection makefile for:		qt-sqlite-plugin
# Date created:                         	27 February 2004
# Whom:                                        	Michael Nottebrock <lofi@freebsd.org>
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
COMMENT=	Qt SQLite 2.x database plugin

DB=		sqlite2

LIB_DEPENDS+=	QtSql:${PORTSDIR}/databases/qt4-sql \
		sqlite.2:${PORTSDIR}/databases/sqlite2

#USE_BZIP2=	yes
DRIVER=		src/sql/drivers/${DB}
EXTRACT_AFTER_ARGS?=| ${TAR} -xf - \
		${DISTNAME}/${DRIVER} ${DISTNAME}/include/QtSql \
		${DISTNAME}/src/sql/kernel
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	DB="${DB}" DRIVER="${DRIVER}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB=	DB=${DB}

.include <bsd.port.mk>
