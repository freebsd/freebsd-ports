# New ports collection makefile for:	xbloody
# Version required:	1.00
# Date created:		10 February 1998
# Whom:			FURUSAWA,Kazuhisa <kazu@jp.freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	xbloody
PKGNAME=	xbloody-1.00
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1994/oct/

MAINTAINER=	kazu@jp.freebsd.org

WRKSRC=		${WRKDIR}
USE_IMAKE=	yes
NO_INSTALL_MANPAGES= yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xbloody
	@${INSTALL_DATA} ${WRKSRC}/README.sjis ${PREFIX}/share/doc/xbloody
.endif

.include <bsd.port.mk>
