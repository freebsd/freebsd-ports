# New ports collection Makefile for: rxvt
# Version required:     2.6.0
# Date created:         Nov 16 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

DISTNAME=	rxvt-2.7.2
PKGNAME=	zh-rxvt-2.7.2
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://ftp.rxvt.org/pub/rxvt/

MAINTAINER=	frankch@waru.life.nthu.edu.tw

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
MAN1=		crxvt.1

CONFIGURE_ARGS+=--enable-xpm-background --enable-transparency \
		--enable-menubar --enable-graphics --enable-xim \
		--enable-languages --with-encoding=big5

.include <bsd.port.mk>
