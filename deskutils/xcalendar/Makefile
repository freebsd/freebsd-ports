# Created by: MITA Yoshio <mita@iis.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	xcalendar
PORTVERSION=	4.0.2008
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	PORTS_JP
DISTNAME=	${PORTNAME}-4.0+i18n

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Calendar with a notebook for X11 (internationalized version)

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		imake gmake xorg
USE_XORG=	ice sm x11 xaw xext xmu xt
MAKE_ENV=	FILESDIR=${FILESDIR}
ALL_TARGET=	all XCal-uj.ad xcalendar-uj.hlp xcalendar-uj.man

.include <bsd.port.mk>
