PORTNAME=	bookworm
DISTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	miguel@gocobachi.dev
COMMENT=	Simple, focused ebook reader

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	curl>0:ftp/curl \
		html2text>0:textproc/html2text \
		valac:lang/vala
LIB_DEPENDS=	libappstream-glib.so:devel/appstream-glib \
		libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite \
		libpoppler-glib.so:graphics/poppler-glib \
		libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libxml2.so:textproc/libxml2
RUN_DEPENDS=	bash:shells/bash \
		pdftohtml:graphics/poppler-utils \
		unar:archivers/unarchiver \
		unzip:archivers/unzip

USES=		desktop-file-utils gettext gnome meson pkgconfig \
		python:build,run shebangfix sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	babluboy
USE_GNOME=	gdkpixbuf2 glib20 gtk30 libxml2 pango

GLIB_SCHEMAS=	com.github.babluboy.bookworm.gschema.xml
INSTALLS_ICONS=	yes
SHEBANG_FILES=	data/scripts/com.github.babluboy.bookworm.search.sh \
		data/scripts/mobi_lib/mobi_dict.py \
		data/scripts/mobi_lib/mobi_html.py \
		data/scripts/mobi_lib/mobi_index.py \
		data/scripts/mobi_lib/mobi_k8proc.py \
		data/scripts/mobi_lib/mobi_ncx.py \
		data/scripts/mobi_lib/mobi_opf.py \
		data/scripts/mobi_lib/mobi_split.py \
		data/scripts/mobi_lib/mobi_uncompress.py \
		data/scripts/mobi_lib/mobi_unpack.py \
		data/scripts/mobi_lib/mobi_utils.py

MESON_BUILD_DIR=	build

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-configure:
	@${MKDIR} ${WRKSRC}/${MESON_BUILD_DIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${WRKSRC}/${MESON_BUILD_DIR} && ninja test

.include <bsd.port.mk>
