# New ports collection makefile for:	libgda2
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgda2
PORTVERSION=	0.12.0
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/0.12
DISTNAME=	libgda-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides uniform access to different kinds of data sources

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier glib20 libxslt
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-odbc # iODBC support seems broken
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

MAN1=		gda-config-tool.1
MAN5=		gda-config.5

.if defined(WITH_MYSQL)
LIB_DEPENDS+=		mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
PLIST_SUB=		MYSQL=""
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB=		MYSQL="@comment "
.endif

.if defined(WITH_POSTGRES)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=		pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
PLIST_SUB+=		POSTGRES=""
.else
CONFIGURE_ARGS+=	--without-postgres
PLIST_SUB+=		POSTGRES="@comment "
.endif

.if defined(WITH_LDAP)
LIB_DEPENDS+=		ldap.2:${PORTSDIR}/net/openldap20
CONFIGURE_ARGS+=	--with-ldap=${LOCALBASE}
PLIST_SUB+=		LDAP=""
.else
CONFIGURE_ARGS+=	--without-ldap
PLIST_SUB+=		LDAP="@comment "
.endif

pre-everything::
.if !defined(WITH_MYSQL)
	@${ECHO_MSG} "You can enable support for MySQL databases by defining WITH_MYSQL."
.endif
.if !defined(WITH_POSTGRES)
	@${ECHO_MSG} "You can enable support for Postgres databases by defining WITH_POSTGRES."
.endif
.if !defined(WITH_LDAP)
	@${ECHO_MSG} "You can enable support for LDAP databases by defining WITH_LDAP."
.endif

.include <bsd.port.mk>
