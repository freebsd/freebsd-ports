# New ports collection makefile for:   xshisen
# Version required:           1.35
# Date created:               9 Oct 1996
# Whom:                 Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/11/03 21:11:08 jfitz Exp $
#

DISTNAME=       xshisen-1.35
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.iis.u-tokyo.ac.jp/pub1/X/contrib/games/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

IS_INTERACTIVE=	YES	# Has to create an app-defaults file
USE_X11=	YES
GNU_CONFIGURE=	YES
#CONFIGURE_ARGS=--enable-japanese=euc	#Japanese char set euc, jis sjis

post-install:
	@ strip ${PREFIX}/bin/xshisen
	@ /bin/chmod 755 ${PREFIX}/bin/xshisen
	@ /usr/sbin/chown bin.bin ${PREFIX}/bin/xshisen
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man6/xshisen.6
	gzip -9nf ${PREFIX}/man/ja_JP.JIS7/man6/xshisen.6
.endif

.include <bsd.port.mk>
