# New ports collection makefile for:	SQL Relay
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${SQLRELAY_PORTNAME}
PORTVERSION=	${SQLRELAY_PORTVERSION}
CATEGORIES=	databases
MASTER_SITES=	http://www.firstworks.com/downloads/sqlrelay/

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	rudiments.0:${PORTSDIR}/devel/rudiments \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		giconv.2:${PORTSDIR}/converters/libiconv

USE_GMAKE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	${SQLRELAY_CONFIGURE_ARGS} \
		--without-perl-prefix \
		--without-python-prefix \
		--without-ruby-prefix \
		--without-php-prefix
INSTALLS_SHLIB=	yes

.include "${.CURDIR}/Makefile.common"

.if defined(PACKAGE_BUILDING) || defined(BATCH)
WITH_SQLITE?=		yes
WITH_MYSQL?=		yes
WITH_MSQL?=		no
WITH_POSTGRESQL?=	yes
WITH_ODBC?=		yes
WITH_FREETDS?=		yes
WITH_GTK?=		yes
.else
WITH_SQLITE?=		no
WITH_MYSQL?=		yes
WITH_MSQL?=		no
WITH_POSTGRESQL?=	yes
WITH_ODBC?=		no
WITH_FREETDS?=		no
WITH_GTK?=		yes
.endif

.if defined(WITH_SQLITE) && ${WITH_SQLITE:L} != no
LIB_DEPENDS+=		gdbm.2:${PORTSDIR}/databases/gdbm \
			sqlite.1:${PORTSDIR}/databases/sqlite
CONFIGURE_ARGS+=	--with-gdbm-prefix="${LOCALBASE}" \
			--with-sqlite-prefix="${LOCALBASE}"
IF_SQLITE=	""
.else
IF_SQLITE=	"@comment "
.endif

.if defined(WITH_MYSQL) && ${WITH_MYSQL:L} != no
LIB_DEPENDS+=		mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--with-mysql-prefix="${LOCALBASE}"
IF_MYSQL=	""
.else
IF_MYSQL=	"@comment "
.endif

.if defined(WITH_MSQL) && ${WITH_MSQL:L} != no
LIB_DEPENDS+=		msql.1:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql-prefix="${LOCALBASE}"
IF_MSQL=	""
.else
IF_MSQL=	"@comment "
.endif

.if defined(WITH_POSTGRESQL) && ${WITH_POSTGRESQL:L} != no
LIB_DEPENDS+=		pq.2:${PORTSDIR}/databases/postgresql7
.if defined(WITH_OLD_LAYOUT)
CONFIGURE_ARGS+=	--with-postgresql-prefix="${LOCALBASE}/pgsql"
.else
CONFIGURE_ARGS+=	--with-postgresql-prefix="${WRKDIR}/prefixes/postgresql"
.endif
IF_POSTGRESQL=	""
.else
IF_POSTGRESQL=	"@comment "
.endif

.if defined(WITH_ODBC) && ${WITH_ODBC:L} != no
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc-prefix="${LOCALBASE}"
IF_ODBC=	""
.else
IF_ODBC=	"@comment "
.endif

.if defined(WITH_FREETDS) && ${WITH_FREETDS:L} != no
LIB_DEPENDS+=		tds.0:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=	--with-freetds-prefix="${LOCALBASE}"
IF_FREETDS=	""
.else
IF_FREETDS=	"@comment "
.endif

.if defined(WITH_GTK) && ${WITH_GTK:L} != no
USE_GTK=		yes
CONFIGURE_ARGS+=	--with-gtk-prefix="${X11BASE}"
IF_GTK=		""
.else
IF_GTK=		"@comment "
.endif

PLIST_SUB=	IF_SQLITE=${IF_SQLITE} \
		IF_MYSQL=${IF_MYSQL} \
		IF_MSQL=${IF_MSQL} \
		IF_POSTGRESQL=${IF_POSTGRESQL} \
		IF_ODBC=${IF_ODBC} \
		IF_FREETDS=${IF_FREETDS} \
		IF_GTK=${IF_GTK}

#  --with-sybase-prefix          Location of Sybase
#  --with-oracle-home            Location of Oracle
#  --with-interbase-prefix       Location of Interbase
#  --with-db2-prefix             Location of DB2

post-extract:
	${RM} -rf ${WRKSRC}/src/api/perl/*/blib
	${MKDIR} ${WRKDIR}/prefixes/libxml
	${LN} -s ${LOCALBASE}/include/libxml2 ${WRKDIR}/prefixes/libxml/include
	${LN} -s ${LOCALBASE}/lib ${WRKDIR}/prefixes/libxml/lib
.if defined(WITH_POSTGRESQL) && ${WITH_POSTGRESQL:L} != no
.if !defined(WITH_OLD_LAYOUT)
	${MKDIR} ${WRKDIR}/prefixes/postgresql
	${LN} -s ${LOCALBASE}/include/pgsql ${WRKDIR}/prefixes/postgresql/include
	${LN} -s ${LOCALBASE}/lib ${WRKDIR}/prefixes/postgresql/lib
.endif
.endif

post-patch:
	${PERL} -i -pe 's,\blibiconv\b,libgiconv,g;s,-liconv\b,-lgiconv,g' ${WRKSRC}/configure.in
	find ${WRKSRC}/src/api -type f | xargs ${GREP} -Ele '-L(\.\./)?\.\./c\+\+/lib' /dev/null | xargs ${PERL} -i -pe 's|-L(?:\.\./)?\.\./c\+\+/lib|-L${LOCALBASE}/lib|'
.if defined(WITH_GTK) && ${WITH_GTK:L} != no
	${PERL} -i -pe 's,\bgtk-config\b,${GTK_CONFIG:T},g' ${WRKSRC}/configure.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${MAKE} install-doc
.endif

.include <bsd.port.mk>
