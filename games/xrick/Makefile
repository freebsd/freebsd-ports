# New ports collection makefile for:   xrick
# Date created:        15 March 2002
# Whom:                David Siebörger <drs@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	xrick
PORTVERSION=	010808
CATEGORIES=	games
MASTER_SITES=	http://www.bigorno.net/xrick/
EXTRACT_SUFX=	.tgz

MAINTAINER=	drs@rucus.ru.ac.za

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12

WRKSRC=		${WRKDIR}/xrick
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config
USE_GMAKE=	yes

MAN6=		xrick.6
MANCOMPRESSED=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrick ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xrick.6.gz ${PREFIX}/man/man6/xrick.6.gz

.include <bsd.port.mk>
