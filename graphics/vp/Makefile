PORTNAME=	vp
PORTVERSION=	1.8
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://elfga.com/~erik/files/

MAINTAINER=	erik@elfga.com
COMMENT=	Image viewer for X
WWW=		https://bzflag.bz/~erik

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
LIBS+=		-lm
USES=		sdl tar:xz
USE_SDL=	image

PLIST_FILES=	bin/vp share/man/man1/vp.1.gz

.include <bsd.port.mk>
