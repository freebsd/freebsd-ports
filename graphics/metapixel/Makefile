# Ports collection makefile for:	metapixel
# Date created:			2002-05-23
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	metapixel
PORTVERSION=	0.7
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.complang.tuwien.ac.at/~schani/metapixel/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	"Metapixel is a program for generating photomosaics"

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

post-patch:
	@${RM} ${WRKSRC}/getopt.h
	@${REINPLACE_CMD} -e 's,values.h,limits.h,'  ${WRKSRC}/libzoom/simple.h
	@${REINPLACE_CMD} -e 's,MINSHORT,SHRT_MIN,; \
 			    s,MAXSHORT,SHRT_MAX,' ${WRKSRC}/libzoom/zoom.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/metapixel ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/metapixel-prepare ${PREFIX}/bin

.include <bsd.port.mk>
