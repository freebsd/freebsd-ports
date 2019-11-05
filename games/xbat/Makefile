# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	xbat
PORTVERSION=	1.11
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	LOCAL/hrs
DISTNAME=	xev111

MAINTAINER=	TsurutaniNaoki@gmail.com
COMMENT=	XEVIOUS like shooting game

LICENSE=	GPLv2

NO_CDROM=	Possible copyright infringement

USES=		imake xorg
USE_XORG=	x11 xext
WRKSRC=		${WRKDIR}/Xev111
ALL_TARGET=	xbat
USE_GCC=	yes # segfaults when compiled with clang

.include <bsd.port.mk>
