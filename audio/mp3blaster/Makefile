# New ports collection makefile for:	mp3blaster
# Version required:	2.0b17
# Date created:		5 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

DISTNAME=	mp3blaster-2.0b17
CATEGORIES=	audio
MASTER_SITES=	ftp://mud.stack.nl/pub/mp3blaster/ \
		http://mp3blaster.linuxave.net/src/

MAINTAINER=	ports@FreeBSD.org

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 400010
LIB_DEPENDS=	ncurses.4:${PORTSDIR}/devel/ncurses
.endif

GNU_CONFIGURE=	yes

MAN1=		mp3blaster.1 nmixer.1

.include <bsd.port.post.mk>
