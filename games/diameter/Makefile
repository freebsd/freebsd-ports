# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	diameter
PORTVERSION=	0.4.0.3
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/game${PORTNAME}/game${PORTNAME}/${PORTNAME}-0.4.0

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arcade-style game with elements of economy and adventure

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libguichan.so:${PORTSDIR}/devel/guichan

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GL=		gl
USE_SDL=	sdl mixer image
USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/gamediameter

CPPFLAGS+=	`${SDL_CONFIG} --cflags` -I${LOCALBASE}/include
LDFLAGS+=	`${SDL_CONFIG} --libs` -L${LOCALBASE}/lib

DATADIR=	${PREFIX}/share/gamediameter

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|; /^CFLAGS=.*march/ d; \
		/PKG_CONFIG/ s|libpng|libpng15|' ${WRKSRC}/configure

.include <bsd.port.mk>
