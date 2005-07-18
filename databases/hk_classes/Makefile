# New ports collection makefile for:	hk_classes
# Date created:				25 July 2002
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	hk_classes
PORTVERSION=	0.7.4a
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hk-classes

MAINTAINER=	sem@FreeBSD.org
COMMENT=	C++ Library for rapid development of database applications

BUILD_DEPENDS=	${LOCALBASE}/include/argp.h:${PORTSDIR}/devel/argp-standalone

USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_ICONV=	yes
USE_PYTHON=	yes
USE_GNOME=	pkgconfig
CXXFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV+=	LIBPYTHON="-l${PYTHON_VERSION} ${PTHREAD_LIBS}" \
		LDFLAGS="${PTHREAD_LIBS} -largp -L${LOCALBASE}/lib"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=	15
LDCONFIG_DIRS+=	${PREFIX}/lib/hk_classes/

OPTIONS=	MYSQL "Build MySQL driver" on \
		POSTGRESQL "Build PostrgreSQL driver" off \
		ODBC "Build unixODBC driver" off \
		SQLITE2 "Build with sqlite2 driver" off \
		SQLITE3 "Build with sqlite3 driver" off

MAN1=		hk_report.1man hk_actionquery.1man hk_exportxml.1man \
		hk_exporthtml.1man hk_exportcsv.1man hk_importcsv.1man

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql-dir=${LOCALBASE} \
			--with-mysql-incdir=${LOCALBASE}/include/mysql \
			--with-mysql-libdir=${LOCALBASE}/lib/mysql
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${LOCALBASE}/lib/mysql"
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-postgres-incdir=${LOCALBASE}/include/ \
			--with-postgres-libdir=${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"
PLIST_SUB+=	POSTGRESQL=""
.else
CONFIGURE_ARGS+=	--without-postgres
PLIST_SUB+=	POSTGRESQL="@comment "
.endif

.if defined(WITH_ODBC)
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc-incdir=${LOCALBASE}/include/\
			--with-odbc-libdir=${LOCALBASE}/lib
PLIST_SUB+=	ODBC=""
.else
CONFIGURE_ARGS+=	--without-odbc
PLIST_SUB+=	ODBC="@comment "
.endif

.if defined(WITH_SQLITE2)
LIB_DEPENDS+=		sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_ARGS+=	--with-sqlite-incdir=${LOCALBASE}/include/\
			--with-sqlite-libdir=${LOCALBASE}/lib
PLIST_SUB+=	SQLITE2=""
.else
CONFIGURE_ARGS+=	--without-sqlite
PLIST_SUB+=	SQLITE2="@comment "
.endif

.if defined(WITH_SQLITE3)
LIB_DEPENDS+=		sqlite3:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-sqlite-incdir3=${LOCALBASE}/include/\
			--with-sqlite-libdir3=${LOCALBASE}/lib
PLIST_SUB+=	SQLITE3=""
.else
CONFIGURE_ARGS+=	--without-sqlite3
PLIST_SUB+=	SQLITE3="@comment "
.endif

post-install:
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#' ${FILESDIR}/hk_classes.sh > \
		${PREFIX}/etc/rc.d/hk_classes.sh; \
	 ${CHMOD} a+x ${PREFIX}/etc/rc.d/hk_classes.sh

.include <bsd.port.post.mk>
