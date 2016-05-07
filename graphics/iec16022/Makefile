# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iec16022
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://datenfreihafen.org/~stefan/iec16022/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Create 2D barcodes, also known as DataMatrix

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:devel/popt

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool pkgconfig

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -fPIC

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/iec16022.c \
		${WRKSRC}/iec16022ecc200.c ${WRKSRC}/reedsol.c ${WRKSRC}/image.c
	@${REINPLACE_CMD} -e \
		"s|^\(pkgconfigdir\).*|\1 = ${PREFIX}/libdata/pkgconfig|" \
			${WRKSRC}/Makefile.in

.include <bsd.port.mk>
