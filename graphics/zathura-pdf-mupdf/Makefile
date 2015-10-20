# Created by: Zsolt Udvari <udvzsolt@gmail.com>
# $FreeBSD$

PORTNAME=	zathura-pdf-mupdf
PORTVERSION=	0.2.7
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://pwmt.org/projects/zathura-pdf-mupdf/download/

MAINTAINER=	udvzsolt@gmail.com
COMMENT=	MuPDF render PDF plugin for Zathura PDF viewer

LICENSE=	zlib
LICENSE_NAME=	zlib license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	zathura:${PORTSDIR}/graphics/zathura \
		mupdf>=1.7,1:${PORTSDIR}/graphics/mupdf
RUN_DEPENDS=	zathura:${PORTSDIR}/graphics/zathura
LIB_DEPENDS=	libjbig2dec.so:${PORTSDIR}/graphics/jbig2dec \
		libopenjp2.so:${PORTSDIR}/graphics/openjpeg

PLIST_FILES=	lib/zathura/pdf.so share/applications/zathura-pdf-mupdf.desktop

MAKE_ARGS=	MUPDF_LIB=-lmupdf_pic OPENSSL_INC=-I${OPENSSLINC} \
		OPENSSL_LIB="-L${OPENSSLLIB} -lcrypto"
USES=		desktop-file-utils gmake pkgconfig
USE_GNOME=	glib20 gtk30
USE_OPENSSL=	yes

CONFLICTS_INSTALL=	zathura-pdf-poppler-[0-9]*

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/zathura/pdf.so

.include <bsd.port.mk>
