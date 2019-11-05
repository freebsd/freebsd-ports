# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xdgagrab
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Capture an X server screen with a mouse pointer

USES=		xorg
USE_XORG=	x11 xxf86dga
ALL_TARGET=	xdgagrab
PLIST_FILES=	bin/xdgagrab

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/xdgagrab ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
