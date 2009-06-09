# New ports collection makefile for:	xmmix
# Date created:		Mon Aug  5 10:54:25 CDT 1996
# Whom:			erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xmmix
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.ibiblio.org/tkan/download/xmmix/1.2.2/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Motif-based audio mixer

WRKSRC=		${WRKDIR}/xmmix-1.2

USE_IMAKE=	yes
USE_MOTIF=	yes
USE_XORG=	x11 xext sm ice xt xp

MAN1=		xmmix.1

PLIST_FILES=	bin/xmmix lib/X11/app-defaults/XMmix lib/X11/xmmix.hlp

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/XMmix.ad

.include <bsd.port.mk>
