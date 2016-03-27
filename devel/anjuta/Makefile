# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anjuta
PORTVERSION=	3.18.2
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated Development Environment for C and C++

BUILD_DEPENDS=	autogen:${PORTSDIR}/devel/autogen \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre \
		libgdl-3.so:${PORTSDIR}/x11-toolkits/gdl
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		autogen:${PORTSDIR}/devel/autogen \
		automake>=0:${PORTSDIR}/devel/automake \
		autoconf>=0:${PORTSDIR}/devel/autoconf \
		libtool>=2.4:${PORTSDIR}/devel/libtool \
		gdb>=7.10:${PORTSDIR}/devel/gdb \
		gmake:${PORTSDIR}/devel/gmake \
		yelp>=3.0.0:${PORTSDIR}/x11/yelp

PORTSCOUT=	limitw:1,even

USES=		bison desktop-file-utils gettext gmake gnome libtool pathfix \
		perl5 pkgconfig:both python shared-mime-info shebangfix tar:xz
SHEBANG_FILES=	plugins/project-wizard/templates/js_minimal/src/main.js \
		plugins/tools/scripts/find-fixmes.pl \
		plugins/tools/scripts/translation-status.pl \
		plugins/tools/scripts/prepare-changelog.pl
SHEBANG_LANG+=	gjs
gjs_OLD_CMD=	/usr/bin/gjs
gjs_CMD=	${LOCALBASE}/bin/gjs

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gtksourceview3 intlhack libgda5 libwnck3 vte3
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-symbol-db-shm=/tmp \
		--disable-packagekit \
		--disable-neon \
		--enable-compile-warnings=minimum \
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
		org.gnome.anjuta.plugins.git.gschema.xml \
		org.gnome.anjuta.plugins.indent-c.gschema.xml \
		org.gnome.anjuta.plugins.indent-python.gschema.xml \
		org.gnome.anjuta.plugins.js.gschema.xml \
		org.gnome.anjuta.plugins.message-manager.gschema.xml \
		org.gnome.anjuta.plugins.parser-cxx.gschema.xml \
		org.gnome.anjuta.plugins.project-wizard.gschema.xml \
		org.gnome.anjuta.plugins.python.gschema.xml \
		org.gnome.anjuta.plugins.run.gschema.xml \
		org.gnome.anjuta.plugins.sourceview.gschema.xml \
		org.gnome.anjuta.plugins.vala.gschema.xml \
		org.gnome.anjuta.snippets.gschema.xml \
		org.gnome.anjuta.starter.gschema.xml \
		org.gnome.anjuta.symbol-db.gschema.xml \
		org.gnome.anjuta.terminal.gschema.xml \
		org.gnome.anjuta.tools.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	SVN DEVHELP VALA GLADE TERMINAL
OPTIONS_DEFAULT=SVN DEVHELP VALA GLADE TERMINAL
SVN_DESC=	Subversion plugin
DEVHELP_DESC=	Devhelp plugin
VALA_DESC=	Vala support
GLADE_DESC=	Build glade plugin
TERMINAL_DESC=	Build build-in terminal

GLADE_LIB_DEPENDS=	libgladeui-2.so:${PORTSDIR}/devel/glade
GLADE_CONFIGURE_ENABLE=	plugin-glade

TERMINAL_USE=	GNOME=vte3
TERMINAL_CONFIGURE_ENABLE=	plugin-terminal

SVN_BUILD_DEPENDS=	svn:${PORTSDIR}/devel/subversion
SVN_LIB_DEPENDS=	libapr-1.so:${PORTSDIR}/devel/apr1 \
			libserf-1.so:${PORTSDIR}/www/serf
SVN_RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion
SVN_CONFIGURE_ENABLE=	plugin-subversion

DEVHELP_LIB_DEPENDS=	libdevhelp-3.so:${PORTSDIR}/devel/devhelp
DEVHELP_CONFIGURE_ENBABLE=	plugin-devhelp

VALA_VER=		0.30
VALA_BUILD_DEPENDS=	vala>=${VALA_VER}<${VALA_VER}.99:${PORTSDIR}/lang/vala
VALA_RUN_DEPENDS=	vala>=${VALA_VER}<${VALA_VER}.99:${PORTSDIR}/lang/vala
VALA_CONFIGURE_ENABLE=	vala

post-patch:
	@${REINPLACE_CMD} -e 's|"make|"gmake|g' \
		${WRKSRC}/plugins/build-basic-autotools/plugin.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		${WRKSRC}/libanjuta/anjuta-utils.c
	@${REINPLACE_CMD} -e 's|ac_ct_CXX" = "x"|CXX" = "x"|g' \
		-e 's|libvala-0.28|libvala-${VALA_VER}|g' \
		-e 's|valaver="-0.28"|valaver="-${VALA_VER}"|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|values.h|limits.h|g' \
		${WRKSRC}/plugins/project-wizard/property.h \
		${WRKSRC}/plugins/project-wizard/install.h
	@${REINPLACE_CMD} -e 's|-fprofile-arcs||g' \
		${WRKSRC}/libanjuta/tests/Makefile.in \
		${WRKSRC}/libanjuta/tests/Makefile.am
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		${WRKSRC}/plugins/gdb/debugger.c

.include <bsd.port.mk>
