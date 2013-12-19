# Created by: mi@aldan.ziplink.net
# $FreeBSD$

PORTNAME=	xmdiary
PORTVERSION=	3.0.3
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	office
DISTFILES=	${DISTNAME}.tar.gz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Personal and group calendar utility

NO_CDROM=	Do not sell for profit
EXTRACT_ONLY=	${DISTNAME}.tar.gz
USES=		imake motif
USE_XORG=	x11 xext xp xpm xt
MAN1=		xdaclunix.1 xdalarm.1 xdcustom.1 xddump.1 xdiary.1 xdinitdb.1 \
		xdlight.1 xdnotify.1 xdprformat.1 xdremind.1 xdremove.1 \
		xdrestore.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's/malloc\.h/stdlib.h/' \
		${WRKSRC}/tools/LstLinked.c ${WRKSRC}/tools/System.c \
		${WRKSRC}/xtools/xitClipboard.c ${WRKSRC}/xtools/xitInfoFile.c
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		-e 's|CcCmd gcc|CcCmd ${CC}|' '${WRKSRC}/XDiary.tmpl'

.include <bsd.port.mk>
