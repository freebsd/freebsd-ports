# Ports collection makefile for:	metapixel
# Date created:			2002-05-23
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	metapixel
PORTVERSION=	0.9
CATEGORIES=	graphics
MASTER_SITES=	http://www.complang.tuwien.ac.at/~schani/metapixel/ \
		http://dragon.roe.ch/mirrors/distfiles/metapixel/

MAINTAINER=	daniel@roe.ch
COMMENT=	A photomosaic generator

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I." \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

post-patch:
	@${RM} ${WRKSRC}/getopt.h
	@${MV} ${WRKSRC}/sizesort ${WRKSRC}/metapixel-sizesort
	@${REINPLACE_CMD} -e 's/imagesize/metapixel-imagesize/' \
				  ${WRKSRC}/metapixel-sizesort

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/metapixel ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/metapixel-convert ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/metapixel-imagesize ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/metapixel-prepare ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/metapixel-sizesort ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/metapixel-zoom ${PREFIX}/bin

.include <bsd.port.mk>
