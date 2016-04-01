# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	pngrewrite
PORTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://entropymine.com/jason/pngrewrite/ \
		http://mirror.roe.ch/dist/pngrewrite/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PNG palette optimizer

LICENSE=	ZLIB

LIB_DEPENDS=	libpng.so:graphics/png

USES=		localbase zip

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/pngrewrite

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -lm -lpng -lz -o ${WRKSRC}/pngrewrite ${WRKSRC}/libpngrewrite.c ${WRKSRC}/pngrewrite.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngrewrite ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
