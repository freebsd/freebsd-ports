# New ports collection makefile for:	pipewalker
# Date created:		11 Aug 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pipewalker
PORTVERSION=	0.7.2
CATEGORIES=	games
MASTER_SITES=	SF
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A clone of the NetWalk game

GNU_CONFIGURE=	yes
USE_SDL=	sdl
USE_GL=		gl glu
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CPPFLAGS="-I${LOCALBASE}/include"

PORTDOCS=	*

post-patch:
	@${CHMOD} a+x ${WRKSRC}/install-sh
	@${REINPLACE_CMD} -e 's|(datadir)/games|(datadir)|' \
		${WRKSRC}/data/Makefile.in ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/^install-data-am/ s|install-pkgmenudataDATA||' \
		${WRKSRC}/extra/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am/ s|install-pkgdocdataDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
