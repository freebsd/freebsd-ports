# New ports collection makefile for:	ja-lynx-current
# Version required:     2.8.2dev.X
# Date created:         10 August 1998
# Whom:                 Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id: Makefile,v 1.4 1998/11/14 16:57:42 kuriyama Exp $
#

DISTNAME=	lynx2.8.2dev.2
PKGNAME=	ja-lynx-2.8.2.2
CATEGORIES=	japanese www
MASTER_SITES=	ftp://sol.slcc.edu/pub/lynx/current/

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

NO_LATEST_LINK=	YES
WRKSRC=		${WRKDIR}/lynx2-8-2
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-screen=ncurses --with-zlib \
		--libdir="${PREFIX}/etc" --disable-nls --enable-default-colors
MAKEFILE=	makefile
INSTALL_TARGET=	install install-help
MAN1=		lynx.1

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} ; make install-doc)
	@chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/lynx
.endif
	@chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/lynx_help

.include <bsd.port.mk>
