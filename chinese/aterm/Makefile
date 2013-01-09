# Created by: gugod@gugod.org
# $FreeBSD$

PORTNAME=	aterm
PORTVERSION=	1.0.1
CATEGORIES=	chinese x11
MASTER_SITES=	SF

MAINTAINER=	gugod@gugod.org
COMMENT=	A color vt102 terminal emulator with transparency support

USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-xim --enable-big5

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/aterm

MAN1=		aterm.1
PLIST_FILES=	bin/aterm

.include <bsd.port.mk>
