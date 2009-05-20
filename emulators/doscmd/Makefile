# New ports collection makefile for:		doscmd
# Date created:					2004-03-23
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	doscmd
PORTVERSION=	20040330
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	des

MAINTAINER=	des@freebsd.org
COMMENT=	DOS emulator

ONLY_FOR_ARCHS=	i386
.ifdef WITHOUT_X11
MAKE_ARGS+=	-DNO_X
PLIST_SUB+=	X11="@comment "
.else
USE_XORG=	x11
PLIST_SUB+=	X11=""
.endif
MAKE_ARGS+=	MANDIR="${PREFIX}/man/man"
MAN1=		doscmd.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000	 
BROKEN=		does not build	 
.endif	 

.include <bsd.port.post.mk>
