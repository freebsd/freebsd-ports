# New ports collection makefile for:	autocutsel
# Date created:		13 November 2003
# Whom:			john@jnielsen.net
#
# $FreeBSD$
#

PORTNAME=	autocutsel
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	autocutsel

MAINTAINER=	john@jnielsen.net
COMMENT=	Synchronizes the two copy/paste buffers used by X applications

USE_XORG=	x11 xaw xext
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/autocutsel \
		bin/cutsel

.include <bsd.port.mk>
