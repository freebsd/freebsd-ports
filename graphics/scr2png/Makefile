# New ports collection makefile for:	scr2png
# Date created:				18 May 2001
# Whom:					nik
#
# $FreeBSD$
#

PORTNAME=	scr2png
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	graphics

MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= nik
NO_WRKSUBDIR=	yes

MAINTAINER=	nik@freebsd.org
COMMENT=	Converts the output of "vidcontrol -p" to PNG

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

USE_REINPLACE=	yes

MAN1=		scr2png.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/scr2png

post-extract:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|<gd/gd\.h>|<gd.h>|' ${WRKSRC}/scr2png.c

do-install:	
	@cd ${WRKSRC}; ${MAKE} BINDIR=${PREFIX}/bin SHAREDIR=${PREFIX} install

.include <bsd.port.mk>
