# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	xdeblock
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://ftp.vector.co.jp/pack/unix/game/action/block/
DISTFILES=	${PORTNAME}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Block action game

WRKSRC=		${WRKDIR}/xdeblo_v1.0

USES=		imake
USE_XORG=	xpm
NO_INSTALL_MANPAGES=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdeblo ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/X11/xdeblock/mapf
	${CHMOD} 777 ${PREFIX}/lib/X11/xdeblock/mapf
	${INSTALL_DATA} ${WRKSRC}/mapf/*.txt ${PREFIX}/lib/X11/xdeblock/mapf

.include <bsd.port.mk>
