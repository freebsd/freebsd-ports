# Created by: Ultima <ultima1252@gmail.com>
# $FreeBSD$

PORTNAME=	puush
PORTVERSION=	0.0.1
CATEGORIES=	deskutils

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Screen capture and Puush image-bin client

RUN_DEPENDS=	gnome-screenshot:deskutils/gnome-screenshot \
		curl:ftp/curl \
		zenity:x11/zenity \
		xclip:x11/xclip

USE_GITHUB=	yes
GH_ACCOUNT=	ultima1252
NO_BUILD=	yes

PLIST_FILES=	sbin/puush \
		share/icons/puush.png

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/puush ${STAGEDIR}${PREFIX}/sbin/puush
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${CP} -R ${WRKSRC}/icon.png ${STAGEDIR}${PREFIX}/share/icons/puush.png

.include <bsd.port.mk>
