# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ida
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.kraxel.org/releases/fbida/
DISTNAME=	fbida-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and fast motif-based image viewer and editor

LICENSE=	GPLv2

LIB_DEPENDS=	libexif.so:graphics/libexif

USES=		compiler:c11 desktop-file-utils gmake iconv jpeg motif perl5
USE_PERL5=	build
MAKEFILE=	GNUmakefile
MAKE_ARGS=	HAVE_LINUX_FB_H=no HAVE_GLIBC=no JPEG_VER=80 verbose=yes

LDFLAGS+=	${ICONV_LIB}

PORTDOCS=	README TODO INSTALL
PLIST_FILES=	bin/exiftran bin/ida lib/X11/app-defaults/Ida \
		man/man1/exiftran.1.gz man/man1/ida.1.gz \
		share/applications/ida.desktop

OPTIONS_DEFINE=		DOCS GIF PCD PNG SANE TIFF WEBP
OPTIONS_DEFAULT=	GIF PNG TIFF

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_MAKE_ARGS_OFF=	HAVE_LIBGIF=no
PCD_DESC=		PhotoCD support
PCD_LIB_DEPENDS=	libpcd.so:graphics/libpcd
PCD_MAKE_ARGS_OFF=	HAVE_LIBPCD=no
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MAKE_ARGS_OFF=	HAVE_LIBPNG=no
SANE_LIB_DEPENDS=	libsane.so:graphics/sane-backends
SANE_MAKE_ARGS_OFF=	HAVE_LIBSANE=no
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MAKE_ARGS=		HAVE_LIBTIFF=no
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_MAKE_ARGS_OFF=	HAVE_LIBWEBP=no

post-install:
	${INSTALL_DATA} ${WRKSRC}/desktop/ida.desktop ${STAGEDIR}${DESKTOPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
