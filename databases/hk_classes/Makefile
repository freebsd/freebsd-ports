# New ports collection makefile for:	hk_classes
# Date created:				25 July 2002
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	hk_classes
PORTVERSION=	0.6.2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hk-classes

MAINTAINER=	sem@ciam.ru
COMMENT=	C++ Library for rapid development of database applications

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_PYTHON=	yes
CONFIGURE_ENV+=	LIBPYTHON="-l${PYTHON_VERSION} ${PTHREAD_LIBS}"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
LDCONFIG_DIRS+=	${PREFIX}/lib/hk_classes/

OPTIONS=	MYSQL "Build MySQL driver" on \
		POSTGRESQL "Build PostrgreSQL driver" off \
		ODBC "Build unixODBC driver" off
WITH_MYSQL?=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
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
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=		pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
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

.include <bsd.port.post.mk>
