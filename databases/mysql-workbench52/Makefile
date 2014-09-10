# Created by: Maxim Ignatenko
# $FreeBSD$

PORTNAME=	mysql-workbench-gpl
PORTVERSION=	5.2.47
PORTREVISION=	6
DISTVERSIONSUFFIX=	-src
CATEGORIES=	databases
MASTER_SITES=	MYSQL/MySQLGUITools
PKGNAMESUFFIX=	52

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual database design tool

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libzip.so:${PORTSDIR}/archivers/libzip \
		libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libctemplate.so:${PORTSDIR}/textproc/google-ctemplate \
		libtinyxml.so:${PORTSDIR}/textproc/tinyxml \
		libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:${PORTSDIR}/misc/py-pexpect \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:${PORTSDIR}/security/py-paramiko

OPTIONS_DEFINE=	PYTHON_UTILS UNIXODBC
PYTHON_UTILS_DESC=	Python scripts useful for administering MySQL

USES=		compiler:gcc-c++11-lib desktop-file-utils gettext gmake iconv \
		libtool lua:51 pathfix pkgconfig python:2 shared-mime-info \
		shebangfix
SHEBANG_FILES=	ext/ctemplate/ctemplate-src/src/htmlparser/*.py \
		ext/mysql-utilities/*.py \
		ext/mysql-utilities/scripts/*.py \
		ext/scintilla/qt/ScintillaEditPy/*.py \
		library/sshtunnel/*.py \
		plugins/wb.admin/backend/config/gen-opt/*.py \
		plugins/wb.admin/gen-opt/*.py \
		plugins/wb.admin/gen-opt/new/*.py \
		plugins/wb.admin/gen-opt/recat/*.py \
		plugins/wb.query.analysis/*.py \
		po/*.py
USE_GL=		gl
USE_GNOME=	gnomehier gtk20 libxml2
USE_MYSQL=	client
USE_SQLITE=	3
USE_AUTOTOOLS=	libtoolize aclocal automake autoheader autoconf
AUTOMAKE_ARGS=	--add-missing --copy --force-missing --foreign
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LUA_CFLAGS="$$(pkg-config --cflags lua-${LUA_VER})" \
		LUA_LIBS="$$(pkg-config --libs lua-${LUA_VER})" \
		TINYXML_CFLAGS="-I${LOCALBASE}/include" \
		TINYXML_LIBS="-L${LOCALBASE}/lib -ltinyxml" \
		ac_cv_header_netinet_tcp_h=yes
CONFIGURE_ARGS=	--docdir=${WRKDIR}/fakeroot
USE_LDCONFIG=	${PREFIX}/lib/mysql-workbench
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION}" PYTHON_VER="${PYTHON_VER}"

CONFLICTS=	mysql-workbench-oss*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON_UTILS}
CONFIGURE_ARGS+=--enable-mysql-utilities
PLIST_SUB+=	PYTHON_UTILS=""
.else
PLIST_SUB+=	PYTHON_UTILS="@comment "
.endif

LIB_DEPENDS+=	libodbc.so:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=--with-unixodbc

post-patch:
	@${REINPLACE_CMD} -e \
		's|/bin/bash|/bin/sh|' \
		${WRKSRC}/build/build_freetds.sh
	@${REINPLACE_CMD} -e \
		's| $$(pkgdatadir)| $$(DESTDIR)$$(pkgdatadir)|' \
		${WRKSRC}/ext/Makefile.am
	@${REINPLACE_CMD} -e \
		'/spawn/s|/bin/bash|/bin/sh|' \
		${WRKSRC}/ext/python/pexpect/pexpect.py
	@${REINPLACE_CMD} -e \
		's|-O0 -g3||' \
		${WRKSRC}/ext/scintilla/gtk/Makefile.am
	@${REINPLACE_CMD} -e \
		'/^wbcopytables_LDADD=/s/$$/ ${ICONV_LIB}/' \
		${WRKSRC}/plugins/migration/Makefile.am
	@${REINPLACE_CMD} -e \
		'/f.write/s|bash -i|sh -i| ; \
		 /call/s|/bin/bash|/bin/sh| ; \
		 /paths/s|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/modules/wb.utils/wb_utils_grt.py
	@${REINPLACE_CMD} -e \
		'/spawn/s|/bin/bash|/bin/sh|' \
		${WRKSRC}/plugins/wb.admin/backend/wb_server_management.py
	@${REINPLACE_CMD} -e \
		's|/usr/bin/sudo|${LOCALBASE}/bin/sudo| ; \
		 s|/bin/bash|/bin/sh|' \
		${WRKSRC}/plugins/wb.admin/frontend/wb_admin_grt.py

post-install:
.for i in lib/mysql-workbench/modules share/mysql-workbench/libraries
	@(cd ${STAGEDIR}/${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PREFIX} -f ${i})
.endfor
.if ${PORT_OPTIONS:MPYTHON_UTILS}
	${DO_MAKE_BUILD} -C ${WRKSRC}/ext install-utils install-connector
	@(cd ${STAGEDIR}/${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PREFIX} -f share/mysql-workbench/python)
.endif

.include <bsd.port.mk>
