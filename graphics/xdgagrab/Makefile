# New ports collection makefile for:	xdgagrab
# Version required:	0.3
# Date created:		99/01/18
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	xdgagrab-0.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/ports/

MAINTAINER=	taoka@FreeBSD.org

ALL_TARGET=	xdgagrab
USE_X_PREFIX=	yes

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/xdgagrab ${PREFIX}/bin

.include <bsd.port.mk>
