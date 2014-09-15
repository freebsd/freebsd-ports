# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qt4-${DB}-plugin
DISTVERSION=	${QT4_VERSION}
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt SQLite 2 database plugin

DB=		sqlite2

USE_QT4=	moc_build sql
QT_DIST=	yes
USE_SQLITE=	2

DRIVER=		src/sql/drivers/${DB}
PLUGIN=		src/plugins/sqldrivers/${DB}
EXTRACT_AFTER_ARGS?=	${DISTNAME}/${DRIVER} ${DISTNAME}/${PLUGIN} \
			${DISTNAME}/include/QtSql \
			${DISTNAME}/src/corelib \
			${DISTNAME}/src/sql/kernel
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	DB="${DB}" DRIVER="${DRIVER}" MOC="${MOC}" \
		PLUGIN="${PLUGIN}" \
		QT_INCDIR="${QT_INCDIR}" \
		QT_LIBDIR="${QT_LIBDIR}"
PLIST_SUB=	DB=${DB}

EXTRA_PATCHES=	# empty

SQL_PLUGINDIR=	${PREFIX}/${QT_PLUGINDIR_REL}/sqldrivers

do-install:
	@${MKDIR} ${STAGEDIR}${SQL_PLUGINDIR}
	${INSTALL_LIB} ${WRKSRC}/libq${DB}.so ${STAGEDIR}${SQL_PLUGINDIR}

.include <bsd.port.mk>
