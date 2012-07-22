# New ports collection makefile for:	hk_classes
# Date created:				25 July 2002
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	hk_classes
PORTVERSION=	0.8.3
CATEGORIES=	databases
MASTER_SITES=	SF/hk-classes/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ Library for rapid development of database applications

BUILD_DEPENDS=	${LOCALBASE}/include/argp.h:${PORTSDIR}/devel/argp-standalone \
		pkg-config>0:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_BZIP2=	yes
USE_ICONV=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
CXXFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib -largp -lintl
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV+=	PYTHON_VERSION=${PYTHON_VERSION:S/python//}
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

OPTIONS_DEFINE=	MYSQL PGSQL ODBC PARADOX SQLITE2 SQLITE3 DBASE
OPTIONS_DEFAULT=	MYSQL
SQLITE3_DESC=	Enable SQLite 3 backend
SQLITE2_DESC=	Enable SQLite 2 backend
PARADOX_DESC=	Enable paradox backend
DBASE_DESC=	Enable Dbase backend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql-dir=${LOCALBASE} \
			--with-mysql-incdir=${LOCALBASE}/include/mysql \
			--with-mysql-libdir=${LOCALBASE}/lib/mysql
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -L${LOCALBASE}/lib/mysql"
CPPFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MDBASE}
PLIST_SUB+=	DBASE=""
.else
CONFIGURE_ARGS+=	--without-dbase
PLIST_SUB+=	DBASE="@comment "
.endif

.if ${PORT_OPTIONS:MPOSTGRESQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-postgres-incdir=${LOCALBASE}/include/ \
			--with-postgres-libdir=${LOCALBASE}/lib
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB+=	POSTGRESQL=""
.else
CONFIGURE_ARGS+=	--without-postgres
PLIST_SUB+=	POSTGRESQL="@comment "
.endif

.if ${PORT_OPTIONS:MODBC}
LIB_DEPENDS+=		odbc.2:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc-incdir=${LOCALBASE}/include/\
			--with-odbc-libdir=${LOCALBASE}/lib
PLIST_SUB+=	ODBC=""
.else
CONFIGURE_ARGS+=	--without-odbc
PLIST_SUB+=	ODBC="@comment "
.endif

.if ${PORT_OPTIONS:MPARADOX}
LIB_DEPENDS+=		px:${PORTSDIR}/databases/pxlib
CONFIGURE_ARGS+=	--with-paradox-incdir=${LOCALBASE}/include/\
			--with-paradox-libdir=${LOCALBASE}/lib
PLIST_SUB+=	PARADOX=""
.else
CONFIGURE_ARGS+=	--without-paradox
PLIST_SUB+=	PARADOX="@comment "
.endif

# XXX does not work yet
.if ${PORT_OPTIONS:MMSACCESS}
LIB_DEPENDS+=		mdb:${PORTSDIR}/databases/mdbtools
CONFIGURE_ARGS+=	--with-mdb-incdir=${LOCALBASE}/include/\
			--with-mdb-libdir=${LOCALBASE}/lib
PLIST_SUB+=	MSACCESS=""
.else
CONFIGURE_ARGS+=	--without-mdb
PLIST_SUB+=	MSACCESS="@comment "
.endif

# XXX does not work yet
CONFIGURE_ARGS+=	--without-xbase

.if ${PORT_OPTIONS:MSQLITE2}
LIB_DEPENDS+=		sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_ARGS+=	--with-sqlite-incdir=${LOCALBASE}/include/\
			--with-sqlite-libdir=${LOCALBASE}/lib
PLIST_SUB+=	SQLITE2=""
.else
CONFIGURE_ARGS+=	--without-sqlite
PLIST_SUB+=	SQLITE2="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE3}
LIB_DEPENDS+=		sqlite3:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-sqlite-incdir3=${LOCALBASE}/include/\
			--with-sqlite-libdir3=${LOCALBASE}/lib
PLIST_SUB+=	SQLITE3=""
.else
CONFIGURE_ARGS+=	--without-sqlite3
PLIST_SUB+=	SQLITE3="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e "s|INCLUDES = -I../hk_classes \
		-I./pxlib|INCLUDES = -I../hk_classes -I./pxlib \
		-I${LOCALBASE}/include|g" \
		${WRKSRC}/hk_paradoxclasses/Makefile.in

post-configure:
	${REINPLACE_CMD} -e "s| -I|','|g" ${WRKSRC}/python/setup.py

post-install:
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#' ${FILESDIR}/hk_classes.sh > \
		${PREFIX}/etc/rc.d/hk_classes.sh; \
	 ${CHMOD} a+x ${PREFIX}/etc/rc.d/hk_classes.sh

.include <bsd.port.mk>
