# New ports collection makefile for:	pngrewrite
# Date created:		10 February 2004
# Whom:			Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	pngrewrite
PORTVERSION=	1.4.0
CATEGORIES=	graphics
MASTER_SITES=	http://entropymine.com/jason/pngrewrite/ \
		http://mirror.roe.ch/dist/pngrewrite/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	A PNG palette optimizer

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/pngrewrite

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-o ${WRKSRC}/pngrewrite ${WRKSRC}/pngrewrite.c ${WRKSRC}/libpngrewrite.c -lpng -lz -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngrewrite ${PREFIX}/bin

.include <bsd.port.mk>
