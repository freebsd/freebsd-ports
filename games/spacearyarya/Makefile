# New ports collection makefile for:   spacearyarya
# Date created:        16 June 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spacearyarya
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.dvo.ru/pub/Gentoo/distfiles/ \
		ftp://ftp.uni-erlangen.de/.mirrors/ftpbsd/ftp.freebsd.org/pub/FreeBSD/ports/distfiles/ \
		ftp://ftp.bsdfr.org/pub/FreeBSD/ports/distfiles/ \
		ftp://ftp.jpix.ad.jp/pub/FreeBSD/ports/distfiles/
DISTNAME=	SpaceAryarya-KXL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Space Harrier, the ancient video game like game

BUILD_DEPENDS=	${X11BASE}/include/KXL.h:${PORTSDIR}/devel/kxl
RUN_DEPENDS=	${X11BASE}/lib/libKXL-1.1.7.so:${PORTSDIR}/devel/kxl

NO_CDROM=	Possible copyright infringement

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
