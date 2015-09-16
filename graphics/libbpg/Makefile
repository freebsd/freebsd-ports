# Created by: Matthieu Volat <mazhe@alkumuna.eu>
# $FreeBSD$

PORTNAME=	libbpg
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://bellard.org/bpg/

MAINTAINER=	mazhe@alkumuna.eu
COMMENT=	BPG (Better Portable Graphics) is a new image format

LICENSE=	BSD2CLAUSE LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	SDL JCTVC X265
OPTIONS_DEFAULT=SDL JCTVC
OPTIONS_SUB=	yes

USE_LDCONFIG=	yes
SDL_USE=	SDL=image
X265_LIB_DEPENDS=	libx265.so:${PORTSDIR}/multimedia/x265

JCTVC_DESC=	Enable JCTVC (best quality but slow) for the encoder
JCTVCHI_DESC=	Use bit depths > 12 with JCTVC (experimental)
USES=		compiler:c++11-lib gmake jpeg
CFLAGS+=	-fPIC -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

do-configure:
.if ! ${PORT_OPTIONS:MSDL}
	${REINPLACE_CMD} -e 's/^USE_BPGVIEW=y$$/#USE_BPGVIEW=/' ${WRKSRC}/Makefile
.endif
.if ! ${PORT_OPTIONS:MJCTVC}
	${REINPLACE_CMD} -e 's/^USE_JCTVC=y$$/#USE_JCTVC=/' ${WRKSRC}/Makefile
.endif
.if ${PORT_OPTIONS:MX265}
	${REINPLACE_CMD} -e 's/^#USE_JCTVC_HIGH_BIT_DEPTH=y$$/USE_JCTVC_HIGH_BIT_DEPTH=y/' ${WRKSRC}/Makefile
.endif
.if ${PORT_OPTIONS:MX265}
	${REINPLACE_CMD} -e 's/^#USE_X265=y$$/USE_X265=y/' ${WRKSRC}/Makefile
.endif

post-install:
.if ${PORT_OPTIONS:MSDL}
	${INSTALL_PROGRAM} ${WRKSRC}/bpgview ${STAGEDIR}${PREFIX}/bin
.endif
	${INSTALL_DATA} ${WRKSRC}/libbpg.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libbpg.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libbpg.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
