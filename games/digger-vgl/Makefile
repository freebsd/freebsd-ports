# New ports collection makefile for:	Digger
# Date created:				14 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	digger
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.digger.org/
DISTNAME=	${PORTNAME}-${DIGREL}

MAINTAINER=	sobomax@FreeBSD.org

.if defined(WITH_SOUND)
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12
MAKE_ENV=	SOUND=yes \
		SDL_CONFIG=${SDL_CONFIG}
.endif

ONLY_FOR_ARCHS=	i386	# Alphas don't have libvgl yet...

DIGREL=		20000407
WRKSRC=		${WRKDIR}/${PORTNAME}-${DIGREL}
MAKEFILE=	Makefile.fbsd

.if !defined(WITH_SOUND)
post-extract:
	@${ECHO_MSG}
	@${ECHO_MSG} "Please use \"make -DWITH_SOUND\" if you want to build the game with sound support."
	@${ECHO_MSG}
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/digger ${PREFIX}/bin
	@${MKDIR} /var/games/digger
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/digger
	@${INSTALL_MAN} ${WRKSRC}/digger.txt ${PREFIX}/share/doc/digger
.endif

.if defined(WITH_SOUND)
post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "Use \"digger /A\" command to run Digger with sound enabled."
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
