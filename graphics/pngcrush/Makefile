# Created by: Chris D. Faulhaber <jedgar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pngcrush
PORTVERSION=	1.7.80
CATEGORIES=	graphics
MASTER_SITES=	SF/pmt/${PORTNAME}/${PORTVERSION}/ \
		SF/pmt/${PORTNAME}/old-versions/1.7/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-nolib

MAINTAINER=	vsasjason@gmail.com
COMMENT=	Optimizer for PNG files

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USES=		tar:xz
CFLAGS+=	-DPNGCRUSH_COUNT_COLORS -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/pngcrush

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/pngcrush

.include <bsd.port.mk>
