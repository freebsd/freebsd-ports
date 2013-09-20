# Created by: Matthew Hunt <mph@pobox.com>
# $FreeBSD$

PORTNAME=	xfrisk
PORTVERSION=	1.2
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://old.tuxick.net/xfrisk/files/ \
		http://devel.ringlet.net/games/xfrisk/
DISTNAME=	XFrisk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi-player networked Risk game for X11

LIB_DEPENDS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d

NO_CDROM=	Possible trademark infringement

WRKSRC=		${WRKDIR}/XFrisk

USE_XORG=	x11 xt xaw xmu sm ice
USE_GMAKE=	yes
MAKE_ENV=	XDIR="${LOCALBASE}"

NO_STAGE=	yes
do-install:
.for file in aiColson aiConway aiDummy friskserver xfrisk
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in risk
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
.for file in Countries.risk Help.risk World.risk
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/${PORTNAME}
.endfor

.include <bsd.port.mk>
