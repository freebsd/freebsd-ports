# New ports collection makefile for:	xscrabble
# Version required:	1.0
# Date created:		27 July 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $Id: Makefile,v 1.1.1.1 1997/08/04 11:45:49 tg Exp $
#

DISTNAME=	xscrabble
PKGNAME=	xscrabble-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.belgarath.demon.co.uk/programs/

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	Xpm.5:${PORTSDIR}/graphics/xpm

USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	@/usr/bin/perl -pi.bak -e "s|@XSCRABBLEDIR@|${PREFIX}/lib/X11/xscrabble|;" \
		${WRKSRC}/Imakefile
	@/usr/bin/perl -pi.bak -e "s|@XSCRABBLEDIR@|${PREFIX}/lib/X11/xscrabble|;" \
		${WRKSRC}/XScrabble.ad

.include <bsd.port.mk>
