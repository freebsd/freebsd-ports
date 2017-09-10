# Created by: Zsolt Udvari <udvzsolt@gmail.com>
# $FreeBSD$

PORTNAME=	zathura-pdf-mupdf
PORTVERSION=	0.3.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura-pdf-mupdf/download/ \
		http://www.madpilot.net/~mad/pwmt.org/

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	MuPDF render PDF plugin for Zathura PDF viewer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zathura:graphics/zathura
RUN_DEPENDS=	zathura:graphics/zathura
LIB_DEPENDS=	libjbig2dec.so:graphics/jbig2dec \
		libfreetype.so:print/freetype2 \
		libgirara-gtk3.so:x11-toolkits/girara \
		libharfbuzz.so:print/harfbuzz \
		libmupdf.so:graphics/mupdf \
		libopenjp2.so:graphics/openjpeg

PLIST_FILES=	lib/zathura/pdf.so share/applications/zathura-pdf-mupdf.desktop

MAKE_ARGS=	OPENSSL_INC=-I${OPENSSLINC} OPENSSL_LIB="-L${OPENSSLLIB} -lcrypto"
USES=		compiler:c11 desktop-file-utils gmake gettext jpeg pkgconfig ssl
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30

CONFLICTS_INSTALL=	zathura-pdf-poppler-[0-9]*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/zathura/pdf.so

.include <bsd.port.mk>
