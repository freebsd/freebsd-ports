PORTNAME=	pqiv
PORTVERSION=	2.13.2
PORTREVISION=	4
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/phillipberndt/pqiv/commit/
PATCHFILES=	a36571549a32d2ec41d6f523d443de74e0fb1276.patch:-p1 \
		fc4f1767ee72e3f9cc7c0f7945da6a05b56db458.patch:-p1

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Pretty Quick Image Viewer
WWW=		https://github.com/phillipberndt/pqiv

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
BUILD_DEPENDS=	bash:shells/bash

USES=		compiler gettext-runtime gmake gnome pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	phillipberndt

OPTIONS_DEFINE=	DOCS

OPTIONS_SINGLE=		GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3

OPTIONS_MULTI=		BACKENDS
OPTIONS_MULTI_BACKENDS=	LIBARCHIVE LIBAV PIXBUF POPPLER SPECTRE WAND WEBP
LIBARCHIVE_DESC=	Libarchive formats support
LIBAV_DESC=		Video support
SPECTRE_DESC=		PS/EPS support
WAND_DESC=		ImageMagick image processing support

OPTIONS_DEFAULT=	GTK3 LIBARCHIVE LIBAV PIXBUF POPPLER WEBP

USE_XORG=	x11
USE_GNOME=	cairo gdkpixbuf
HAS_CONFIGURE=	yes

LIBARCHIVE_CONFIGURE_WITH=	archive archive_cbx
LIBARCHIVE_USES=	libarchive

LIBAV_CONFIGURE_WITH=	libav
LIBAV_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

PIXBUF_CONFIGURE_WITH=	gdkpixbuf

POPPLER_CONFIGURE_WITH=	poppler
POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib

SPECTRE_CONFIGURE_WITH=	spectre
SPECTRE_LIB_DEPENDS=	libspectre.so:print/libspectre

WAND_CONFIGURE_WITH=	wand
WAND_USES=		magick:6

WEBP_CONFIGURE_WITH=	webp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

GTK2_CONFIGURE_ON=	--gtk-version=2
GTK2_USE=		GNOME=gtk20

GTK3_CONFIGURE_ON=	--gtk-version=3
GTK3_USE=		GNOME=gtk30

MAKEFILE=	GNUmakefile

PORTDOCS=	README.markdown
PLIST_FILES=	bin/pqiv share/man/man1/pqiv.1.gz

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
post-patch:
	@${REINPLACE_CMD} -e '/#pragma GCC diagnostic/d' \
		-e '/PQIV_DISABLE_PEDANTIC/d' \
		-e '/PQIV_ENABLE_PEDANTIC/d' \
		${WRKSRC}/pqiv.c
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pqiv ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pqiv.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
