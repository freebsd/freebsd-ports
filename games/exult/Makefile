# New ports collection makefile for:	exult
# Date created:		18 February 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=		exult
PORTVERSION=		1.00
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tiamat@telegraph.spb.ru

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

ONLY_FOR_ARCHS=	i386

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib \
		--disable-tools \
		--disable-sdltest
# SDL cannot find X11 includes in normal way
CONFIGURE_ENV=	CPPFLAGS=-I${X11BASE}/include \
		SDL_CONFIG="${SDL_CONFIG}"

MAN6=		exult.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exult ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/exult.flx ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/exult_bg.flx ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/exult_si.flx ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/midisfx.flx ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/docs/exult.6 ${PREFIX}/man/man6
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${ECHO} "******************************************************************************"
	@${ECHO} "* Original Ultima VII data is required to run Exult"
	@${ECHO} "* Please, read ${DOCSDIR}/README for additional information"
	@${ECHO} "******************************************************************************"

.include <bsd.port.mk>
