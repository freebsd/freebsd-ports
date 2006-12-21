# New ports collection makefile for:	diameter
# Date created:		15 Jun 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	diameter
DISTVERSION=	0.3.5-r1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gamediameter
DISTNAME=	${PORTNAME}-${DISTVERSION}src

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Arcade-style game with elements of economy and adventure

BUILD_DEPENDS=	guichan>=0.5.0:${PORTSDIR}/devel/guichan
RUN_DEPENDS=	guichan>=0.5.0:${PORTSDIR}/devel/guichan

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	sdl mixer image
USE_GCC=	3.4+

CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags` -I${X11BASE}/include" \
		LDFLAGS="`${SDL_CONFIG} --libs` -L${X11BASE}/lib"

DATADIR=	${PREFIX}/share/gamediameter

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not build on FreeBSD 4.x
.endif

post-patch:
	@${REINPLACE_CMD} -e '/PKG_CONFIG/ s|libpng|libpng12|' \
		-e 's|sdl-config|$$SDL_CONFIG|' \
		-e '/LIBS/ s|-lSDL |`$$SDL_CONFIG --libs` |' \
		-e '/^CFLAGS=.*march/ d' \
		-e '/PKG_CHECK_MODULES/ s|^|#|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
