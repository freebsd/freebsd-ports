# New ports collection makefile for:	asmix
# Date created:		1 January 2003
# Whom:			mtm@identd.net
#
# $FreeBSD$
#

PORTNAME=	asmix
PORTVERSION=	1.4
CATEGORIES=	audio afterstep
MASTER_SITES=	${MASTER_SITE_AFTERSTEP} \
		http://www.tigr.net/afterstep/download/asmix/
MASTER_SITE_SUBDIR=	apps/asmix

MAINTAINER=	mtm@identd.net
COMMENT=	Volume control dock-app for the AfterStep Window Manager

MAN1=		${PORTNAME}.1x
PLIST_FILES=	bin/asmix

USE_X_PREFIX=	yes
USE_XPM=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include <bsd.port.mk>
