# New ports collection makefile for:	asmixer
# Date created:		2 January 2003
# Whom:			mtm@identd.net
#
# $FreeBSD$
#

PORTNAME=	asmixer
PORTVERSION=	0.5
CATEGORIES=	audio afterstep
MASTER_SITES=	${MASTER_SITE_AFTERSTEP} \
		http://www.tigr.net/afterstep/download/asmixer/
MASTER_SITE_SUBDIR=	apps/asmixer

MAINTAINER=	mtm@identd.net
COMMENT=	A mixer control for X, and specifically the AfterStep Window Manager

MAN1=		${PORTNAME}.1x
PLIST_FILES=	bin/asmixer

USE_X_PREFIX=	yes
USE_XPM=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man \
	    ${MAN1PREFIX}/man/man1/${PORTNAME}.1x

.include <bsd.port.mk>
