# New ports collection Makefile for: rxvt
# Version required:     2.6.PRE3
# Date created:         Nov 16 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $Id: Makefile,v 1.11 1999/03/19 22:17:49 asami Exp $
#

DISTNAME=	rxvt-2.6.PRE3
PKGNAME=	zh-rxvt-2.6.p3
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://mason.primenet.com.au/pub/rxvt/ \
		ftp://ftp.rxvt.org/pub/rxvt/devel/

MAINTAINER=	frankch@waru.life.nthu.edu.tw

BUILD_DEPENDS=	yodl2man:${PORTSDIR}/textproc/yodl

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-big5=yes --enable-xim=yes
MAN1=		crxvt.1

.include <bsd.port.mk>
