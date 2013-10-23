# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iec16022
PORTVERSION=	0.2.4
CATEGORIES=	graphics
MASTER_SITES=	http://datenfreihafen.org/~stefan/iec16022/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Create 2D barcodes, also known as DataMatrix

LICENSE=	GPLv2

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		pkgconfig

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

MAN1=		iec16022.1

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/iec16022.c \
		${WRKSRC}/iec16022ecc200.c ${WRKSRC}/reedsol.c ${WRKSRC}/image.c
	@${REINPLACE_CMD} -e \
		"s|^\(pkgconfigdir\).*|\1 = ${PREFIX}/libdata/pkgconfig|" \
			${WRKSRC}/Makefile.in

.include <bsd.port.mk>
