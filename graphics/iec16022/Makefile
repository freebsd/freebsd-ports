# New ports collection makefile for:    iec16022
# Date created:                         Thu Jul  3 14:13:08 CEST 2008
# Whom:                                 Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iec16022
PORTVERSION=	0.2.2
CATEGORIES=	graphics
MASTER_SITES=	http://datenfreihafen.org/~stefan/iec16022/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Create 2D barcodes, also known as DataMatrix

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

PLIST_FILES=	bin/iec16022

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/iec16022.c \
		${WRKSRC}/iec16022ecc200.c ${WRKSRC}/reedsol.c ${WRKSRC}/image.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
