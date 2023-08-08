PORTNAME=	jbig2dec
PORTVERSION=	0.19
CATEGORIES=	graphics devel
MASTER_SITES=	https://github.com/ArtifexSoftware/ghostpdl-downloads/releases/download/gs9533/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Decoder implementation of the JBIG2 image compression format
WWW=		https://github.com/ArtifexSoftware/jbig2dec

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool pathfix

CONFIGURE_ENV=	ac_cv_func_getopt_long=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-lmd
USE_LDCONFIG=	yes

CPE_VENDOR=	artifex

OPTIONS_DEFINE=	PNG
OPTIONS_DEFAULT=PNG

PNG_CONFIGURE_WITH=	libpng=${LOCALBASE}
PNG_LIB_DEPENDS=	libpng.so:graphics/png

post-patch:
	@${RM} ${WRKSRC}/getopt* ${WRKSRC}/sha1.h

.include <bsd.port.mk>
