# New ports collection makefile for:    splay
# Version required:     0.8.2
# Date created:         1 Apr 1997
# Whom:                 junker@jazz.snu.ac.kr
#
# $Id: Makefile,v 1.5 1998/01/08 18:52:01 fenner Exp $
#
# pthread library can be used, but sound quality is buggy
#

DISTNAME=		splay-0.8.2
CATEGORIES=		audio
MASTER_SITES=		http://cain.kaist.ac.kr/~jwj95/

MAINTAINER=		junker@jazz.snu.ac.kr

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		i386--freebsd --without-xsplay --without-pthread
MAN1=			splay.1

.include <bsd.port.mk>
