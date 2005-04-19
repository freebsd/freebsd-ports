# New ports collection makefile for:	xmix
# Date created:		30 June 1995
# Whom:			janek@gaja.ipan.lublin.pl
#
# $FreeBSD$
#

PORTNAME=	xmix
PORTVERSION=	2.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/mixers

PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCHFILES=	xmix-2.1.mixers.patch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mixer for X Window System

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/xmix

MAN1=		xmix.1
PLIST_FILES=	bin/xmix lib/X11/app-defaults/XMix

pre-build:
	${CP} ${WRKSRC}/xmix.1 ${WRKSRC}/xmix.man

post-install:
	${INSTALL_DATA} ${WRKSRC}/XMix ${PREFIX}/lib/X11/app-defaults

.include <bsd.port.mk>
