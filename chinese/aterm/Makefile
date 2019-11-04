# Created by: gugod@gugod.org
# $FreeBSD$

PORTNAME=	aterm
PORTVERSION=	1.0.1
CATEGORIES=	chinese x11
MASTER_SITES=	SF

MAINTAINER=	gugod@gugod.org
COMMENT=	Color vt102 terminal emulator with transparency support

USES=		xorg
USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-xim --enable-big5
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	"@(,,4711) bin/aterm" \
		man/man1/aterm.1.gz

.include <bsd.port.mk>
