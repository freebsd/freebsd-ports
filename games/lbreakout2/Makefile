# New ports collection makefile for:	lbreakout2
# Date created:		12 June 2002
# Whom:			verm@drunkmonk.net
#
# $FreeBSD$
#

PORTNAME=	lbreakout2
PORTVERSION=	2.2.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lgames

MAINTAINER=	verm@drunkmonk.net

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12 \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		png.5:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-highscore-path=/var/games \
		--with-doc-path=${PREFIX}/share/doc
CONFIGURE_ENV=	SDL_CONFIG=${LOCALBASE}/bin/sdl11-config \
		LDFLAGS=-L${LOCALBASE}/lib
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/games\/lbreakout2/lbreakout2/g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/if .*lbreakout2.hscr/if false/' \
		${WRKSRC}/src/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's/ docs / /g' ${WRKSRC}/src/Makefile.in
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/empty.hscr ${DATADIR}
	@${CHOWN} root:games ${PREFIX}/bin/lbreakout2
	@${CHMOD} g+s ${PREFIX}/bin/lbreakout2
	@${SETENV} "PKG_PREFIX=${PREFIX}" \
		${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
