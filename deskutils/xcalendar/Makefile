# New ports collection makefile for:	xcalendar-4.0
# Date created:		25 June 1996
# Whom:			MITA Yoshio <mita@iis.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xcalendar
PORTVERSION=	4.0.2002
CATEGORIES=	deskutils
MASTER_SITES=	ftp://daemon.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/
DISTNAME=	${PORTNAME}-${PORTVERSION}+i18n

MAINTAINER=	mistral@imasy.or.jp

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_IMAKE=	yes
USE_GMAKE=	yes
MAKE_ENV=	FILESDIR=${FILESDIR}
ALL_TARGET=	all XCal-uj.ad xcalendar-uj.hlp xcalendar-uj.man
MAN1=		xcalendar.1
MANLANG=	"" ja

.include <bsd.port.mk>
