# Created by: Zsolt Udvari <udvzsolt@gmail.com>
# $FreeBSD$

PORTNAME=	zathura-pdf-mupdf
PORTVERSION=	0.2.7
CATEGORIES=	graphics
MASTER_SITES=	http://pwmt.org/projects/zathura-pdf-mupdf/download/

MAINTAINER=	udvzsolt@gmail.com
COMMENT=	MuPDF render PDF plugin for Zathura PDF viewer

LICENSE=	pwmt
LICENSE_NAME=	pwmt license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	zathura:${PORTSDIR}/graphics/zathura \
		mupdf>=1.5_1,1:${PORTSDIR}/graphics/mupdf
RUN_DEPENDS=	zathura:${PORTSDIR}/graphics/zathura

MAKE_ARGS=	MUPDF_LIB=-lmupdf_pic OPENSSL_INC=-I${OPENSSLINC} \
		OPENSSL_LIB="-L${OPENSSL_LIB} -lcrypto"

USES=		desktop-file-utils gmake pkgconfig
USE_GNOME=	glib20 gtk30
USE_OPENSSL=	yes

CONFLICTS_INSTALL=	zathura-pdf-poppler-[0-9]*

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/zathura/pdf.so

.include <bsd.port.mk>
