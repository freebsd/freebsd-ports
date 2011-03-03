# New ports collection makefile for:	libgda2
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/libgda4/Makefile,v 1.14 2010/11/14 20:57:58 kwm Exp $
#

PORTNAME=	libgda4
PORTVERSION?=	4.2.5
PORTREVISION?=	0
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/4$//}/${PORTVERSION:R}
DISTNAME=	libgda-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Provides uniform access to different kinds of data sources

USE_BZIP2=	yes
LIBGDA4_SLAVE?=	no

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		gcrypt.17:${PORTSDIR}/security/libgcrypt \
    		soup-2.4.1:${PORTSDIR}/devel/libsoup \
		json-glib-1.0.0:${PORTSDIR}/devel/json-glib
RUN_DEPENDS=	${LOCALBASE}/lib/girepository-1.0/GObject-2.0.typelib:${PORTSDIR}/devel/gobject-introspection

USE_AUTOTOOLS=	libtool
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack glib20 libxslt intlhack referencehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes
CONFIGURE_ARGS=	--without-oracle \
		--disable-crypto \
		--enable-introspection=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

.if ${LIBGDA4_SLAVE}=="no"
OPTIONS=	UI "Build UI tools" on
.endif

.if defined(WITH_UI)
INSTALLS_ICONS=	yes
.endif

.include <bsd.port.options.mk>

#VERSION=	${PORTVERSION:R}
VERSION=	4.0
PLIST_SUB=	VERSION=${VERSION}

.if ${LIBGDA4_SLAVE}=="no"
.if defined(WITH_UI)
CONFIGURE_ARGS+=--with-ui
BUILD_DEPENDS+=	xml2po:${PORTSDIR}/textproc/gnome-doc-utils
USE_GNOME+=	gtk20
PLIST_SUB+=	UI=""
.else
CONFIGURE_ARGS+=--without-ui
PLIST_SUB+=	UI="@comment "
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

.if ${LIBGDA4_SLAVE}=="mysql"
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${LIBGDA4_SLAVE}=="postgresql"
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-postgres
.endif

.if ${LIBGDA4_SLAVE}=="firebird"
LIB_DEPENDS+=		gds.2:${PORTSDIR}/databases/firebird2-client
CONFIGURE_ARGS+=	--with-firebird=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-firebird
.endif

# MDB (MS Access)
.if ${LIBGDA4_SLAVE}=="mdb"
LIB_DEPENDS+=		mdbsql.0:${PORTSDIR}/databases/mdbtools
CONFIGURE_ARGS+=	--with-mdb=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-mdb
.endif

.if ${LIBGDA4_SLAVE}=="jdbc"
USE_JAVA=		yes
JAVA_VENDOR=		bsdjava openjdk
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
. for d in bdb jdbc mdb mysql postgres reuseable/postgres reuseable/mysql
	@${REINPLACE_CMD} -e 's|$$(top_builddir)/libgda/libgda-4.0.la|${LOCALBASE}/lib/libgda-4.0.la|g' \
		${WRKSRC}/providers/${d}/Makefile.in
. endfor
.endif

pre-build:
.if ${LIBGDA4_SLAVE}=="postgresql"
	cd ${WRKSRC}/providers/reuseable/postgres && ${GMAKE} libgda-postgres.la
.endif

.if ${LIBGDA4_SLAVE}=="mysql"
	cd ${WRKSRC}/providers/reuseable/mysql && ${GMAKE} libgda-mysql.la
.endif

.if ${LIBGDA4_SLAVE}=="no"
post-install:
	${INSTALL_DATA} ${WRKSRC}/data/config \
		${PREFIX}/etc/libgda-${VERSION}/config.default
.endif

.include <bsd.port.pre.mk>

.if ${LIBGDA4_SLAVE}=="jdbc" && ${OSVERSION} < 800000
BROKEN=		does not compile on 7.x
.endif

.include <bsd.port.post.mk>
.endif
