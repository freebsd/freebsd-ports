PORTNAME=	jbig2dec
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	https://github.com/ArtifexSoftware/jbig2dec/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Decoder implementation of the JBIG2 image compression format
WWW=		https://github.com/ArtifexSoftware/jbig2dec

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool pathfix python:env,test shebangfix

CONFIGURE_ENV=	ac_cv_func_getopt_long=yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip
LDFLAGS+=	-lmd
TEST_TARGET=	check
USE_LDCONFIG=	yes

CPE_VENDOR=	artifex

SHEBANG_FILES=	*.py

OPTIONS_DEFINE=	PNG
OPTIONS_DEFAULT=PNG

PNG_CONFIGURE_WITH=	libpng=${LOCALBASE}
PNG_LIB_DEPENDS=	libpng.so:graphics/png

post-patch:
	@${RM} ${WRKSRC}/getopt* ${WRKSRC}/sha1.h

.include <bsd.port.mk>
