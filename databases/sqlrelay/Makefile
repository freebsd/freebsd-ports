# New ports collection makefile for:	SQL Relay
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${SQLRELAY_PORTNAME}
PORTVERSION=	${SQLRELAY_PORTVERSION}
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sqlrelay

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A persistent DB connection pooling/proxying/load balancing system

LIB_DEPENDS=	rudiments.0:${PORTSDIR}/devel/rudiments \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	${SQLRELAY_CONFIGURE_ARGS} \
		--without-java-prefix \
		--without-perl-prefix \
		--without-php-prefix \
		--without-python-prefix \
		--without-ruby-prefix \
		--without-zope-prefix
MAKE_ARGS=	VERSION="${PORTVERSION:R}"
INSTALLS_SHLIB=	yes

POSTGRESQL_PORT?=	databases/postgresql7

.include "${.CURDIR}/Makefile.common"

.if defined(PACKAGE_BUILDING) || defined(BATCH)
WITH_SQLITE?=		yes
WITH_MYSQL?=		yes
WITH_MSQL?=		no
WITH_POSTGRESQL?=	yes
WITH_ODBC?=		yes
WITH_FREETDS?=		yes
WITH_GTK?=		yes
WITH_INTERBASE?=	yes
.else
WITH_SQLITE?=		no
WITH_MYSQL?=		yes
WITH_MSQL?=		no
WITH_POSTGRESQL?=	yes
WITH_ODBC?=		no
WITH_FREETDS?=		no
WITH_GTK?=		yes
WITH_INTERBASE?=	no
.endif

.if defined(WITH_SQLITE) && ${WITH_SQLITE:L} != no
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdbm \
			sqlite.2:${PORTSDIR}/databases/sqlite
CONFIGURE_ARGS+=	--with-gdbm-prefix="${LOCALBASE}" \
			--with-sqlite-prefix="${LOCALBASE}"
IF_SQLITE=	""
.else
CONFIGURE_ARGS+=	--without-gdbm-prefix \
			--without-sqlite-prefix
IF_SQLITE=	"@comment "
.endif

.if defined(WITH_MYSQL) && ${WITH_MYSQL:L} != no
LIB_DEPENDS+=		mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--with-mysql-prefix="${LOCALBASE}"
IF_MYSQL=	""
.else
CONFIGURE_ARGS+=	--without-mysql-prefix
IF_MYSQL=	"@comment "
.endif

.if defined(WITH_INTERBASE) && ${WITH_INTERBASE:L} != no
LIB_DEPENDS+=		gds.1:${PORTSDIR}/databases/firebird
CONFIGURE_ARGS+=	--with-interbase-prefix="${LOCALBASE}/firebird"
IF_INTERBASE=	""
.else
CONFIGURE_ARGS+=	--without-interbase-prefix
IF_INTERBASE=	"@comment "
.endif

.if defined(WITH_MSQL) && ${WITH_MSQL:L} != no
LIB_DEPENDS+=		msql.1:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql-prefix="${LOCALBASE}"
IF_MSQL=	""
.else
CONFIGURE_ARGS+=	--without-msql-prefix
IF_MSQL=	"@comment "
.endif

.if defined(WITH_POSTGRESQL) && ${WITH_POSTGRESQL:L} != no
LIB_DEPENDS+=		pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-postgresql-prefix="${LOCALBASE}"
IF_POSTGRESQL=	""
.else
CONFIGURE_ARGS+=	--without-postgresql-prefix
IF_POSTGRESQL=	"@comment "
.endif

.if defined(WITH_ODBC) && ${WITH_ODBC:L} != no
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc-prefix="${LOCALBASE}"
IF_ODBC=	""
.else
CONFIGURE_ARGS+=	--without-odbc-prefix
IF_ODBC=	"@comment "
.endif

.if defined(WITH_FREETDS) && ${WITH_FREETDS:L} != no
LIB_DEPENDS+=		tds.3:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=	--with-freetds-prefix="${LOCALBASE}"
IF_FREETDS=	""
.else
CONFIGURE_ARGS+=	--without-freetds-prefix
IF_FREETDS=	"@comment "
.endif

.if defined(WITH_GTK) && ${WITH_GTK:L} != no
USE_GNOME=		gtk12
CONFIGURE_ARGS+=	--with-gtk-prefix="${X11BASE}"
IF_GTK=		""
.else
CONFIGURE_ARGS+=	--without-gtk-prefix
IF_GTK=		"@comment "
.endif

PLIST_SUB=	IF_SQLITE=${IF_SQLITE} \
		IF_MYSQL=${IF_MYSQL} \
		IF_MSQL=${IF_MSQL} \
		IF_POSTGRESQL=${IF_POSTGRESQL} \
		IF_ODBC=${IF_ODBC} \
		IF_FREETDS=${IF_FREETDS} \
		IF_INTERBASE=${IF_INTERBASE} \
		IF_GTK=${IF_GTK}

#  --with-sybase-prefix          Location of Sybase
#  --with-oracle-home            Location of Oracle
#  --with-interbase-prefix       Location of Interbase
#  --with-db2-prefix             Location of DB2

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-*

PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

post-extract:
	${MKDIR} ${WRKDIR}/prefixes/libxml
	${LN} -s ${LOCALBASE}/include/libxml2 ${WRKDIR}/prefixes/libxml/include
	${LN} -s ${LOCALBASE}/lib ${WRKDIR}/prefixes/libxml/lib

post-patch:
	${REINPLACE_CMD} -E \
		-e 's,/usr/local[[:>:]],${PREFIX},g;' \
		-e 's,[[:<:]]gtk-config[[:>:]],${GTK_CONFIG:T},g;' \
			${WRKSRC}/configure
	${REINPLACE_CMD} -E \
		-e 's,\.so\.\$$\(SQLR_VERSION\),\.so\.$$(basename $$(SQLR_VERSION)),g;' \
			${WRKSRC}/src/api/c/src/Makefile \
			${WRKSRC}/src/api/c++/src/Makefile

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${MAKE} install-doc
.endif

.include <bsd.port.post.mk>
