# New ports collection makefile for:    xeyes+
# Version required:     2.01
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	xeyes+2.01
PKGNAME=	xeyes+-2.01
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.eos.hokudai.ac.jp/pub/X11/contrib/misc/

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	@${CHMOD} 755 ${PREFIX}/bin/xeyes+
	@${CHOWN} ${BINOWN}.${BINGRP} ${PREFIX}/bin/xeyes+

.include <bsd.port.mk>
