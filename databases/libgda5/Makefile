# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/databases/libgda5/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libgda
PORTVERSION?=	5.0.3
PORTREVISION?=	0
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX?=	5
DIST_SUBDIR=	gnome3

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Provides uniform access to different kinds of data sources

USE_XZ=		yes
LIBGDA5_SLAVE?=	no

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib

USE_AUTOTOOLS=	libtool
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix glib20 libxslt intlhack referencehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes
CONFIGURE_ARGS=	--without-oracle \
		--disable-crypto \
		--disable-default-binary \
		--disable-introspection
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

VERSION=	5.0
PLIST_SUB=	VERSION=${VERSION}

.if ${LIBGDA5_SLAVE}!="no"
USE_GNOME+=	libgda5
.endif

.if ${LIBGDA5_SLAVE}==ui
CONFIGURE_ARGS+=--with-ui
USE_GNOME+=	gtk30 gnomedocutils
INSTALLS_ICONS=	yes
.else
CONFIGURE_ARGS+=--without-ui
.endif

.if ${LIBGDA5_SLAVE}==bdb
USE_BDB=		5
CONFIGURE_ARGS+=	--with-bdb=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-bdb
.endif

.if ${LIBGDA5_SLAVE}==ldap
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if ${LIBGDA5_SLAVE}==mysql
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${LIBGDA5_SLAVE}==postgresql
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-postgres
.endif

# MDB (MS Access)
.if ${LIBGDA5_SLAVE}==mdb
LIB_DEPENDS+=		libmdbsql.so:${PORTSDIR}/databases/mdbtools
CONFIGURE_ARGS+=	--with-mdb=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-mdb
.endif

.if ${LIBGDA5_SLAVE}==jdbc
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
.if ${LIBGDA5_SLAVE}!="no"
	@${FIND} ${WRKSRC} -name Makefile.in -exec ${REINPLACE_CMD} \
		-e 's|$$(top_builddir)/libgda/libgda-5.0.la|${LOCALBASE}/lib/libgda-5.0.la|g' \
		-e 's|../libgda/libgda-5.0.la|${LOCALBASE}/lib/libgda-5.0.la|g' \
		{} \;
.endif

pre-build:
.if ${LIBGDA5_SLAVE}==postgresql
	cd ${WRKSRC}/providers/reuseable/postgres && ${GMAKE} libgda-postgres.la
.endif

.if ${LIBGDA5_SLAVE}==mysql
	cd ${WRKSRC}/providers/reuseable/mysql && ${GMAKE} libgda-mysql.la
.endif

.if ${LIBGDA5_SLAVE}==ui
	cd ${WRKSRC}/libgda && ${GMAKE} gda-enum-types.h
.endif

.if ${LIBGDA5_SLAVE}==no
post-install:
	${INSTALL_DATA} ${WRKSRC}/data/config \
		${STAGEDIR}${PREFIX}/etc/libgda-${VERSION}/config.default
	@${RM} -f ${STAGEDIR}${PREFIX}/etc/libgda-${VERSION}/config
.endif
.if ${LIBGDA5_SLAVE}==ui
post-install:
	${INSTALL_DATA} ${WRKSRC}/libgda-ui-5.0.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/
.endif

.include <bsd.port.mk>
.endif
