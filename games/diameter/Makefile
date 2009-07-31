# New ports collection makefile for:	diameter
# Date created:		15 Jun 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	diameter
PORTVERSION=	0.4.0.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	gamediameter

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arcade-style game with elements of economy and adventure

BUILD_DEPENDS=	guichan>=0.8.1:${PORTSDIR}/devel/guichan
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		gl
USE_SDL=	sdl mixer image
USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/gamediameter

CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags` -I${LOCALBASE}/include" \
		LDFLAGS="`${SDL_CONFIG} --libs` -L${LOCALBASE}/lib"

DATADIR=	${PREFIX}/share/gamediameter

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|; /^CFLAGS=.*march/ d; \
		/PKG_CONFIG/ s|libpng|libpng12|' ${WRKSRC}/configure

.include <bsd.port.mk>
