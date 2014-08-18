# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/anjuta/Makefile 19814 2014-08-15 20:17:00Z gusi $

PORTNAME=	anjuta
PORTVERSION=	3.6.2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated Development Environment for C and C++

BUILD_DEPENDS=	glade>=3.12.0:${PORTSDIR}/devel/glade \
		valac:${PORTSDIR}/lang/vala \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libgladeui-2.so:${PORTSDIR}/devel/glade \
		libgdl-3.so:${PORTSDIR}/x11-toolkits/gdl
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		autogen:${PORTSDIR}/devel/autogen \
		automake>=0:${PORTSDIR}/devel/automake \
		autoconf>=0:${PORTSDIR}/devel/autoconf \
		libtool>=2.4:${PORTSDIR}/devel/libtool \
		gdb>=7.3:${PORTSDIR}/devel/gdb \
		yelp>=3.0.0:${PORTSDIR}/x11/yelp
USE_CSTD=	gnu89
USES=		bison desktop-file-utils gettext gmake pathfix perl5 \
		pkgconfig python shared-mime-info shebangfix tar:xz
SHEBANG_FILES=	plugins/project-wizard/templates/js_minimal/src/main.js \
		plugins/tools/scripts/find-fixmes.pl \
		plugins/tools/scripts/translation-status.pl \
		plugins/tools/scripts/prepare-changelog.pl
SHEBANG_LANG+=	gjs
gjs_OLD_CMD=	/usr/bin/gjs
gjs_CMD=	${LOCALBASE}/bin/gjs
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomeprefix vte3 gtksourceview3 libgda5 libwnck3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-symbol-db-shm=/tmp \
		--disable-packagekit \
		--enable-introspection=yes
DOCSDIR=	share/doc/libanjuta
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.anjuta.cvs.gschema.xml \
		org.gnome.anjuta.document-manager.gschema.xml \
		org.gnome.anjuta.file-manager.gschema.xml \
		org.gnome.anjuta.gschema.xml \
		org.gnome.anjuta.plugins.build.gschema.xml \
		org.gnome.anjuta.plugins.cpp.gschema.xml \
		org.gnome.anjuta.plugins.debug-manager.gschema.xml \
		org.gnome.anjuta.plugins.indent-c.gschema.xml \
		org.gnome.anjuta.plugins.indent-python.gschema.xml \
		org.gnome.anjuta.plugins.js.gschema.xml \
		org.gnome.anjuta.plugins.message-manager.gschema.xml \
		org.gnome.anjuta.plugins.parser-cxx.gschema.xml \
		org.gnome.anjuta.plugins.python.gschema.xml \
		org.gnome.anjuta.plugins.run.gschema.xml \
		org.gnome.anjuta.plugins.sourceview.gschema.xml \
		org.gnome.anjuta.plugins.vala.gschema.xml \
		org.gnome.anjuta.snippets.gschema.xml \
		org.gnome.anjuta.symbol-db.gschema.xml \
		org.gnome.anjuta.terminal.gschema.xml \
		org.gnome.anjuta.tools.gschema.xml

OPTIONS_DEFINE=	SVN DEVHELP GRAPHVIZ VALA
OPTIONS_DEFAULT=DEVHELP GRAPHVIZ
SVN_DESC=	Subversion plugin
DEVHELP_DESC=	Devhelp plugin
GRAPHVIZ_DESC=	Inheritance plugin
VALA_DESC=	Vala support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSVN}
BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
LIB_DEPENDS+=	libapr-1.so:${PORTSDIR}/devel/apr1
LIB_DEPENDS+=	libneon.so:${PORTSDIR}/www/neon29
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
PLIST_SUB+=	SVN=""
.else
CONFIGURE_ARGS+=--disable-plugin-subversion
PLIST_SUB+=	SVN="@comment "
.endif

.if ${PORT_OPTIONS:MDEVHELP}
LIB_DEPENDS+=	libdevhelp-3.so:${PORTSDIR}/devel/devhelp
PLIST_SUB+=	DEVHELP=""
.else
CONFIGURE_ARGS+=--disable-plugin-devhelp
# XXX Even if we disable the devhelp plugin it gets build and installed.
# See if versions beyond 2.26.1.0 still do this.
#PLIST_SUB+=	DEVHELP="@comment "
PLIST_SUB+=	DEVHELP=""
.endif

.if ${PORT_OPTIONS:MGRAPHVIZ}
CONFIGURE_ARGS+=--enable-graphviz
BUILD_DEPENDS+=	neato:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS+=	neato:${PORTSDIR}/graphics/graphviz
PLIST_SUB+=	GRAPHVIZ=""
.else
CONFIGURE_ARGS+=--disable-graphviz
PLIST_SUB+=	GRAPHVIZ="@comment "
.endif

.if ${PORT_OPTIONS:MVALA}
CONFIGURE_ARGS+=--enable-vala
BUILD_DEPENDS+=	vala>=0.14.0:${PORTSDIR}/lang/vala
RUN_DEPENDS+=	vala>=0.14.0:${PORTSDIR}/lang/vala
PLIST_SUB+=	VALA=""
.else
CONFIGURE_ARGS+=--disable-vala
PLIST_SUB+=	VALA="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"make|"gmake|g' \
		${WRKSRC}/plugins/build-basic-autotools/plugin.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		${WRKSRC}/libanjuta/anjuta-utils.c
	@${REINPLACE_CMD} -e 's|ac_ct_CXX" = "x"|CXX" = "x"|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|values.h|limits.h|g' \
		${WRKSRC}/plugins/project-wizard/property.h \
		${WRKSRC}/plugins/project-wizard/install.h
	@${REINPLACE_CMD} -e 's|-fprofile-arcs||g' \
		${WRKSRC}/libanjuta/tests/Makefile.in \
		${WRKSRC}/libanjuta/tests/Makefile.am

.include <bsd.port.mk>
