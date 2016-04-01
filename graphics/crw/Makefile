# Created by: dillon
# $FreeBSD$

PORTNAME=	crw
PORTVERSION=	1.03
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://apollo.backplane.com/FreeBSDPorts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to process Canon camera RAW (.crw) files

LIB_DEPENDS=	libpng.so:graphics/png

USES=		uidfix

PLIST_FILES=	bin/crw man/man1/crw.1.gz

#CFLAGS+=	-I${LOCALBASE}/include/libpng15

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local/lib,${LOCALBASE}/lib,' \
		-e 's,CFLAGS=,CFLAGS+=,' \
		-e 's,/usr/local/include,${LOCALBASE}/include,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
