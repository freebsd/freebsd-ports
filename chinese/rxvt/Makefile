# New ports collection Makefile for: rxvt
# Version required:     2.4.4
# Date created:         Nov 16 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $Id: Makefile,v 1.3 1997/12/16 19:26:52 vanilla Exp $
#

DISTNAME=       rxvt-2.4.4
PKGNAME=        zh-rxvt-2.4.4
CATEGORIES=     chinese x11
MASTER_SITES=   ftp://ftp.math.fu-berlin.de/pub/rxvt/devel/

MAINTAINER=     frankch@waru.life.nthu.edu.tw

RUN_DEPENDS=	${X11BASE}/bin/xcin:${PORTSDIR}/chinese/xcin

USE_X11=        yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --enable-big5=yes --enable-xcin=yes
MAN1=           crxvt2.1

.include <bsd.port.mk>
