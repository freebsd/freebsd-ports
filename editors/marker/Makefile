PORTNAME=	marker
PORTVERSION=	2023.05.02
PORTREVISION=	3
CATEGORIES=	editors

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Gtk3 markdown editor
WWW=		https://fabiocolacio.github.io/Marker/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtkspell3-3.so:textproc/gtkspell3 \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40
RUN_DEPENDS=	pandoc:textproc/hs-pandoc

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	fabiocolacio
GH_PROJECT=	Marker
GH_TUPLE=	Mandarancio:scidown:a7b7f063de4f272ef0ec12d00b98470888e8cb32:scidown/src/scidown \
		Mandarancio:charter:a25dee1214ea9ba5882325066555cb813efbb489:charter/src/scidown/src/charter \
		codeplea:tinyexpr:9476568b69de4c384903f1d5f255907b92592f45:tinyexpr/src/scidown/src/charter/src/tinyexpr

USE_GNOME=	cairo gdkpixbuf glib20 gtk30 gtksourceview3
GLIB_SCHEMAS=	com.github.fabiocolacio.marker.gschema.xml

DATADIR=	${PREFIX}/share/com.github.fabiocolacio.marker

PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
