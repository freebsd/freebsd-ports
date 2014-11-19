# Created by: "Waitman Gobble" <uzimac@da3m0n8t3r.com>
# $FreeBSD$

PORTNAME=	dcraw-m
PORTVERSION=	9.17
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://dx.burplex.com/dcraw-m/ \
		http://www.waitman.net/dcraw-m/

MAINTAINER=	waitman@waitman.net
COMMENT=	Modified Decoder for RAW files from digital cameras

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-11-26

LIB_DEPENDS=	libjasper.so:${PORTSDIR}/graphics/jasper \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		liblcms.so:${PORTSDIR}/graphics/lcms \
		libMagickWand-6.Q16.so:${PORTSDIR}/graphics/ImageMagick

PLIST_FILES=	bin/dcraw-m

OPTIONS_DEFINE=	OPTIMIZE_O3 OPTIMIZE_O4
OPTIMIZE_O3_DESC=	Use O3 with clang (O4 not working)
OPTIMIZE_O4_DESC=	Use O4 with gcc

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZE_O3}
CFLAGS+=	-O3
.else
.if ${PORT_OPTIONS:MOPTIMIZE_O4}
CFLAGS+=	-O4
.endif
.endif

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/ImageMagick-6
LDFLAGS+=	-L${LOCALBASE}/lib -lm -ljasper -ljpeg -llcms -lMagickWand-6.Q16

do-build:
	cd ${WRKSRC}/ && ${CC} -o ${PORTNAME} ${CFLAGS} ${PORTNAME}.c ${LDFLAGS}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
