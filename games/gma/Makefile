# New ports collection makefile for:   gma
# Date created:         22 June 1999
# Whom:                 Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	gma
PORTVERSION=	0.6
CATEGORIES=	games
MASTER_SITES=	http://www.student.nada.kth.se/~d92-jwa/code/gma/

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Go-moku game which learns playing the game from studying its opponent

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

USE_GCC=	2.95
GNU_CONFIGURE=	yes

.include <bsd.port.post.mk>
