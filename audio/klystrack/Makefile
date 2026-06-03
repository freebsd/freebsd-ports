PORTNAME=	klystrack
PORTVERSION=	1.7.8
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tracker for making C64/NES/Amiga-style chiptunes
WWW=		https://github.com/z-erica/klystrack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		compiler:c11 desktop-file-utils localbase:ldconfig meson \
		pkgconfig sdl
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	z-erica
GH_TUPLE=	z-erica:klystron:09cb52c:klystron/klystron
USE_SDL=	gfx2 image2 mixer2 sdl2 ttf2

LDFLAGS+=	-lm

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MV} ${STAGEDIR}${DATADIR}/examples ${STAGEDIR}${EXAMPLESDIR}
	@${RMDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
