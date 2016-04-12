# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/libgda4/Makefile,v 1.27 2012/09/01 23:02:08 mezz Exp $

PORTNAME=	libgda
PORTVERSION=	4.2.12
PORTREVISION?=	7
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX?=	4
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Provides uniform access to different kinds of data sources

CONFLICTS=	libgda5-ui-[0-9]*
PORTSCOUT=	ignore:1

USES=		tar:xz
LIBGDA4_SLAVE?=	no

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libjson-glib-1.0.so:devel/json-glib

USES+=		gettext gmake libtool pathfix pkgconfig
USE_GNOME=	gnomeprefix glib20 libxslt intlhack referencehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=yes
CONFIGURE_ARGS=	--without-oracle \
		--disable-crypto \
		--enable-introspection=no \
		--without-gtksourceview \
		--without-goocanvas \
		--without-graphviz
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.if ${LIBGDA4_SLAVE}=="no"
OPTIONS_DEFINE=	UI SOUP KEYRING
OPTIONS_DEFAULT=UI
UI_DESC=	Build UI tools
SOUP_DESC=	Web provider
KEYRING_DESC=	Support gnome-keyring
.endif

.include <bsd.port.options.mk>

VERSION=	4.0
PLIST_SUB=	VERSION=${VERSION}

.if ${LIBGDA4_SLAVE}=="no"
.if ${PORT_OPTIONS:MUI}
CONFIGURE_ARGS+=--with-ui
BUILD_DEPENDS+=	xml2po:textproc/gnome-doc-utils
USE_GNOME+=	gtk20
INSTALLS_ICONS=	yes
PLIST_SUB+=	UI=""
.else
CONFIGURE_ARGS+=--without-ui
PLIST_SUB+=	UI="@comment "
.endif

.if ${PORT_OPTIONS:MSOUP}
CONFIGURE_ARGS+=--with-libsoup
LIB_DEPENDS+=	libsoup-2.so:devel/libsoup
PLIST_SUB+=	WEB=""
.else
CONFIGURE_ARGS+=--without-libsoup
PLIST_SUB+=	WEB="@comment "
.endif

.if ${PORT_OPTIONS:MKEYRING}
CONFIGURE_ARGS+=--with-gnome-keyring
LIB_DEPENDS+=	libgnome-keyring.so:security/libgnome-keyring
.else
CONFIGURE_ARGS+=--without-gnome-keyring
.endif

MAN1=		gda-sql.1 gda-sql-4.0.1
.else
USE_GNOME+=	libgda4
.endif

.if ${LIBGDA4_SLAVE}=="bdb"
USE_BDB=		yes
CONFIGURE_ARGS+=	--with-bdb=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-bdb
.endif

.if ${LIBGDA4_SLAVE}=="ldap"
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if ${LIBGDA4_SLAVE}=="mysql"
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${LIBGDA4_SLAVE}=="postgresql"
USES+=			pgsql
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-postgres
.endif

# MDB (MS Access)
.if ${LIBGDA4_SLAVE}=="mdb"
LIB_DEPENDS+=		libmdbsql.so:databases/mdbtools
CONFIGURE_ARGS+=	--with-mdb=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-mdb
.endif

.if ${LIBGDA4_SLAVE}=="jdbc"
USE_JAVA=		yes
JAVA_VERSION=		1.6
JAVA_VENDOR=		openjdk
.else
CONFIGURE_ARGS+=	--without-java
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|"db.h|"db${BDB_VER}/db.h|g' \
		-e 's|ldb47|l${BDB_LIB_NAME}|g' \
		-e 's|ldb|l${BDB_LIB_NAME}|g' \
		-e 's|libdb|lib${BDB_LIB_NAME}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|<db\.h>|<db${BDB_VER}/db.h>|' \
		${WRKSRC}/providers/bdb/gda-bdb-provider.c \
		${WRKSRC}/providers/bdb/gda-bdb-test.c
.if ${LIBGDA4_SLAVE}!="no"
#. for d in msql firebird odbc freetds mdb ldap mysql sqlite postgres
. for d in bdb jdbc mdb mysql postgres reuseable/postgres reuseable/mysql ldap
	@${REINPLACE_CMD} -e 's|$$(top_builddir)/libgda/libgda-4.0.la|-lgda-4.0|g' \
		${WRKSRC}/providers/${d}/Makefile.in
. endfor
.endif

pre-build:
.if ${LIBGDA4_SLAVE}=="postgresql"
	cd ${WRKSRC}/providers/reuseable/postgres && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} libgda-postgres.la
.endif

.if ${LIBGDA4_SLAVE}=="mysql"
	cd ${WRKSRC}/providers/reuseable/mysql && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} libgda-mysql.la
.endif

.if ${LIBGDA4_SLAVE}=="no"
post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/libgda-${VERSION}/config \
		${STAGEDIR}${PREFIX}/etc/libgda-${VERSION}/config.sample
.endif

.include <bsd.port.mk>

.endif
