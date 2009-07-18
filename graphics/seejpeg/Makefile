# New ports collection makefile for: seejpeg-1.10.tgz
# Date created:		2000 Oct 19
#
# Whom:			Donn Miller <dmmiller@cvzoom.net>
# $FreeBSD$
#

PORTNAME=	seejpeg
PORTVERSION=	1.10
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/viewers/svga
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A console graphics viewer using the svga console graphics library

LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib \
		jpeg.10:${PORTSDIR}/graphics/jpeg

ALL_TARGET=	seejpeg

MAN1=		seejpeg.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/seejpeg
USE_GMAKE=	yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

post-extract:
	${CHMOD} 0644 ${WRKSRC}/Makefile

post-patch:
	${MV}	${WRKSRC}/Makefile ${WRKSRC}/Makefile.prev
	${SED}	"s|-O3|${CFLAGS}|g" ${WRKSRC}/Makefile.prev >  ${WRKSRC}/Makefile

.include <bsd.port.mk>
