# New ports collection makefile for:		doscmd
# Date created:					2004-03-23
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	doscmd
PORTVERSION=	20040324
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
USE_XLIB=	yes
PLIST_SUB+=	X11=""
.endif

.include <bsd.port.mk>
