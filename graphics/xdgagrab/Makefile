# New ports collection makefile for:	xdgagrab
# Date created:		99/01/18
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xdgagrab
PORTVERSION=	0.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Capture an X server screen with a mouse pointer

ALL_TARGET=	xdgagrab
PLIST_FILES=	bin/xdgagrab
USE_X_PREFIX=	yes

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/xdgagrab ${PREFIX}/bin

.include <bsd.port.mk>
