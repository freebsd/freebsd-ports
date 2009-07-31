# New ports collection makefile for:	Xtuner
# Date created:		19 December 96
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	xtuner
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/
DISTNAME=	Xtuner-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xwindows interface for the RadioREVEAL and RadioTrack FM radio cards!

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

PLIST_FILES=	bin/xtuner
USE_IMAKE=	YES
USE_XORG=	xpm

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "ia64"
BROKEN=		Does not compile on sparc64 or ia64
.endif

.include <bsd.port.post.mk>
