# New ports collection makefile for:   xdeblock
# Version required:    v1.0
# Date created:        28 December 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	xdeblo_v1.0
PKGNAME=	xdeblock-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://www.vector.co.jp/pack/unix/game/action/block/
DISTFILES=	xdeblock.tgz

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdeblo ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/X11/xdeblock/mapf
	${CHMOD} 777 ${PREFIX}/lib/X11/xdeblock/mapf
	${INSTALL_DATA} ${WRKSRC}/mapf/*.txt ${PREFIX}/lib/X11/xdeblock/mapf

.include <bsd.port.mk>
