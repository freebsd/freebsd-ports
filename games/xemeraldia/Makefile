# New ports collection makefile for:	xemeraldia
# Date created:		22 Mar 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	xemeraldia
PORTVERSION=	0.31
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.eos.hokudai.ac.jp/pub/Linux/JG/JG-0.9.1/other-sources/jp/
DISTNAME=	xemeraldia-0.3

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	xemeraldia-0.3to0.31.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A game of breaking blocks

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	@${CHOWN} root:games ${PREFIX}/bin/xemeraldia
	@${CHMOD} 2755 ${PREFIX}/bin/xemeraldia
	@${MKDIR} ${PREFIX}/lib/X11/xemeraldia
	@${TOUCH} ${PREFIX}/lib/X11/xemeraldia/xemeraldia.scores
	@${CHOWN} root:games ${PREFIX}/lib/X11/xemeraldia/xemeraldia.scores
	@${CHMOD} 664 ${PREFIX}/lib/X11/xemeraldia/xemeraldia.scores

.include <bsd.port.mk>
