# New ports collection makefile for:    tileworld
# Date created:         08. Oct 02
# Whom:                 sec@42.org
#
# $FreeBSD$
#

PORTNAME=	tileworld
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/tworld/
DISTNAME=	tworld-${PORTVERSION}

MAINTAINER=	sec@42.org

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_REINPLACE=	YES
ALL_TARGET=	tworld

MAN6=		tworld.6

post-patch:
	@${REINPLACE_CMD} -e 's|make|$${MAKE}|g; s|cp -i|cp|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|sdl-config|sdl11-config|g' ${WRKSRC}/configure

.include <bsd.port.mk>
