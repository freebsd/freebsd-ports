# New ports collection makefile for:    xeyes+
# Version required:     2.01
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.5 1997/04/02 01:51:11 fenner Exp $
#

DISTNAME=		xeyes+2.01
PKGNAME=		xeyes+-2.01
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.eos.hokudai.ac.jp/pub/X11/contrib/misc/

MAINTAINER=		nakai@mlab.t.u-tokyo.ac.jp

LIB_DEPENDS=		Xpm.5:${PORTSDIR}/graphics/xpm

USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

post-install:
	@chmod 755 ${PREFIX}/bin/xeyes+
	@/usr/sbin/chown ${BINOWN}.${BINGRP} ${PREFIX}/bin/xeyes+

.include <bsd.port.mk>
