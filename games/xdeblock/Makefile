# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	xdeblock
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://ftp.vector.co.jp/03/94/1328/
DISTFILES=	${PORTNAME}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Block action game

WRKSRC=		${WRKDIR}/xdeblo_v1.0

USES=		imake:noman xorg
USE_XORG=	xpm

CFLAGS+=	-Wno-return-type

DESKTOP_ENTRIES="XDeBlock" "" "" "xdeblo" "" ""

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/main.c

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} xdeblo ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/xdeblock/mapf
	(cd ${WRKSRC}/mapf && ${INSTALL_DATA} *.txt \
		${STAGEDIR}${PREFIX}/lib/X11/xdeblock/mapf)

.include <bsd.port.mk>
