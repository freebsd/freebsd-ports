# New ports collection makefile for:   spacearyarya
# Date created:        16 June 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spacearyarya
PORTVERSION=	1.0.2
CATEGORIES=	games
MASTER_SITES=	http://kxl.hn.org/download/
DISTNAME=	SpaceAryarya-KXL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Space Harrier, the ancient video game like game

BUILD_DEPENDS=	${X11BASE}/include/KXL.h:${PORTSDIR}/games/kxl

NO_CDROM=	Possible copyright infringement

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
