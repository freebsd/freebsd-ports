# New ports collection makefile for:	SQL Relay
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${SQLRELAY_PORTNAME}
PORTVERSION=	${SQLRELAY_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A persistent DB connection pooling/proxying/load balancing system

LIB_DEPENDS=	rudiments.1:${PORTSDIR}/devel/rudiments

USE_GMAKE=		yes
USE_AUTOTOOLS=	autoconf:262 libtool:22
CONFIGURE_ENV=		${SQLRELAY_CONFIGURE_ENV} \
			CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=		${SQLRELAY_CONFIGURE_ARGS} \
			--disable-tcl \
			--disable-java \
			--disable-perl \
			--disable-php \
			--disable-python \
			--disable-ruby \
			--disable-zope
USE_LDCONFIG=	yes

PORTDOCS=	*

.include "${.CURDIR}/Makefile.common"

OPTIONS=	MSQL "Build MSQL connection" off \
		MYSQL "Build MySQL connection" off \
		ODBC "Build ODBC connection" off \
		POSTGRESQL "Build PostgreSQL connection" off \
		SQLITE "Build SQLite connection" off \
		FREETDS "Build FreeTDS connection" off \
		INTERBASE "Build Interbase connection" off \
		GTK "Build GTK configuration tool" off

.include <bsd.port.pre.mk>

.if defined(WITH_SQLITE) && ${WITH_SQLITE:L} != no
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdbm \
			sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_ARGS+=	--with-gdbm-prefix="${LOCALBASE}" \
			--with-sqlite-prefix="${LOCALBASE}"
IF_SQLITE=	""
.else
CONFIGURE_ARGS+=	--without-gdbm-prefix \
			--disable-sqlite
IF_SQLITE=	"@comment "
.endif

.if defined(WITH_MYSQL) && ${WITH_MYSQL:L} != no
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql-prefix="${LOCALBASE}"
IF_MYSQL=	""
.else
CONFIGURE_ARGS+=	--disable-mysql
IF_MYSQL=	"@comment "
.endif

.if defined(WITH_INTERBASE) && ${WITH_INTERBASE:L} != no
USE_FIREBIRD=	yes
CONFIGURE_ARGS+=	--with-interbase-prefix="${LOCALBASE}"
IF_INTERBASE=	""
.else
CONFIGURE_ARGS+=	--disable-interbase
IF_INTERBASE=	"@comment "
.endif

.if defined(WITH_MSQL) && ${WITH_MSQL:L} != no
LIB_DEPENDS+=		msql.1:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql-prefix="${LOCALBASE}"
IF_MSQL=	""
.else
CONFIGURE_ARGS+=	--disable-msql
IF_MSQL=	"@comment "
.endif

.if defined(WITH_POSTGRESQL) && ${WITH_POSTGRESQL:L} != no
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-postgresql-prefix="${LOCALBASE}"
IF_POSTGRESQL=	""
.else
CONFIGURE_ARGS+=	--disable-postgresql
IF_POSTGRESQL=	"@comment "
.endif

.if defined(WITH_ODBC) && ${WITH_ODBC:L} != no
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc-prefix="${LOCALBASE}"
IF_ODBC=	""
.else
CONFIGURE_ARGS+=	--disable-odbc
IF_ODBC=	"@comment "
.endif

.if defined(WITH_FREETDS) && ${WITH_FREETDS:L} != no
LIB_DEPENDS+=		tds.5:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=	--with-freetds-prefix="${LOCALBASE}"
IF_FREETDS=	""
.else
CONFIGURE_ARGS+=	--disable-freetds
IF_FREETDS=	"@comment "
.endif

.if defined(WITH_GTK) && ${WITH_GTK:L} != no
USE_GNOME+=		gtk12
CONFIGURE_ARGS+=	--with-gtk-prefix="${LOCALBASE}"
IF_GTK=		""
.else
CONFIGURE_ARGS+=	--disable-gtk
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

MAN1=		fields.1 query.1 query.py.1 sqlr-config-gtk.1 sqlrsh.1
MAN8=		sqlr-connection.8 sqlr-cachemanager.8 sqlr-ipclean.8 \
		sqlr-listener.8 sqlr-scaler.8 sqlr-start.8 sqlr-stop.8

post-patch:
	${REINPLACE_CMD} -E \
		-e 's,/usr/local[[:>:]],${PREFIX},g;' \
		-e 's,[[:<:]]gtk-config[[:>:]],${GTK_CONFIG:T},g;' \
			${WRKSRC}/acsite.m4
	@${REINPLACE_CMD} -e '/EXAMPLEDIR/d' ${WRKSRC}/etc/Makefile
	${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -E \
		-e 's#-release \$$\(SQLR_VERSION\)##g;'
.ifdef NOPORTDOCS
	 @${REINPLACE_CMD} '/$$(MAKE) -C doc/d' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
