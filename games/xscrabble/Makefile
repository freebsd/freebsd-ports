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
MASTER_SITES=	http://www.belgarath.demon.co.uk/programs/ \
		http://people.FreeBSD.org/~mph/distfiles/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/XScrabble.ad

.include <bsd.port.mk>
