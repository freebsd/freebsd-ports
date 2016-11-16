# Created by: Edwin Groothuis <edwin2mavetju.org>
# $FreeBSD$

PORTNAME=	flatzebra
PORTVERSION=	0.1.6
PORTREVISION=	4
CATEGORIES=	devel games
MASTER_SITES=	http://perso.b2b2c.ca/sarrazip/dev/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic game engine for 2D double-buffering animation

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include

USES=		pathfix pkgconfig libtool
USE_SDL=	sdl mixer image

USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING INSTALL NEWS README TODO THANKS

OPTIONS_DEFINE=	DOCS

post-patch-DOCS-off:
	@${REINPLACE_CMD} 's|^install-data-am: .*|install-data-am: install-pkgconfigDATA|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
