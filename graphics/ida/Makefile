# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ida
PORTVERSION=	2.14
CATEGORIES=	graphics
MASTER_SITES=	https://www.kraxel.org/releases/fbida/
DISTNAME=	fbida-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and fast motif-based image viewer and editor

LICENSE=	GPLv2

LIB_DEPENDS=	libexif.so:graphics/libexif

USES=		desktop-file-utils gmake iconv jpeg motif perl5 pkgconfig xorg
USE_PERL5=	build
USE_XORG=	pixman x11 xext xt
MAKEFILE=	GNUmakefile
MAKE_ARGS=	verbose=yes

LDFLAGS+=	${ICONV_LIB}

PORTDOCS=	README TODO INSTALL
PLIST_FILES=	bin/exiftran bin/ida lib/X11/app-defaults/Ida \
		man/man1/exiftran.1.gz man/man1/ida.1.gz \
		share/applications/ida.desktop

OPTIONS_DEFINE=		DOCS GIF PCD PNG SANE TIFF WEBP
OPTIONS_DEFAULT=	GIF PNG TIFF

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_MAKE_ARGS=		HAVE_LIBGIF=yes
PCD_DESC=		PhotoCD support
PCD_LIB_DEPENDS=	libpcd.so:graphics/libpcd
PCD_MAKE_ARGS=		HAVE_LIBPCD=yes
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MAKE_ARGS=		HAVE_LIBPNG=yes
SANE_LIB_DEPENDS=	libsane.so:graphics/sane-backends
SANE_MAKE_ARGS=		HAVE_LIBSANE=yes
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MAKE_ARGS=		HAVE_LIBTIFF=yes
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_MAKE_ARGS=		HAVE_LIBWEBP=yes

pre-build:
	@${ECHO_CMD} -n > ${WRKSRC}/Make.config
	@${ECHO_CMD} "LIB:=lib" >> ${WRKSRC}/Make.config
	@${ECHO_CMD} "RESDIR:=${PREFIX}/lib/X11" >> ${WRKSRC}/Make.config
	@${ECHO_CMD} "HAVE_ENDIAN_H:=yes" >> ${WRKSRC}/Make.config
	@${ECHO_CMD} "HAVE_LINUX_FB_H:=no" >> ${WRKSRC}/Make.config
	@${ECHO_CMD} "HAVE_NEW_EXIF:=yes" >> ${WRKSRC}/Make.config
	@${ECHO_CMD} "HAVE_GLIBC:=no" >> ${WRKSRC}/Make.config
	@${ECHO_CMD} "HAVE_STRSIGNAL:=yes" >> ${WRKSRC}/Make.config
	@${ECHO_CMD} "HAVE_MOTIF:=yes" >> ${WRKSRC}/Make.config
	@${ECHO_CMD} "JPEG_VER:=80" >> ${WRKSRC}/Make.config

post-install:
	${INSTALL_DATA} ${WRKSRC}/desktop/ida.desktop ${STAGEDIR}${DESKTOPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
