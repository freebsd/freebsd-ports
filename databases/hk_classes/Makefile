# New ports collection makefile for:	hk_classes
# Date created:				25 July 2002
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	hk_classes
PORTVERSION=	0.8.1
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hk-classes

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ Library for rapid development of database applications

BUILD_DEPENDS=	${LOCALBASE}/include/argp.h:${PORTSDIR}/devel/argp-standalone
LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
USE_ICONV=	yes
USE_PYTHON=	yes
USE_GNOME=	pkgconfig
USE_GETTEXT=	yes
CXXFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS=	${PTHREAD_LIBS} -L${LOCALBASE}/lib -largp -lintl
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV+=	PYTHON_VERSION=${PYTHON_VERSION:S/python//} LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--with-python-libdir=${PYTHON_LIBDIR} \
		--with-python-incdir=${PYTHON_INCLUDEDIR} \
		--with-fontconfig-incdir=${LOCALBASE}/include/fontconfig \
		--with-fontconfig-libdir=${LOCALBASE}/lib \
		--without-firebird
USE_LDCONFIG=	${PREFIX}/lib/hk_classes/

INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGVERSION=	1.1

NOT_FOR_ARCHS=	ia64
NOT_FOR_ARCHS_REASON_ia64=	Does not build

OPTIONS=	MYSQL		"Build MySQL driver"		on  \
		POSTGRESQL	"Build PostrgreSQL driver"	off \
		ODBC		"Build unixODBC driver"		off \
		PARADOX		"Build Paradox driver"		off \
		SQLITE2		"Build with sqlite2 driver"	off \
		SQLITE3		"Build with sqlite3 driver"	off

MAN1=		hk_report.1man hk_actionquery.1man hk_exportxml.1man \
		hk_exporthtml.1man hk_exportcsv.1man hk_importcsv.1man \
		hk_dbcopy.1man

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

.if defined(WITH_PARADOX)
LIB_DEPENDS+=		px:${PORTSDIR}/databases/pxlib
CONFIGURE_ARGS+=	--with-paradox-incdir=${LOCALBASE}/include/\
			--with-paradox-libdir=${LOCALBASE}/lib
PLIST_SUB+=	PARADOX=""
.else
CONFIGURE_ARGS+=	--without-paradox
PLIST_SUB+=	PARADOX="@comment "
.endif

# XXX does not work yet
.if defined(WITH_MSACCESS)
LIB_DEPENDS+=		mdb:${PORTSDIR}/databases/mdbtools
CONFIGURE_ARGS+=	--with-mdb-incdir=${LOCALBASE}/include/\
			--with-mdb-libdir=${LOCALBASE}/lib
PLIST_SUB+=	MSACCESS=""
.else
CONFIGURE_ARGS+=	--without-mdb
PLIST_SUB+=	MSACCESS="@comment "
.endif

# XXX does not work yet
.if defined(WITH_DBASE)
LIB_DEPENDS+=		xbase:${PORTSDIR}/databases/xbase
CONFIGURE_ARGS+=	--with-xbase-incdir=${LOCALBASE}/include/xbase \
			--with-xbase-libdir=${LOCALBASE}/lib
PLIST_SUB+=	DBASE=""
.else
CONFIGURE_ARGS+=	--without-xbase
PLIST_SUB+=	DBASE="@comment "
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
