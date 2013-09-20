# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	${SQLRELAY_PORTNAME}
PORTVERSION=	${SQLRELAY_PORTVERSION}
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A persistent DB connection pooling/proxying/load balancing system

LIB_DEPENDS=	rudiments.1:${PORTSDIR}/devel/rudiments

WANT_GNOME=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf libtool
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=		${SQLRELAY_CONFIGURE_ENV}
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

NO_STAGE=	yes
.include "${.CURDIR}/Makefile.common"

OPTIONS_DEFINE=	MSQL MYSQL ODBC PGSQL SQLITE2 FREETDS INTERBASE GTK1 DOCS
SQLITE2_DESC=	SQLite 2 database
INTERBASE_DESC=	Interbase database

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE2}
LIB_DEPENDS+=		gdbm.4:${PORTSDIR}/databases/gdbm \
			sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_ARGS+=	--with-gdbm-prefix="${LOCALBASE}" \
			--with-sqlite-prefix="${LOCALBASE}"
IF_SQLITE=	""
.else
CONFIGURE_ARGS+=	--without-gdbm-prefix \
			--disable-sqlite
IF_SQLITE=	"@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql-prefix="${LOCALBASE}"
IF_MYSQL=	""
.else
CONFIGURE_ARGS+=	--disable-mysql
IF_MYSQL=	"@comment "
.endif

.if ${PORT_OPTIONS:MINTERBASE}
USE_FIREBIRD=	yes
CONFIGURE_ARGS+=	--with-interbase-prefix="${LOCALBASE}"
IF_INTERBASE=	""
.else
CONFIGURE_ARGS+=	--disable-interbase
IF_INTERBASE=	"@comment "
.endif

.if ${PORT_OPTIONS:MMSQL}
LIB_DEPENDS+=		msql.1:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql-prefix="${LOCALBASE}"
IF_MSQL=	""
.else
CONFIGURE_ARGS+=	--disable-msql
IF_MSQL=	"@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-postgresql-prefix="${LOCALBASE}"
IF_POSTGRESQL=	""
.else
CONFIGURE_ARGS+=	--disable-postgresql
IF_POSTGRESQL=	"@comment "
.endif

.if ${PORT_OPTIONS:MODBC}
LIB_DEPENDS+=		odbc.2:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc-prefix="${LOCALBASE}"
IF_ODBC=	""
.else
CONFIGURE_ARGS+=	--disable-odbc
IF_ODBC=	"@comment "
.endif

.if ${PORT_OPTIONS:MFREETDS}
LIB_DEPENDS+=		tds.5:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=	--with-freetds-prefix="${LOCALBASE}"
IF_FREETDS=	""
.else
CONFIGURE_ARGS+=	--disable-freetds
IF_FREETDS=	"@comment "
.endif

.if ${PORT_OPTIONS:MGTK1}
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

MAN1=		fields.1 query.1 query.py.1 sqlrsh.1
MAN8=		sqlr-connection.8 sqlr-cachemanager.8 sqlr-ipclean.8 \
		sqlr-listener.8 sqlr-scaler.8 sqlr-start.8 sqlr-stop.8

post-patch:
	${REINPLACE_CMD} -E \
		-e 's,(freebsd.*)/usr/local(.*rc.d),\1${PREFIX}\2/sqlrelay.sh-sample,' \
		-e 's,(freebsd/sqlrelay )(.*etc),\1$$(sysconfdir)/sqlrelay-sample,' \
			${WRKSRC}/init/Makefile
	${REINPLACE_CMD} -E \
		-e 's,/usr/local[[:>:]],${PREFIX},g;' \
		-e 's,[[:<:]]gtk-config[[:>:]],${GTK_CONFIG:T},g;' \
			${WRKSRC}/acsite.m4
	@${REINPLACE_CMD} -e '/EXAMPLEDIR/d' ${WRKSRC}/etc/Makefile
	${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -E \
		-e 's#-release \$$\(SQLR_VERSION\)##g;'
.if ! ${PORT_OPTIONS:MDOCS}
	 @${REINPLACE_CMD} '/$$(MAKE) -C doc/d' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
