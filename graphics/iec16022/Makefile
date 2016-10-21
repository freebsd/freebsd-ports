# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iec16022
PORTVERSION=	0.2.7
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Create 2D barcodes, also known as DataMatrix

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:devel/popt

USE_GITHUB=	yes
GH_ACCOUNT=	rdoeffinger

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		autoreconf gmake libtool pathfix pkgconfig

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -fPIC

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/iec16022.c \
		${WRKSRC}/iec16022ecc200.c ${WRKSRC}/reedsol.c ${WRKSRC}/image.c
	@${REINPLACE_CMD} -e '/-Wno-unused-result/d' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
