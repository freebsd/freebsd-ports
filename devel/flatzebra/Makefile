PORTNAME=	flatzebra
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	devel games
MASTER_SITES=	http://perso.b2b2c.ca/~sarrazip/dev/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Generic game engine for 2D double-buffering animation
WWW=		http://sarrazip.com

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix pkgconfig sdl
USE_SDL=	sdl2 gfx2 image2 mixer2 ttf2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS NEWS README THANKS

OPTIONS_DEFINE=	DOCS

post-patch-DOCS-off:
	@${REINPLACE_CMD} 's|^install-data-am: .*|install-data-am: install-pkgconfigDATA|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
