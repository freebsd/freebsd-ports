# New ports collection makefile for:	xscrabble
# Version required:	1.0
# Date created:		27 July 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	xscrabble
PKGNAME=	xscrabble-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.freebsd.org/~mph/distfiles/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	@/usr/bin/perl -pi.bak -e "s|\@XSCRABBLEDIR\@|${PREFIX}/lib/X11/xscrabble|;" \
		${WRKSRC}/Imakefile
	@/usr/bin/perl -pi.bak -e "s|\@XSCRABBLEDIR\@|${PREFIX}/lib/X11/xscrabble|;" \
		${WRKSRC}/XScrabble.ad

.include <bsd.port.mk>
