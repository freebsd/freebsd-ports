# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	${SQLRELAY_PORTNAME}
PORTVERSION=	${SQLRELAY_PORTVERSION}
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Persistent DB connection pooling/proxying/load balancing system

LIB_DEPENDS=	librudiments.so:${PORTSDIR}/devel/rudiments

WANT_GNOME=	yes
USES=		gmake
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
MAKE_JOBS_UNSAFE=yes
USE_LDCONFIG=	yes

PORTDOCS=	*

.include "${.CURDIR}/Makefile.common"

OPTIONS_DEFINE=	MSQL MYSQL ODBC PGSQL SQLITE3 FREETDS FIREBIRD DOCS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE3}
LIB_DEPENDS+=		libgdbm.so:${PORTSDIR}/databases/gdbm \
			libsqlite3.so:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-gdbm-prefix="${LOCALBASE}" \
			--with-sqlite-prefix="${LOCALBASE}"
.else
CONFIGURE_ARGS+=	--without-gdbm-prefix \
			--disable-sqlite
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql-prefix="${LOCALBASE}"
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

.if ${PORT_OPTIONS:MFIREBIRD}
USE_FIREBIRD=	yes
CONFIGURE_ARGS+=	--with-firebird-prefix="${LOCALBASE}"
.else
CONFIGURE_ARGS+=	--disable-firebird
.endif

.if ${PORT_OPTIONS:MMSQL}
LIB_DEPENDS+=		libmsql.so:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql-prefix="${LOCALBASE}"
.else
CONFIGURE_ARGS+=	--disable-msql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-postgresql-prefix="${LOCALBASE}"
.else
CONFIGURE_ARGS+=	--disable-postgresql
.endif

.if ${PORT_OPTIONS:MODBC}
LIB_DEPENDS+=		libodbc.so:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc-prefix="${LOCALBASE}"
.else
CONFIGURE_ARGS+=	--disable-odbc
.endif

.if ${PORT_OPTIONS:MFREETDS}
LIB_DEPENDS+=		libtds.so:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=	--with-freetds-prefix="${LOCALBASE}"
.else
CONFIGURE_ARGS+=	--disable-freetds
.endif

post-patch:
	${REINPLACE_CMD} -E \
		-e 's,\$$\(initroot\),\$$\(initroot\)${PREFIX},g' \
		-e 's,/etc/rc.conf,/etc/defaults/rc.conf,g' \
			${WRKSRC}/init/Makefile
	${REINPLACE_CMD} -E \
		-e 's,/usr/local[[:>:]],${PREFIX},g;' \
		-e 's,[[:<:]]gtk-config[[:>:]],${GTK_CONFIG:T},g;' \
			${WRKSRC}/acsite.m4
	@${REINPLACE_CMD} -e '/EXAMPLEDIR/d' ${WRKSRC}/etc/Makefile
	${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -E \
		-e 's#-release \$$\(SQLR_VERSION\)##g;'

post-configure:
	@${REINPLACE_CMD} 's,-Werror,,' ${WRKSRC}/config.mk

.include <bsd.port.mk>
