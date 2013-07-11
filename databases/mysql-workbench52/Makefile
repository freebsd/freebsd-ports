# Created by: Maxim Ignatenko
# $FreeBSD$

PORTNAME=	mysql-workbench-gpl
PORTVERSION=	5.2.47
DISTVERSIONSUFFIX=	-src
CATEGORIES=	databases
MASTER_SITES=	MYSQL/MySQLGUITools
PKGNAMESUFFIX=	52

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual database design tool

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	zip:${PORTSDIR}/archivers/libzip \
		boost_system:${PORTSDIR}/devel/boost-libs \
		sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		pcre:${PORTSDIR}/devel/pcre \
		cairo:${PORTSDIR}/graphics/cairo \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring \
		ctemplate:${PORTSDIR}/textproc/google-ctemplate \
		tinyxml:${PORTSDIR}/textproc/tinyxml \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:${PORTSDIR}/misc/py-pexpect \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:${PORTSDIR}/security/py-paramiko

OPTIONS_DEFINE=	PYTHON_UTILS UNIXODBC
PYTHON_UTILS_DESC=	Python scripts useful for administering MySQL

USES=		gettext gmake pathfix pkgconfig shared-mime-info
USE_GCC=	any
USE_GL=		gl
USE_GNOME=	gnomehier gtk20 libxml2
USE_PYTHON=	-2.7
USE_LUA=	5.1
LUA_COMPS=	lua
USE_MYSQL=	client
USE_SQLITE=	3
USE_AUTOTOOLS=	libtoolize aclocal automake autoheader autoconf
LIBTOOLIZE_ARGS=--copy --force
ACLOCAL_ARGS=	# none
AUTOMAKE_ARGS=	--copy --force-missing --foreign
CONFIGURE_ENV=	LUA_CFLAGS="$$(pkg-config --cflags lua-${LUA_VER})" \
		LUA_LIBS="$$(pkg-config --libs lua-${LUA_VER})" \
		TINYXML_CFLAGS="-I${LOCALBASE}/include" \
		TINYXML_LIBS="-L${LOCALBASE}/lib -ltinyxml" \
		ac_cv_header_netinet_tcp_h=yes
CONFIGURE_ARGS=	--docdir=${WRKDIR}/fakeroot
USE_LDCONFIG=	${PREFIX}/lib/mysql-workbench
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

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

.if ${PORT_OPTIONS:MUNIXODBC}
LIB_DEPENDS+=	odbccr:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=--with-unixodbc
.else
LIB_DEPENDS+=	iodbc:${PORTSDIR}/databases/libiodbc
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/spawn/s|/bin/bash|/bin/sh|' \
		${WRKSRC}/ext/python/pexpect/pexpect.py
	@${REINPLACE_CMD} -e \
		's|-O0 -g3||' \
		${WRKSRC}/ext/scintilla/gtk/Makefile.am
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
	@${FIND} ${WRKSRC} -name "*.py" | ${XARGS} ${REINPLACE_CMD} -e \
		'/^#!/s|/usr/bin/python.*|${SETENV} python|'

post-install:
.for i in lib/mysql-workbench/modules share/mysql-workbench/libraries
	@${PYTHON_CMD} -m compileall ${PREFIX}/${i}
.endfor
.if ${PORT_OPTIONS:MPYTHON_UTILS}
	(cd ${WRKSRC}/ext && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} DESTDIR="${DESTDIR}/"  \
		install-utils install-connector)
.endif

.include <bsd.port.mk>
