# New ports collection makefile for:   grande
# Date created:        20 Feb 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grande
PORTVERSION=	0.5
CATEGORIES=	games
MASTER_SITES=	http://www2.mwnet.or.jp/~fc3srx7/download/
DISTNAME=	${PORTNAME}-KXL-${PORTVERSION}

MAINTAINER=	nakai@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/include/KXL.h:${PORTSDIR}/games/kxl

NO_CDROM=	Possible copyright infringement

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=	253

pre-install:
	${MKDIR} ${PREFIX}/share/${PORTNAME}/score

.include <bsd.port.mk>
