# New ports collection Makefile for: rxvt
# Date created:         Nov 16 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	rxvt
PORTVERSION=	2.7.3
PORTREVISION=	1
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://ftp.rxvt.org/pub/rxvt/ \
		ftp://mason.primenet.com.au/pub/rxvt/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/rxvt/ \
		ftp://ftp.fu-berlin.de/unix/X11/terms/rxvt/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= X11/terms
DISTNAME=	rxvt-${PORTVERSION}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	rxvt-2.7.3.patch1.gz
PATCH_DIST_STRIP+=	-p1

MAINTAINER=	frankch@waru.life.nthu.edu.tw

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
CONFIGURE_ARGS= --enable-xpm-background --enable-transparency \
		--enable-menubar --enable-graphics --enable-xim \
		--enable-languages --with-encoding=big5

MAN1=		crxvt.1

.include <bsd.port.mk>
