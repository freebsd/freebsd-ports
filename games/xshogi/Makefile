# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

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

PLIST_FILES=	bin/xshogi man/man6/xshogi.6.gz

.include "${.CURDIR}/../../games/gnushogi/Makefile.common"
.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xshogi/xshogi \
		${STAGEDIR}${PREFIX}/bin/xshogi
	${INSTALL_MAN} ${WRKSRC}/doc/xshogi.6 \
		${STAGEDIR}${MANPREFIX}/man/man6/xshogi.6

.include <bsd.port.post.mk>
