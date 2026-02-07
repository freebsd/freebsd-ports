PORTNAME=	enter-tex
DISTVERSION=	3.48.0
PORTREVISION=	1
CATEGORIES=	editors
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated TeX/LaTeX editor
WWW=		https://gitlab.gnome.org/World/gedit/enter-tex

LICENSE=	GPLv3+

BUILD_DEPENDS=	itstool:textproc/itstool \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgedit-amtk-5.so:x11-toolkits/amtk \
		libgedit-tepl-6.so:x11-toolkits/tepl6 \
		libgedit-gtksourceview-300.so:x11-toolkits/libgedit-gtksourceview \
		libgspell-1.so:textproc/gspell

USES=		compiler:c11 desktop-file-utils gettext gnome meson \
		pkgconfig tar:bz2 tex vala:build
USE_GNOME=	dconf glib20 gtk30 introspection:build
USE_TEX=	formats

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/gedit

MESON_ARGS=	-Dtests=false
GLIB_SCHEMAS=	org.gnome.enter_tex.gschema.xml

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk_doc

# https://gitlab.gnome.org/World/gedit/enter-tex/-/issues/19
pre-build:
	@(cd ${BUILD_WRKSRC}; if ! ${DO_MAKE_BUILD} src/gtex/Gtex-1.gir; then \
		if [ -n "${BUILD_FAIL_MESSAGE}" ]; then \
			${ECHO_MSG} "===> Compilation failed unexpectedly." ;\
			(${ECHO_CMD} "${BUILD_FAIL_MESSAGE}") ;\
		fi ;\
	fi)

.include <bsd.port.mk>
