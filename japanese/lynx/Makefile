# New ports collection makefile for:	ja-lynx
# Version required:     2.8.1
# Date created:         10 August 1998
# Whom:                 Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1998/08/10 16:03:26 kuriyama Exp $
#

DISTNAME=       lynx2-8-1
PKGNAME=        ja-lynx-2.8.1
CATEGORIES=	japanese www
MASTER_SITES=   ftp://sol.slcc.edu/pub/lynx/release2-8-1/

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

NO_LATEST_LINK=	YES
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc"
MAKEFILE=       makefile
INSTALL_TARGET= install install-help
MAN1=		lynx.1

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} ; make install-doc)
	@chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/lynx
.endif
	@chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/lynx_help

.include <bsd.port.mk>
