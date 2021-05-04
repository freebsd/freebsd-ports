# Created by: mi@aldan.ziplink.net

PORTNAME=	xmdiary
PORTVERSION=	3.0.3
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	XCONTRIB/office

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Personal and group calendar utility

# Converted from NO_CDROM
LICENSE=	xmdiary
LICENSE_NAME=	xmdiary
LICENSE_TEXT=	Do not sell for profit
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		imake motif xorg
USE_XORG=	x11 xext xpm xt

post-patch:
	@${REINPLACE_CMD} -e 's/malloc\.h/stdlib.h/' \
		${WRKSRC}/tools/LstLinked.c ${WRKSRC}/tools/System.c \
		${WRKSRC}/xtools/xitClipboard.c ${WRKSRC}/xtools/xitInfoFile.c
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		-e 's|CcCmd gcc|CcCmd ${CC}|' '${WRKSRC}/XDiary.tmpl'

.include <bsd.port.mk>
