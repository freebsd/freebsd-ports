# New ports collection Makefile for: rxvt
# Version required:     2.6.PRE2
# Date created:         Nov 16 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $Id: Makefile,v 1.9 1999/01/17 07:34:26 vanilla Exp $
#

DISTNAME=	rxvt-2.6.PRE2
PKGNAME=	zh-rxvt-2.6.PRE2
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://mason.primenet.com.au/pub/rxvt/ \
		ftp://ftp.math.fu-berlin.de/pub/rxvt/

MAINTAINER=	frankch@waru.life.nthu.edu.tw

BUILD_DEPENDS=	yodl2man:${PORTSDIR}/textproc/yodl

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-big5=yes --enable-xim=yes
MAN1=		crxvt.1

.include <bsd.port.mk>
