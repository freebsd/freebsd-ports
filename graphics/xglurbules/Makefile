# New ports collection makefile for:   xglurbules
# Date created:        30 August 2002
# Whom:                Stephen Roome <steve@pepcross.com>
#
# $FreeBSD$
#

PORTNAME=	xglurbules
PORTVERSION=	1.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.pepcross.com/glurbules/

MAINTAINER=	steve@pepcross.com
COMMENT=	Burning particle system eye candy program thingy for X11

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile"
.endif

MAN1=		xglurbules.1

USE_XLIB=	yes
USE_X_PREFIX=	yes

MANCOMPRESSED=	yes

.include <bsd.port.post.mk>
