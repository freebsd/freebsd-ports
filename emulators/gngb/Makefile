# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gngb
PORTVERSION=	20060309
PORTREVISION=	8
CATEGORIES=	emulators
MASTER_SITES=	http://m.peponas.free.fr/gngb/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GameBoy(tm) emulator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake localbase
USE_CSTD=	gnu89
USE_SDL=	sdl
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gngb \
		man/man1/gngb.1.gz

OPTIONS_DEFINE=	OPENGL

OPENGL_USE=		GL=gl
OPENGL_CONFIGURE_ENABLE=gl

post-patch:
	@${REINPLACE_CMD} -e \
		's|"$$SDL_CONFIG" = yes|-n "$$SDL_CONFIG"|g ; \
		 s|sdl-config |$$SDL_CONFIG |g ; \
		 s|$$OPT||g' ${WRKSRC}/configure

.include <bsd.port.mk>
