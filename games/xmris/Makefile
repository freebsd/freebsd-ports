# Created by: jmz
# $FreeBSD$

PORTNAME=	xmris
PORTVERSION=	4.04
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Version of the Mr Do video arcade game for X11

USES=		imake tar:tgz
USE_XORG=	x11 xext xaw xmu xt sm ice
ALL_TARGET=	xmris xmred Xmris.ad

DESKTOP_ENTRIES="XMRis" "" "" "${PORTNAME}" "" ""

post-build:
	@${LN} -sf Xmris.ad ${WRKSRC}/Xmris

do-install:
.for i in xmred xmris
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${i} \
		${STAGEDIR}${PREFIX}/bin)
.endfor
	${LN} -sf xmris ${STAGEDIR}${PREFIX}/bin/xmsit
.for i in xmred xmris
	(cd ${WRKSRC} && ${INSTALL_MAN} ${i}.man \
		${STAGEDIR}${MANPREFIX}/man/man6/${i}.6)
.endfor
	${LN} -sf xmris.6 ${STAGEDIR}${MANPREFIX}/man/man6/xmsit.6
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/app-defaults
	(cd ${WRKSRC} && ${INSTALL_DATA} Xmris \
		${STAGEDIR}${PREFIX}/lib/X11/app-defaults)
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/xmris
	(cd ${WRKSRC} && ${INSTALL_DATA} *.gdn \
		${STAGEDIR}${PREFIX}/lib/X11/xmris)
	${MKDIR} ${STAGEDIR}/var/games/xmris

.include <bsd.port.mk>
