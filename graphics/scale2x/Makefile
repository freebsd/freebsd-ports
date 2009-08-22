# Ports collection makefile for:	scale2x
# Date created:			2006/12/01
# Whom:				chinsan
#
# $FreeBSD$
#

PORTNAME=	scale2x
PORTVERSION=	2.2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Real-time graphics effect able to increase the size of small bitmaps

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/scalex bin/scalerx
MAN1=		scalex.1 scalerx.1

post-patch:
	@${REINPLACE_CMD} -e 's,png.h,libpng/png.h,' ${WRKSRC}/file.h

.include <bsd.port.mk>
