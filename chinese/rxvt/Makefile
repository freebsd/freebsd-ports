# New ports collection Makefile for: rxvt
# Version required:     2.6.0
# Date created:         Nov 16 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

DISTNAME=	rxvt-2.6.0
PKGNAME=	zh-rxvt-2.6.0
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://mason.primenet.com.au/pub/rxvt/ \
		ftp://ftp.rxvt.org/pub/rxvt/devel/

MAINTAINER=	frankch@waru.life.nthu.edu.tw

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
MAN1=		crxvt.1

CONFIGURE_ARGS+=--enable-xpm-background --enable-transparency \
		--enable-menubar --enable-graphics --enable-xim \
		--enable-big5 --disable-backspace-key --disable-delete-key

.include <bsd.port.mk>
