# New ports collection makefile for:	xmmix
# Date created:		Mon Aug  5 10:54:25 CDT 1996
# Whom:			erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xmmix
PORTVERSION=	1.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Motif based audio mixer

USE_IMAKE=	yes
USE_MOTIF=	yes

MAN1=		xmmix.1

PLIST_FILES=	bin/xmmix lib/X11/app-defaults/XMmix lib/X11/xmmix.hlp

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/XMmix.ad

.include <bsd.port.mk>
