# New ports collection makefile for:	xboing
# Date created:		31 January 1995
# Whom:			janek
#
# $FreeBSD$

PORTNAME=	xboing
PORTVERSION=	2.4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	X11 arcade game

LICENSE=	MIT

USE_IMAKE=	yes
USE_XORG=	xpm xext x11
WRKSRC=		${WRKDIR}/xboing
MAN1=		xboing.1

.if defined(WITHOUT_AUDIO)
MAKE_ENV+=	WITHOUT_AUDIO=True
PLIST_SUB+=	WITH_SOUND="@comment "
.else
PLIST_SUB+=	WITH_SOUND=""
.endif

post-install:
	${CHOWN} root:games ${PREFIX}/bin/xboing
	${CHMOD} 2755 ${PREFIX}/bin/xboing
	${CHOWN} root:games ${PREFIX}/lib/X11/xboing/.xboing.scr
	${CHMOD} 664 ${PREFIX}/lib/X11/xboing/.xboing.scr

.include <bsd.port.mk>
