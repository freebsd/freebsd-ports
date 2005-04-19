# New ports collection makefile for:    workman
# Date created:         25 Now 1995
# Whom:                 Donald Burr <d_burr@ix.netcom.com>
#
# $FreeBSD$
#

PORTNAME=	workman
PORTVERSION=	1.3a
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/WorkMan
DISTNAME=	WorkMan-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Look-based CD player tool

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

WRKSRC=		${WRKDIR}/workman
USE_IMAKE=	yes
MAN1=		workman.1
MAN5=		workmandb.5
PLIST_FILES=	bin/workman lib/help/workman.info

.include <bsd.port.pre.mk>

post-install:
	${GZIP_CMD} ${X11BASE}/man/man5/workmandb.5

.include <bsd.port.post.mk>
