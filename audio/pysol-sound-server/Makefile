# New ports collection makefile for:	pysol-sound-server
# Version required:	2.10
# Date created:		7 January 2000
# Whom:			Maxim Sobolev
#
# $FreeBSD$
#

DISTNAME=	pysol-sound-server-2.10
CATEGORIES=	audio games
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/download/pysol/pysol-sound-server/

MAINTAINER=	sobomax@altavista.net

LIB_DEPENDS=	SDL-1.0.2:${PORTSDIR}/devel/sdl \
		smpeg-0.3.0:${PORTSDIR}/graphics/smpeg

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X11BASE="${X11BASE}"

.include <bsd.port.mk>
