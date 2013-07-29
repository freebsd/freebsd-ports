# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	pngrewrite
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://entropymine.com/jason/pngrewrite/ \
		http://mirror.roe.ch/dist/pngrewrite/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	PNG palette optimizer

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/pngrewrite

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-o ${WRKSRC}/pngrewrite ${WRKSRC}/pngrewrite.c ${WRKSRC}/libpngrewrite.c -lpng -lz -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngrewrite ${PREFIX}/bin

.include <bsd.port.mk>
