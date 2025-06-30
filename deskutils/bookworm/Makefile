PORTNAME=	bookworm
DISTVERSION=	1.1.2
PORTREVISION=	25
CATEGORIES=	deskutils

MAINTAINER=	miguel@gocobachi.dev
COMMENT=	Simple, focused ebook reader
WWW=		https://babluboy.github.io/bookworm/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	curl>0:ftp/curl \
		html2text>0:textproc/html2text
LIB_DEPENDS=	libappstream-glib.so:devel/appstream-glib \
		libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite \
		libpoppler-glib.so:graphics/poppler-glib \
		libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40
RUN_DEPENDS=	bash:shells/bash \
		pdftohtml:graphics/poppler-utils \
		unar:archivers/unarchiver \
		unzip:archivers/unzip

USES=		desktop-file-utils gettext gnome meson pkgconfig \
		python shebangfix sqlite vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	babluboy
USE_GNOME=	gdkpixbuf glib20 gtk30 libxml2 pango

GLIB_SCHEMAS=	com.github.babluboy.bookworm.gschema.xml
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
	cd ${WRKSRC}/${MESON_BUILD_DIR} && ${LOCALBASE}/bin/ninja test

.include <bsd.port.mk>
