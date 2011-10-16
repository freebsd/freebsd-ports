# New ports collection makefile for:   xshogi
# Date created:        20 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xshogi
PORTVERSION=	${GNUSHOGI_PORTVERSION}
CATEGORIES=	games
MASTER_SITES=	${GNUSHOGI_MASTER_SITES}
MASTER_SITE_SUBDIR=	${GNUSHOGI_MASTER_SITE_SUBDIR}
DISTNAME=	${GNUSHOGI_DISTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The Japanese chess-like game for X Window System

RUN_DEPENDS=	gnushogi:${PORTSDIR}/games/gnushogi

BUILD_WRKSRC=	${WRKSRC}/xshogi

USE_XORG=	xt xaw x11
GNU_CONFIGURE=	yes
USE_CSTD=	gnu99

MAN6=		xshogi.6
PLIST_FILES=	bin/xshogi

.include "${.CURDIR}/../../games/gnushogi/Makefile.common"
.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xshogi/xshogi ${PREFIX}/bin/xshogi
	${INSTALL_MAN} ${WRKSRC}/doc/xshogi.6 ${MANPREFIX}/man/man6/xshogi.6

.include <bsd.port.post.mk>
