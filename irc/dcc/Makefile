# Created by: Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
# $FreeBSD$

PORTNAME=	dcc
PORTVERSION=	2.5.6
PORTREVISION=	1
CATEGORIES=	irc
#MASTER_SITES=	http://gouketsu.net/irchat-pj/src/2.5/
MASTER_SITES=	http://ftp.dti.ad.jp/pub/unix/net/irc/irchat-pj/2.5/
DISTNAME=	irchat-pj-${PORTVERSION}p

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	irchat-pj-${PORTVERSION}pl2.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DCC support program for irchat-pj

LICENSE=	GPLv2 # (or later)

USE_BZIP2=	yes
ALL_TARGET=	dcc

CFLAGS+=	-DUSE_PTHREAD -DENABLE_PTHREAD_ATTR
LDFLAGS+=	-pthread

PLIST_FILES=	bin/dcc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dcc ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
