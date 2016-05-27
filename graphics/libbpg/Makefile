# Created by: Matthieu Volat <mazhe@alkumuna.eu>
# $FreeBSD$

PORTNAME=	libbpg
PORTVERSION=	0.9.7
CATEGORIES=	graphics
MASTER_SITES=	http://bellard.org/bpg/

MAINTAINER=	mazhe@alkumuna.eu
COMMENT=	BPG (Better Portable Graphics) is a new image format

LICENSE=	BSD2CLAUSE LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libpng.so:graphics/png

OPTIONS_DEFINE=	SDL JCTVC X265
OPTIONS_DEFAULT=SDL X265
OPTIONS_SUB=	yes

USE_LDCONFIG=	yes
SDL_USE=	SDL=image
X265_LIB_DEPENDS=	libx265.so:multimedia/x265
X265_VARS=	x265_libs=${PREFIX}/lib/libx265.so

JCTVC_DESC=	Enable JCTVC (best quality but slow) for the encoder
JCTVCHI_DESC=	Use bit depths > 12 with JCTVC (experimental)
USES=		compiler:c++11-lib gmake jpeg
CFLAGS+=	-fPIC -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS+=	X265_LIBS=${X265_LIBS}

do-configure-JCTVC-off:
	${REINPLACE_CMD} -e 's/^USE_JCTVC=y$$/#USE_JCTVC=/' ${WRKSRC}/Makefile

do-configure-SDL-off:
	${REINPLACE_CMD} -e 's/^USE_BPGVIEW=y$$/#USE_BPGVIEW=/' ${WRKSRC}/Makefile

do-configure-X265-off:
	${REINPLACE_CMD} -e 's/^USE_X265=y$$/#USE_X265=/' ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/libbpg.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libbpg.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libbpg.so ${STAGEDIR}${PREFIX}/lib

post-install-SDL-on:
	${INSTALL_PROGRAM} ${WRKSRC}/bpgview ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
