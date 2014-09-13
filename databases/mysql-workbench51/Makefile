# Created by: Maxim Ignatenko
# $FreeBSD$

PORTNAME=	mysql-workbench-oss
PORTVERSION=	5.1.16
PORTREVISION=	11
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	MySQLGUITools
PKGNAMESUFFIX=	51

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The MySQL Workbench

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libzip.so:${PORTSDIR}/archivers/libzip \
		libtolua++-${LUA_VER}.so:${PORTSDIR}/lang/tolua++

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	PYTHON

USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
ACLOCAL_ARGS=	-I m4
AUTOMAKE_ARGS=	-a -c -f --foreign
USE_LDCONFIG=	${PREFIX}/lib/mysql-workbench
SUBDIRS=	ext/yassl/taocrypt ext/yassl ext/ctemplate/ctemplate-src .

USES=		dos2unix libtool lua:51
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

run-autotools-libtoolize:
.for dir in ${SUBDIRS}
	@(cd ${WRKSRC}/${dir} && \
		${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} ${LIBTOOLIZE_ARGS})
.endfor

run-autotools-aclocal:
.for dir in ${SUBDIRS}
	@(cd ${WRKSRC}/${dir} && \
		${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} ${ACLOCAL_ARGS})
.endfor

run-autotools-autoheader:
.for dir in ${SUBDIRS}
	@(cd ${WRKSRC}/${dir} && \
		${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER} ${AUTOHEADER_ARGS})
.endfor

run-autotools-automake:
.for dir in ${SUBDIRS}
	@(cd ${WRKSRC}/${dir} && \
		${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} ${AUTOMAKE_ARGS})
.endfor

run-autotools-autoconf:
.for dir in ${SUBDIRS}
	@(cd ${WRKSRC}/${dir} && \
		${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF} ${AUTOCONF_ARGS})
.endfor

.include <bsd.port.mk>
