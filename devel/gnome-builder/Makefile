PORTNAME=	gnome-builder
PORTVERSION=	47.2
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	IDE for writing software for GNOME
WWW=		https://apps.gnome.org/Builder

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcmark.so:textproc/cmark \
		libgit2-glib-1.0.so:devel/libgit2-glib \
		libgit2.so:devel/libgit2 \
		libjson-glib-1.0.so:devel/json-glib \
		libjsonrpc-glib-1.0.so:devel/jsonrpc-glib \
		libpeas-2.so:devel/libpeas \
		libportal.so:deskutils/libportal \
		libportal-gtk4.so:deskutils/libportal-gtk4 \
		libtemplate_glib-1.0.so:devel/template-glib \
		libdex-1.so:devel/libdex \
		libpanel-1.so:x11-toolkits/libpanel \
		libspelling-1.so:x11-toolkits/libspelling \
		libeditorconfig.so:editors/editorconfig-core-c
RUN_DEPENDS=	d-spy:devel/d-spy

PORTSCOUT=	limit:^47\.

USES=		compiler:c++11-lang desktop-file-utils gettext gnome \
		localbase:lfdlags meson pkgconfig python:build shebangfix \
		tar:xz
USE_GNOME=	glib20 gtk40 gtksourceview5 introspection libadwaita \
		libxml2 vte3
SHEBANG_FILES=	${WRKSRC}/build-aux/meson/post_install.py
USE_LDCONFIG=	yes

MESON_ARGS=	-Dwebkit=disabled \
		-Dplugin_sphinx_preview=false \
		-Dplugin_markdown_preview=false \
		-Dplugin_html_preview=false \
		-Dplugin_manuals=false \
		-Dplugin_flatpak=false \
		-Dplugin_jhbuild=false \
		-Dplugin_qemu=false \
		-Dplugin_sysprof=false \
		-Dplugin_swift=false \
		-Dplugin_swiftformat=false \
		-Dplugin_swiftlint=false \
		-Dplugin_update_manager=false \
		-Dplugin_waf=false

PLIST_SUB=	VERSION=${PORTVERSION:C/^([0-9]+)\..*/\1/}

GLIB_SCHEMAS=	org.gnome.builder.build.gschema.xml \
		org.gnome.builder.clang.gschema.xml \
		org.gnome.builder.code-insight.gschema.xml \
		org.gnome.builder.copyright.gschema.xml \
		org.gnome.builder.debug.gschema.xml \
		org.gnome.builder.editor.gschema.xml \
		org.gnome.builder.editor.language.gschema.xml \
		org.gnome.builder.extension-type.gschema.xml \
		org.gnome.builder.gschema.xml \
		org.gnome.builder.plugin.gschema.xml \
		org.gnome.builder.project-tree.gschema.xml \
		org.gnome.builder.project.gschema.xml \
		org.gnome.builder.shellcmd.command.gschema.xml \
		org.gnome.builder.shellcmd.gschema.xml \
		org.gnome.builder.spelling.gschema.xml \
		org.gnome.builder.terminal.gschema.xml \
		org.gnome.builder.valgrind.gschema.xml

OPTIONS_SUB=		YES
OPTIONS_DEFINE=		CLANG
OPTIONS_DEFAULT=	CLANG

# track the latest llvm/clang version, the config script picks the newest available
CLANG_DESC=		Build the clang plugin
CLANG_MESON_TRUE=	plugin_clang
CLANG_USES=		llvm:build,run
CLANG_CONFIGURE_ENV=	LLVM_CONFIG=${LLVM_CONFIG}

# 11.1 and older has issues with vala generated code.
post-patch:
	${REINPLACE_CMD} -e '/-Werror=return-type/d' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
