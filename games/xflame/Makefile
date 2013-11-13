# Created by: Kris Kennaway <kkennawa@physics.adelaide.edu.au>
# $FreeBSD$

PORTNAME=	xflame
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=kris

MAINTAINER=	ports@FreeBSD.org
COMMENT=	cool animated flame

DEPRECATED=	No more public distfiles

USES=		imake
USE_XORG=	x11 xext

NO_INSTALL_MANPAGES=	yes
PLIST_FILES=		bin/xflame

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xflame ${STAGEDIR}${PREFIX}/bin/xflame

.include <bsd.port.mk>
