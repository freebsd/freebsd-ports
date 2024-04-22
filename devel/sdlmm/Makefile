PORTNAME=	sdlmm
PORTVERSION=	0.1.8
PORTREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/SDLmm/${PORTVERSION}
DISTNAME=	SDLmm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ Wrapper for the SDL (Simple DirectMedia Layer)
WWW=		https://sdlmm.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool sdl
USE_SDL=	sdl
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libSDLmm.so

.include <bsd.port.mk>
