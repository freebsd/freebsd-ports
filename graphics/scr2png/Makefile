# Created by: nik
# $FreeBSD$

PORTNAME=	scr2png
PORTVERSION=	1.2
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nik

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Converts the output of "vidcontrol -p" to PNG

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd

NO_WRKSUBDIR=	yes

MAN1=		scr2png.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/scr2png

post-extract:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|<gd/gd\.h>|<gd.h>|' ${WRKSRC}/scr2png.c

do-install:
	@cd ${WRKSRC}; ${MAKE} BINDIR=${PREFIX}/bin SHAREDIR=${PREFIX} install

.include <bsd.port.mk>
