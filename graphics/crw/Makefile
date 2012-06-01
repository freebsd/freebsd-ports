# New ports collection makefile for:    crw
# Date created:         16 June 2002
# Whom:                 dillon
#
# $FreeBSD$
#

PORTNAME=	crw
PORTVERSION=	1.03
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://apollo.backplane.com/FreeBSDPorts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility to process Canon camera RAW (.crw) files

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

MAN1=		crw.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/crw

#CFLAGS+=	-I${LOCALBASE}/include/libpng15

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local/lib,${LOCALBASE}/lib,' \
		-e 's,CFLAGS=,CFLAGS+=,' \
		-e 's,/usr/local/include,${LOCALBASE}/include,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
