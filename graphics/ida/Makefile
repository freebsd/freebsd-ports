# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ida
PORTVERSION=	2.09
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://www.kraxel.org/releases/fbida/
DISTNAME=	fbida-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and fast motif-based image viewer and editor

LICENSE=	GPLv2

LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif

OPTIONS_DEFINE=	GIF PCF PNG SANE TIFF WEBP DOCS
OPTIONS_DEFAULT=	GIF PNG TIFF
PCD_DESC=	Enable PhotoCD support
SANE_DESC=	Enable SANE support

USE_PERL5=	build
USES=		desktop-file-utils gmake iconv jpeg motif perl5
MAKEFILE=	GNUmakefile
MAKE_ARGS=	JPEG_VER=80 verbose=yes

LDFLAGS+=	${ICONV_LIB}

PORTDOCS=	README TODO INSTALL
PLIST_FILES=	bin/exiftran bin/ida lib/X11/app-defaults/Ida \
		man/man1/exiftran.1.gz man/man1/ida.1.gz \
		${DESKTOPDIR:S/${PREFIX}\///}/ida.desktop

GIB_LIB_DEPENDS=	libgif.so:${PORTSDIR}/graphics/giflib
GIF_MAKE_ARGS_OFF=	HAVE_LIBUNGIF=no

PCD_LIB_DEPENDS=	libpcd.so:${PORTSDIR}/graphics/libpcd
PCD_MAKE_ARGS_OFF=	HAVE_LIBPCD=no

PNG_LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
PNG_MAKE_ARGS_OFF=	HAVE_LIBPNG=no

SANE_LIB_DEPENDS=	libsane.so:${PORTSDIR}/graphics/sane-backends
SANE_MAKE_ARGS_OFF=	HAVE_LIBSANE=no

TIFF_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff
TIFF_MAKE_ARGS=		HAVE_LIBTIFF=no

WEBP_LIB_DEPENDS=	libwebp.so:${PORTSDIR}/graphics/webp
WEBP_MAKE_ARGS_OFF=	HAVE_LIBWEBP=no

post-install:
	${INSTALL_DATA} ${WRKSRC}/desktop/ida.desktop ${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
