# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgda
PORTVERSION?=	5.2.5
PORTREVISION?=	1
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX?=	5
DIST_SUBDIR=	gnome3

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Provides uniform access to different kinds of data sources

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.LIB

USES=		python readline shebangfix tar:xz
LIBGDA5_SLAVE?=	no
SHEBANG_FILES=	libgda-report/RML/*/*.py

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \

USES+=		gettext gmake gnome libtool localbase pathfix pkgconfig
USE_GNOME=	glib20 libxslt intlhack introspection:build referencehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
#MAKE_JOBS_UNSAFE=yes
CONFIGURE_ARGS=	--without-oracle \
		--disable-crypto \
		--disable-default-binary \
		--enable-introspection

.include <bsd.port.options.mk>

VERSION=	5.0
PLIST_SUB+=	VERSION=${VERSION}

.if ${LIBGDA5_SLAVE}!="no"
USE_GNOME+=	libgda5
.endif

.if ${LIBGDA5_SLAVE}==ui
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error
CONFIGURE_ARGS+=--with-ui
USE_GNOME+=	cairo gtk30
INSTALLS_ICONS=	yes
.else
CONFIGURE_ARGS+=--without-ui
.endif

.if ${LIBGDA5_SLAVE}==bdb
USES+=			bdb:5
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
USES+=			mysql
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${LIBGDA5_SLAVE}==postgresql
USES+=			pgsql
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-postgres
.endif

# MDB (MS Access)
.if ${LIBGDA5_SLAVE}==mdb
LIB_DEPENDS+=		libmdbsql.so:databases/mdbtools
CONFIGURE_ARGS+=	--with-mdb=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-mdb
.endif

.if ${LIBGDA5_SLAVE}==jdbc
USE_JAVA=		yes
JAVA_VERSION=		1.6+
JAVA_VENDOR=		bsdjava openjdk
CFLAGS+=		-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd
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
.if ${LIBGDA5_SLAVE} == jdbc
	@${REINPLACE_CMD} -e 's|lib/amd64|lib/${ARCH}|g' \
		${WRKSRC}/getsp.java
.endif
.if ${LIBGDA5_SLAVE}!="no"
	@${FIND} ${WRKSRC} -name Makefile.in -exec ${REINPLACE_CMD} \
		-e 's|$$(top_builddir)/libgda/libgda-5.0.la|-lgda-5.0|g' \
		-e 's|../libgda/libgda-5.0.la|-lgda-5.0|g' \
		{} \;
.endif

.if ${LIBGDA5_SLAVE} == jdbc
pre-configure:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/javac getsp.java
.endif

pre-build:
.if ${LIBGDA5_SLAVE}==postgresql
	cd ${WRKSRC}/providers/reuseable/postgres && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} libgda-postgres.la
.endif

.if ${LIBGDA5_SLAVE}==mysql
	cd ${WRKSRC}/providers/reuseable/mysql && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} libgda-mysql.la
.endif

.if ${LIBGDA5_SLAVE}==ui
	cd ${WRKSRC}/libgda && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} gda-enum-types.h
.endif

.if ${LIBGDA5_SLAVE}==no
post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/libgda-${VERSION}/config \
		${STAGEDIR}${PREFIX}/etc/libgda-${VERSION}/config.sample
.endif
.if ${LIBGDA5_SLAVE}==ui
post-install:
	${INSTALL_DATA} ${WRKSRC}/libgda-ui-5.0.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/
.endif

.include <bsd.port.mk>
.endif
