# New ports collection makefile for:   xshisen
# Version required:           1.36
# Date created:               9 Oct 1996
# Whom:                 Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.10 1998/09/17 00:32:39 asami Exp $
#

DISTNAME=	xshisen-1.36
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.win.or.jp/pub/doc-sources/fj.sources/1996/feb/

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

# runs fine on ssh connection
#IS_INTERACTIVE=	YES	# Has to create an app-defaults file
USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES
#CONFIGURE_ARGS=--enable-japanese=euc	#Japanese char set euc, jis sjis
MAN6=		xshisen.6

INSTALL_TARGET=	install install.man

post-install:
	@ strip ${PREFIX}/bin/xshisen
	@ /bin/chmod 755 ${PREFIX}/bin/xshisen
	@ /usr/sbin/chown ${BINOWN}.${BINGRP} ${PREFIX}/bin/xshisen

.include <bsd.port.mk>
