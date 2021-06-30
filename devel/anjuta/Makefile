# Created by: Dmitry Sivachenko <demon@FreeBSD.org>

PORTNAME=	anjuta
PORTVERSION=	3.34.0
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated Development Environment for C and C++

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autogen:devel/autogen \
		itstool:textproc/itstool
LIB_DEPENDS+=	libpcre.so:devel/pcre \
		libexpat.so:textproc/expat2 \
		libfribidi.so:converters/fribidi \
		libgdl-3.so:x11-toolkits/gdl
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:misc/gnome-icon-theme \
		autogen:devel/autogen \
		automake>=0:devel/automake \
		autoconf>=0:devel/autoconf \
		libtool>=2.4:devel/libtool \
		gdb>=7.10:devel/gdb \
		gmake:devel/gmake \
		yelp>=3.0.0:x11/yelp

PORTSCOUT=	limitw:1,even

USES=		bison compiler:c11 desktop-file-utils gettext gmake gnome \
		libtool pathfix perl5 pkgconfig:both python shared-mime-info \
		shebangfix tar:xz
SHEBANG_FILES=	plugins/project-wizard/templates/js_minimal/src/main.js \
		plugins/tools/scripts/find-fixmes.pl \
		plugins/tools/scripts/translation-status.pl \
		plugins/tools/scripts/prepare-changelog.pl
SHEBANG_LANG+=	gjs
gjs_OLD_CMD=	/usr/bin/gjs
gjs_CMD=	${LOCALBASE}/bin/gjs

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_GNOME=	cairo gtksourceview3 intlhack libgda5 libwnck3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-symbol-db-shm=/tmp \
		--disable-packagekit \
		--disable-neon \
		--disable-vala \
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
		org.gnome.anjuta.tools.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DEVHELP GLADE SUBVERSION TERMINAL
OPTIONS_DEFAULT=DEVHELP GLADE SUBVERSION TERMINAL
DEVHELP_DESC=	Devhelp plugin
GLADE_DESC=	Build glade plugin
TERMINAL_DESC=	Build build-in terminal

GLADE_LIB_DEPENDS=	libgladeui-2.so:devel/glade
GLADE_CONFIGURE_ENABLE=	plugin-glade

TERMINAL_USE=	GNOME=vte3
TERMINAL_CONFIGURE_ENABLE=	plugin-terminal
TERMINAL_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libpcre2-8.so:devel/pcre2
TERMINAL_VARS=		GLIB_SCHEMAS+=org.gnome.anjuta.terminal.gschema.xml

SUBVERSION_LIB_DEPENDS=	libapr-1.so:devel/apr1 \
			libserf-1.so:www/serf \
			libsvn_client-1.so:devel/subversion
SUBVERSION_CONFIGURE_ENABLE=	plugin-subversion

DEVHELP_LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
			libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
			libdevhelp-3.so:devel/devhelp
DEVHELP_CONFIGURE_ENABLE=	plugin-devhelp

post-patch:
	@${REINPLACE_CMD} -e 's|"make|"gmake|g' \
		${WRKSRC}/plugins/build-basic-autotools/plugin.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		${WRKSRC}/libanjuta/anjuta-utils.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		${WRKSRC}/plugins/gdb/debugger.c

.include <bsd.port.mk>
