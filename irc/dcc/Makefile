# New ports collection makefile for:	dcc
# Date Created:		6 May 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dcc
PORTVERSION=	2.5.3
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.fan.gr.jp/pub/elisp/irchat-pj/2.5/
DISTNAME=	irchat-pj-${PORTVERSION}p

MAINTAINER=	yoichi@eken.phys.nagoya-u.ac.jp

ALL_TARGET=	dcc
LDFLAGS=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS} -DUSE_PTHREAD -DENABLE_PTHREAD_ATTR
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dcc ${PREFIX}/bin

.include <bsd.port.mk>
