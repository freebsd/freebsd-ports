# New ports collection makefile for:    xeyes+
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xeyes+
PORTVERSION=	2.01
CATEGORIES=	games
MASTER_SITES=	http://yindy1.aist-nara.ac.jp/~tetu-s/sofken/software/
DISTNAME=	xeyes+${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Horrible eyes looking at your mouse cursor

PLIST_FILES=	bin/xeyes+
USE_IMAKE=	yes
USE_XPM=	yes

post-install:
	@${CHMOD} 755 ${PREFIX}/bin/xeyes+
	@${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/bin/xeyes+

.include <bsd.port.mk>
