# New ports collection Makefile for: rxvt
# Version required:     2.4.11
# Date created:         Nov 16 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $Id: Makefile,v 1.7 1998/10/10 01:04:31 vanilla Exp $
#

DISTNAME=	rxvt-2.4.11
PKGNAME=	zh-rxvt-2.4.11
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://mason.primenet.com.au/pub/rxvt/ \
		ftp://ftp.math.fu-berlin.de/pub/rxvt/

MAINTAINER=	frankch@waru.life.nthu.edu.tw

RUN_DEPENDS=	${X11BASE}/bin/xcin:${PORTSDIR}/chinese/xcin

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-big5=yes --enable-xcin=yes
MAN1=		crxvt2.1

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
