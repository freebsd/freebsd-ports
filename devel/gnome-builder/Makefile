# $FreeBSD$

PORTNAME=	gnome-builder
PORTVERSION=	3.28.4
PORTREVISION=	4
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	IDE for writing software for GNOME

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libjson-glib-1.0.so:devel/json-glib \
		libpeas-1.0.so:devel/libpeas \
		libjsonrpc-glib-1.0.so:devel/jsonrpc-glib \
		libtemplate_glib-1.0.so:devel/template-glib \
		libdazzle-1.0.so:x11-toolkits/libdazzle \
		libenchant-2.so:textproc/enchant2 \
		libgspell-1.so:textproc/gspell \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libdevhelp-3.so:devel/devhelp \
		libgit2-glib-1.0.so:devel/libgit2-glib \
		libpcre.so:devel/pcre \
		libvala-0.40.so:lang/vala

PORTSCOUT=	limitw:1,even
PORTDOCS=	*

CONFLICTS_BUILD=	gnome-builder-3.16.*

USES=		compiler:c++11-lang cpe desktop-file-utils gettext gnome meson pkgconfig python:3.6+,build tar:xz
USE_GNOME=	cairo gtksourceview3 introspection libxml2 vte3
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPE_VENDOR=	gnome
BINARY_ALIAS=	python3=${PYTHON_VERSION}

MESON_ARGS=	-Dwith_flatpak=false \
		-Dwith_sysprof=false \
		-Dwith_qemu=false \
		-Dwith_jhbuild=false

PLIST_SUB+=	PORTVER=${PORTVERSION}

GLIB_SCHEMAS=	org.gnome.builder.build.gschema.xml \
		org.gnome.builder.code-insight.gschema.xml \
		org.gnome.builder.editor.gschema.xml \
		org.gnome.builder.editor.language.gschema.xml \
		org.gnome.builder.extension-type.gschema.xml \
		org.gnome.builder.gnome-code-assistance.gschema.xml \
		org.gnome.builder.gschema.xml \
		org.gnome.builder.plugin.gschema.xml \
		org.gnome.builder.plugins.color_picker_plugin.gschema.xml \
		org.gnome.builder.plugins.eslint.gschema.xml \
		org.gnome.builder.project-tree.gschema.xml \
		org.gnome.builder.project.gschema.xml \
		org.gnome.builder.terminal.gschema.xml \
		org.gnome.builder.workbench.gschema.xml

OPTIONS_SUB=	YES
OPTIONS_DEFINE=	CLANG DOCS
OPTIONS_DEFAULT=	CLANG

# track the latest llvm/clang version, the config script picks the newest available
LLVM_VER=	60
CLANG_DESC=	Build the clang plugin
CLANG_MESON_TRUE=	with_clang
CLANG_BUILD_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}
CLANG_RUN_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}

# jedi plugin with dependancies doesn't work
MESON_ARGS+=	-Dwith_jedi=false
#RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}jedi>0:devel/py-jedi@${PY_FLAVOR}

# 11.1 and older has issues with vala generated code.
post-patch:
	${REINPLACE_CMD} -e '/-Werror=return-type/d' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
