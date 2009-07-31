# New ports collection makefile for:	dangen
# Date created:		25 Aug 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	dangen
PORTVERSION=	0.3
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.interq.or.jp/libra/oohara/dangen/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Shoot'em up game where accurate shooting matters

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl image

PORTDOCS=	README

MAN6=		dangen.6

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile.in \
		${WRKSRC}/libtenm/Makefile.in ${WRKSRC}/spqr/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(datadir)/games/|$$(datadir)/|' ${WRKSRC}/spqr/image/Makefile.in
	@${REINPLACE_CMD} -e 's|/games||' ${WRKSRC}/util.c

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
