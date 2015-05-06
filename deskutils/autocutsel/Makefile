# Created by: john@jnielsen.net
# $FreeBSD$

PORTNAME=	autocutsel
PORTVERSION=	0.10.0
CATEGORIES=	deskutils

MAINTAINER=	john@jnielsen.net
COMMENT=	Synchronizes the two copy/paste buffers used by X applications

USE_GITHUB=	yes
GH_ACCOUNT=	sigmike

USE_XORG=	x11 xaw xmu
GNU_CONFIGURE=	yes
USES=		gmake autoreconf libtool

PLIST_FILES=	bin/autocutsel \
		bin/cutsel

post-configure:
	@${REINPLACE_CMD} -e 's|-I\.|-I/usr/local/include|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
