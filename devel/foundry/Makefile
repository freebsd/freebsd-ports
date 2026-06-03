PORTNAME=	foundry
PORTVERSION=	1.0.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework to develop applications from command line
WWW=		https://gitlab.gnome.org/GNOME/foundry

LICENSE=	LGPL21+

LIB_DEPENDS=	libgom-1.0.so:databases/gom \
		libdex-1.so:devel/libdex \
		libjson-glib-1.0.so:devel/json-glib \
		libpeas-2.so:devel/libpeas \
		libtemplate_glib-1.0.so:devel/template-glib \
		libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2 \
		libcmark.so:textproc/cmark \
		libspelling-1.so:x11-toolkits/libspelling \
		libeditorconfig.so:editors/editorconfig-core-c

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 gtk40 gtksourceview5 introspection:build \
		libxml2 vte3
GLIB_SCHEMAS=	app.devsuite.foundry.ctags.gschema.xml \
		app.devsuite.foundry.gschema.xml \
		app.devsuite.foundry.lsp.gschema.xml \
		app.devsuite.foundry.network.gschema.xml \
		app.devsuite.foundry.project.gschema.xml \
		app.devsuite.foundry.run.gschema.xml \
		app.devsuite.foundry.terminal.gschema.xml \
		app.devsuite.foundry.text.gschema.xml
USE_LDCONFIG=	yes

MESON_ARGS=	-Dgnome_sdk_version=47.10 \
		-Dfeature-flatpak=false \
		-Dfeature-llm=false \
		-Dwebkit=false \
		-Dplugin-qemu=false \
		-Dplugin-dub=false \
		-Dplugin-gradle=false

PORTSCOUT=	limit:^1\.0\.

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/plugins/cmake/plugin-cmake-build-addin.c \
		${WRKSRC}/plugins/fallbacks/host-sdk/plugin-host-documentation-provider.c

.include <bsd.port.mk>
