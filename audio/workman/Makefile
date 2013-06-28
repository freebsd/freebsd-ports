# Created by: Donald Burr <d_burr@ix.netcom.com>
# $FreeBSD$

PORTNAME=	workman
PORTVERSION=	1.3a
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/WorkMan
DISTNAME=	WorkMan-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Look-based CD player tool

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

WRKSRC=		${WRKDIR}/workman
USES=		imake
USE_XORG=	x11 xext
MAN1=		workman.1
MAN5=		workmandb.5
PLIST_FILES=	bin/workman lib/help/workman.info

post-install:
	${GZIP_CMD} ${PREFIX}/man/man5/workmandb.5

.include <bsd.port.mk>
