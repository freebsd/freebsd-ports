# New ports collection makefile for:	xscrabble
# Date created:		27 July 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xscrabble
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.belgarath.demon.co.uk/programs/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mph
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=		yes
USE_XPM=		yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/XScrabble.ad

.include <bsd.port.mk>
