# Created by: Lauri Watts <lauri@kde.org>
# $FreeBSD$

PORTNAME=	qt4-${DB}-plugin
DISTVERSION=	${QT4_VERSION}
CATEGORIES=	databases

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt PostgreSQL database plugin

DB=		psql

USE_QT4=	moc_build sql
QT_NONSTANDARD=	yes
QT_DIST=	yes

USE_PGSQL=	yes
DRIVER=		src/sql/drivers/${DB}
PLUGIN=		src/plugins/sqldrivers/${DB}
EXTRACT_AFTER_ARGS?=	${DISTNAME}/${DRIVER} \
			${DISTNAME}/${PLUGIN}
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	DB="${DB}" DRIVER="${DRIVER}" MOC="${MOC}" \
		PLUGIN="${PLUGIN}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		QT_INCDIR="${QT_INCDIR}" \
		QT_LIBDIR="${QT_LIBDIR}"
PLIST_SUB=	DB=${DB}

SQL_PLUGINDIR=	${PREFIX}/${QT_PLUGINDIR_REL}/sqldrivers

do-install:
	@${MKDIR} ${STAGEDIR}${SQL_PLUGINDIR}
	${INSTALL_LIB} ${WRKSRC}/libqsql${DB}.so ${STAGEDIR}${SQL_PLUGINDIR}

.include <bsd.port.mk>
