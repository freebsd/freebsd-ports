# New ports collection makefile for:   rexima
# Date created:        15 Jul 2002
# Whom:                Jerry Eriksson <jerry.e@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	rexima
PORTVERSION=	1.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/mixers

MAINTAINER=	jerry@rootbsd.net
COMMENT=	A ncurses-based console mixer

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

MAN1=	rexima.1

.include <bsd.port.post.mk>
