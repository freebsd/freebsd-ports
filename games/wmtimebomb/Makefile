# New ports collection makefile for:	wmtimebomb
# Date created:		10 August 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wmtimebomb
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	games windowmaker
MASTER_SITES=	ftp://ftp.netmug.org/pub/FreeBSD/distfiles/
DISTNAME=	wmtimebomb.20

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A minesweeper for WindowMaker

LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		wraster.4:${PORTSDIR}/x11-wm/windowmaker

WRKSRC=		${WRKDIR}/wmtimebomb.app
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/wmtimebomb
	${INSTALL_DATA} ${WRKSRC}/example.modefile ${PREFIX}/lib/X11/wmtimebomb

.include <bsd.port.mk>
