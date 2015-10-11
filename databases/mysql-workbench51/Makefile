# Created by: Maxim Ignatenko
# $FreeBSD$

PORTNAME=	mysql-workbench-oss
PORTVERSION=	5.1.16
PORTREVISION=	12
CATEGORIES=	databases
MASTER_SITES=	MYSQL/MySQLGUITools
PKGNAMESUFFIX=	51

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The MySQL Workbench

DEPRECATED=	EOL upstream, use databases/mysql-workbench52 instead
EXPIRATION_DATE=	2015-11-10

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libzip.so:${PORTSDIR}/archivers/libzip \
		libtolua++-${LUA_VER}.so:${PORTSDIR}/lang/tolua++

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	PYTHON

USE_LDCONFIG=	${PREFIX}/lib/mysql-workbench

USES=		autoreconf dos2unix libtool lua:51
DOS2UNIX_REGEX=	.*ext/yassl/.*(Makefile.am|configure.in)
USE_GL=		gl
USE_GNOME=	cairo gtkmm24 libglade2 libgnome libsigc++20 libxml2

CONFLICTS=	mysql-workbench-gpl*
DATADIR=	${PREFIX}/share/mysql-workbench

CXXFLAGS+=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GNOME2_DIR="${LOCALBASE}" LUA_LIBS="-llua-${LUA_VER}"

USE_MYSQL=	client
DEFAULT_MYSQL_VER=	51
IGNORE_WITH_MYSQL=	55

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--enable-python-modules
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/backend/windows/wbprivate.wr/src/stdafx.h \
		${WRKSRC}/backend/wbprivate/workbench/stdafx.h \
		${WRKSRC}/library/canvas/src/stdafx.h \
		${WRKSRC}/library/canvas/src/mdc_canvas_view.h \
		${WRKSRC}/library/canvas/src/mdc_canvas_view_printing.cpp \
		${WRKSRC}/modules/wb.mysql.import/src/stdafx.h \
		${WRKSRC}/modules/db.mysql.sqlparser/src/stdafx.h \
		${WRKSRC}/modules/db.mysql.sqlparser/src/mysql_sql_parser_fe.cpp \
		${WRKSRC}/plugins/wb.printing/backend/stdafx.h \
		${WRKSRC}/plugins/db.mysql/backend/db_plugin_be.cpp

pre-configure:
	(cd ${WRKSRC}/ext/yassl/taocrypt && ${LOCALBASE}/bin/autoreconf -f -i)
	(cd ${WRKSRC}/ext/yassl && ${LOCALBASE}/bin/autoreconf -f -i)

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
