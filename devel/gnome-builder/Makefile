PORTNAME=	gnome-builder
PORTVERSION=	42.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	IDE for writing software for GNOME

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcmark.so:textproc/cmark \
		libdazzle-1.0.so:x11-toolkits/libdazzle \
		libdevhelp-3.so:devel/devhelp \
		libenchant-2.so:textproc/enchant2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libgit2-glib-1.0.so:devel/libgit2-glib \
		libgit2.so:devel/libgit2 \
		libgladeui-2.so:devel/glade \
		libgspell-1.so:textproc/gspell \
		libhandy-1.so:x11-toolkits/libhandy \
		libjson-glib-1.0.so:devel/json-glib \
		libjsonrpc-glib-1.0.so:devel/jsonrpc-glib \
		libpcre.so:devel/pcre \
		libpeas-1.0.so:devel/libpeas \
		libportal.so:deskutils/libportal \
		libsoup-2.4.so:devel/libsoup \
		libtemplate_glib-1.0.so:devel/template-glib \
		libvala-0.48.so:lang/vala \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

PORTSCOUT=	limitw:1,even
PORTDOCS=	*

CONFLICTS_BUILD=	gnome-builder-3.16.*

USES=		compiler:c++11-lang desktop-file-utils gettext gnome \
		localbase:lfdlags meson pkgconfig python:3.6+,build shebangfix \
		tar:xz
USE_GNOME=	cairo gtksourceview4 introspection libxml2 vte3
SHEBANG_FILES=	${WRKSRC}/src/plugins/gradle/gradle_plugin.py \
		${WRKSRC}/src/plugins/maven/maven_plugin.py
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}

MESON_ARGS=	-Dplugin_color_picker=false \
		-Dplugin_flatpak=false \
		-Dplugin_jhbuild=false \
		-Dplugin_qemu=false \
		-Dplugin_sysprof=false \
		-Dplugin_update_manager=false

PLIST_SUB=	BUILDER_VERSION=${PORTVERSION:R}

GLIB_SCHEMAS=	org.gnome.builder.build.gschema.xml \
		org.gnome.builder.clang.gschema.xml \
		org.gnome.builder.code-insight.gschema.xml \
		org.gnome.builder.editor.gschema.xml \
		org.gnome.builder.editor.language.gschema.xml \
		org.gnome.builder.extension-type.gschema.xml \
		org.gnome.builder.gnome-code-assistance.gschema.xml \
		org.gnome.builder.gschema.xml \
		org.gnome.builder.plugin.gschema.xml \
		org.gnome.builder.plugins.copyright.gschema.xml \
		org.gnome.builder.plugins.eslint.gschema.xml \
		org.gnome.builder.plugins.stylelint.gschema.xml \
		org.gnome.builder.project-tree.gschema.xml \
		org.gnome.builder.project.gschema.xml \
		org.gnome.builder.rust-analyzer.gschema.xml \
		org.gnome.builder.terminal.gschema.xml \
		org.gnome.builder.workbench.gschema.xml

OPTIONS_SUB=		YES
OPTIONS_DEFINE=		CLANG DOCS
OPTIONS_DEFAULT=	CLANG

# track the latest llvm/clang version, the config script picks the newest available
LLVM_VER=		${LLVM_DEFAULT}
CLANG_DESC=		Build the clang plugin
CLANG_MESON_TRUE=	plugin_clang
CLANG_BUILD_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}
CLANG_RUN_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}

# 11.1 and older has issues with vala generated code.
post-patch:
	${REINPLACE_CMD} -e '/-Werror=return-type/d' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
