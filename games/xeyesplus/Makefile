# New ports collection makefile for:    xeyes+
# Version required:     2.01
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/10/10 05:12:00 max Exp $
#

DISTNAME=		xeyes+2.01
PKGNAME=		xeyes+-2.01
CATEGORIES+=		games

MASTER_SITES=		ftp://ftp.eos.hokudai.ac.jp/pub/X/contrib/misc/

MAINTAINER=		nakai@mlab.t.u-tokyo.ac.jp

LIB_DEPENDS=		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

post-install:
	@chmod 755 ${PREFIX}/bin/xeyes+
	@chown bin.bin ${PREFIX}/bin/xeyes+

.include <bsd.port.mk>
