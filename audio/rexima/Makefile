# New ports collection makefile for:   rexima
# Date created:        15 Jul 2002
# Whom:                Jerry Eriksson <jerry@freebsd.se>
#
# $FreeBSD$
#

PORTNAME=	rexima
PORTVERSION=	1.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/mixers

MAINTAINER=	jerry@freebsd.se
COMMENT=	A ncurses-based console mixer

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

MAN1=	rexima.1
PLIST_FILES=	bin/rexima

.include <bsd.port.post.mk>
