# New ports collection makefile for:	toppler
# Date created:				18 Jan 2002
# Whom:					Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	toppler
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	toppler

MAINTAINER=	dom@happygiraffe.net
COMMENT=	A game where you have to climb the tower and avoid the monsters

USE_SDL=	mixer sdl
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes

MAN6=		toppler.6

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} \( -name "*.[ch]" -or -name "*.cc" \) | \
		${XARGS} ${PERL} -pi -e 's|"SDL/SDL|"SDL|g ; s|<SDL/SDL|<SDL|g'

post-install:
	@cd ${WRKSRC} && ${MAKE} global_highscore

.include <bsd.port.mk>
