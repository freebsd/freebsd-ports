# Created by: Zsolt Udvari <udvzsolt@gmail.com>
# $FreeBSD$

PORTNAME=	zathura-pdf-mupdf
PORTVERSION=	0.3.0
CATEGORIES=	graphics
MASTER_SITES=	http://pwmt.org/projects/zathura-pdf-mupdf/download/

MAINTAINER=	udvzsolt@gmail.com
COMMENT=	MuPDF render PDF plugin for Zathura PDF viewer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zathura:graphics/zathura \
		mupdf>=1.8,1:graphics/mupdf
RUN_DEPENDS=	zathura:graphics/zathura
LIB_DEPENDS=	libjbig2dec.so:graphics/jbig2dec \
		libopenjp2.so:graphics/openjpeg

PLIST_FILES=	lib/zathura/pdf.so share/applications/zathura-pdf-mupdf.desktop

MAKE_ARGS=	MUPDF_LIB=-lmupdf_pic OPENSSL_INC=-I${OPENSSLINC} \
		OPENSSL_LIB="-L${OPENSSLLIB} -lcrypto"
USES=		compiler:c11 desktop-file-utils gmake pkgconfig
USE_GNOME=	glib20 gtk30
USE_OPENSSL=	yes

CONFLICTS_INSTALL=	zathura-pdf-poppler-[0-9]*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/zathura/pdf.so

.include <bsd.port.mk>
