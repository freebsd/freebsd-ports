# New ports collection makefile for:	xemeraldia
# Version required:	0.31
# Date created:		22 Mar 1995
# Whom:			asami
#
# $FreeBSD$
#

DISTNAME=	xemeraldia-0.3
PKGNAME=	xemeraldia-0.31
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1995/mar/

PATCH_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1995/apr/
PATCHFILES=	xemeraldia-0.3to0.31.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/xemeraldia
	@${TOUCH} ${PREFIX}/lib/X11/xemeraldia/xemeraldia.scores
	@${CHMOD} 666 ${PREFIX}/lib/X11/xemeraldia/xemeraldia.scores

.include <bsd.port.mk>
