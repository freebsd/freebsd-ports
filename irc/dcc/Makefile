# New ports collection makefile for:	dcc
# Date Created:		6 May 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dcc
PORTVERSION=	2.5.6
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://his.luky.org/ftp/mirrors/irchat-pj/2.5/
DISTNAME=	irchat-pj-${PORTVERSION}p

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	irchat-pj-${PORTVERSION}pl2.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	DCC support program for irchat-pj

USE_BZIP2=	yes
PLIST_FILES=	bin/dcc
ALL_TARGET=	dcc
LDFLAGS=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS} -DUSE_PTHREAD -DENABLE_PTHREAD_ATTR
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dcc ${PREFIX}/bin

.include <bsd.port.mk>
