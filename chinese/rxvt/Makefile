# New ports collection Makefile for: rxvt
# Date created:         Nov 16 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	rxvt
PORTVERSION=	2.7.5
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://ftp.rxvt.org/pub/rxvt/ \
		ftp://mason.primenet.com.au/pub/rxvt/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/rxvt/ \
		ftp://ftp.fu-berlin.de/unix/X11/terms/rxvt/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/terms
DISTNAME=	rxvt-${PORTVERSION}

MAINTAINER=	keichii@freebsd.org

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_BZIP2=	yes
CONFIGURE_ARGS=	--enable-xpm-background --enable-transparency \
		--enable-menubar --enable-graphics --enable-xim \
		--disable-backspace-key --disable-delete-key \
		--enable-rxvt-scroll --enable-next-scroll \
		--enable-languages --with-encoding=big5 \
		--enable-utmp --enable-wtmp --enable-shared

MAN1=		crxvt.1

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/crxvt

.include <bsd.port.mk>
