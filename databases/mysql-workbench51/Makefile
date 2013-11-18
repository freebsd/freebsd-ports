# Created by: Maxim Ignatenko
# $FreeBSD$

PORTNAME=	mysql-workbench-oss
PORTVERSION?=	5.1.16
PORTREVISION=	8
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	MySQLGUITools
PKGNAMESUFFIX?=	51

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The MySQL Workbench

LIB_DEPENDS+=	libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libzip.so:${PORTSDIR}/archivers/libzip \
		libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
		libcairo.so:${PORTSDIR}/graphics/cairo

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	PYTHON

USE_AUTOTOOLS=	autoheader autoconf automake aclocal libtool
AUTOMAKE_ARGS=	--add-missing --foreign
ACLOCAL_ARGS=
AUTOCONF_ARGS=
USE_LDCONFIG=	${PREFIX}/lib/mysql-workbench
SUBDIRS=	ext/yassl/taocrypt ext/yassl .
AUTOTOOLSFILES=	configure.in

USES=		dos2unix
DOS2UNIX_REGEX=	.*ext/yassl/.*(Makefile.am|configure.in)
USE_GL=		gl glu
USE_GNOME=	libglade2 intltool libgnome gtk20 pango orbit2
USE_LUA=	5.1
LUA_COMPS=	lua

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PKGNAMESUFFIX} == 51
CONFLICTS=	mysql-workbench-oss52*
EXTRA_PATCHES=	${PATCHDIR}/extra-51-modules__wb.utils__Makefile.am
.endif

DATADIR=	${PREFIX}/share/mysql-workbench

CXXFLAGS+=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GNOME2_DIR="${LOCALBASE}" LUA_LIBS="-llua"

USE_MYSQL=	client
DEFAULT_MYSQL_VER=	51
IGNORE_WITH_MYSQL=	55

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

run-autotools-aclocal:
.for dir in ${SUBDIRS}
	@(cd ${WRKSRC}/${dir} && \
		${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} ${ACLOCAL_ARGS})
.endfor

run-autotools-autoheader:
.for dir in ${SUBDIRS}
	@(cd ${WRKSRC}/${dir} && if ${GREP} "^AM_CONFIG_HEADER" configure.in \
		>/dev/null; then ${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER} \
		${AUTOHEADER_ARGS}; fi)
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

.include <bsd.port.post.mk>
